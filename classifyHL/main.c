/* Copyright (c) Microsoft Corporation. All rights reserved.
 * Licensed under the MIT License.
 *
 * This example is built on the Azure Sphere DevX library.
 *   1. DevX is an Open Source community-maintained implementation of the Azure Sphere SDK samples.
 *   2. DevX is a modular library that simplifies common development scenarios.
 *        - You can focus on your solution, not the plumbing.
 *   3. DevX documentation is maintained at https://github.com/gloveboxes/AzureSphereDevX/wiki
 *	 4. The DevX library is not a substitute for understanding the Azure Sphere SDK Samples.
 *          - https://github.com/Azure/azure-sphere-samples
 *
 * DEVELOPER BOARD SELECTION
 *
 * The following developer boards are supported.
 *
 *	 1. AVNET Azure Sphere Starter Kit.
 *   2. AVNET Azure Sphere Starter Kit Revision 2.
 *
 * ENABLE YOUR DEVELOPER BOARD
 *
 * Each Azure Sphere developer board manufacturer maps pins differently. You need to select the
 *    configuration that matches your board.
 *
 * Follow these steps:
 *
 *	 1. Open CMakeLists.txt.
 *	 2. Uncomment the set command that matches your developer board.
 *	 3. Click File, then Save to auto-generate the CMake Cache.
 *
 ************************************************************************************************/

#include "main.h"

/// <summary>
/// Callback handler for Inter-Core Messaging
/// </summary>
static void intercore_environment_receive_msg_handler(void *data_block, ssize_t message_length)
{
	INTERCORE_BLOCK *ic_data = (INTERCORE_BLOCK *)data_block;

	switch (ic_data->cmd)
	{
		case IC_PREDICTION:

			if (dx_jsonSerialize(
					msgBuffer, sizeof(msgBuffer), 1, DX_JSON_STRING, "Prediction", ic_data->PREDICTION))
			{
				Log_Debug("%s\n", msgBuffer);

				dx_azurePublish(msgBuffer, strlen(msgBuffer), messageProperties, NELEMS(messageProperties),
					&contentProperties);
			}
			break;
		default:
			break;
	}
}

static void ConnectionStatus(bool connected)
{
	dx_gpioStateSet(&gpio_network_led, connected);
}

static void report_startup(bool connected)
{
	dx_deviceTwinReportValue(&dt_utc_startup, dx_getCurrentUtc(msgBuffer, sizeof(msgBuffer)));
	// Report software version
	snprintf(msgBuffer, sizeof(msgBuffer), "Sample version: %s, DevX version: %s", SAMPLE_VERSION_NUMBER,
		AZURE_SPHERE_DEVX_VERSION);
	dx_deviceTwinReportValue(&dt_hvac_sw_version, msgBuffer);
	// now unregister this callback as we've reported startup time and sw version
	dx_azureUnregisterConnectionChangedNotification(report_startup);
}

/// <summary>
///  Initialize peripherals, device twins, direct methods, timer_binding_sets.
/// </summary>
static void InitPeripheralsAndHandlers(void)
{
	dx_Log_Debug_Init(Log_Debug_Time_buffer, sizeof(Log_Debug_Time_buffer));
	dx_azureConnect(&dx_config, NETWORK_INTERFACE, IOT_PLUG_AND_PLAY_MODEL_ID);
	dx_gpioSetOpen(gpio_binding_sets, NELEMS(gpio_binding_sets));
	dx_timerSetStart(timer_binding_sets, NELEMS(timer_binding_sets));
	dx_deviceTwinSubscribe(device_twin_bindings, NELEMS(device_twin_bindings));

	dx_intercoreConnect(&intercore_environment_ctx);

	dx_azureRegisterConnectionChangedNotification(report_startup);
	dx_azureRegisterConnectionChangedNotification(ConnectionStatus);
}

/// <summary>
///     Close peripherals and handlers.
/// </summary>
static void ClosePeripheralsAndHandlers(void)
{
	dx_timerSetStop(timer_binding_sets, NELEMS(timer_binding_sets));
	dx_deviceTwinUnsubscribe();
	dx_gpioSetClose(gpio_binding_sets, NELEMS(gpio_binding_sets));
	dx_timerEventLoopStop();
}

int main(int argc, char *argv[])
{
	dx_registerTerminationHandler();

	if (!dx_configParseCmdLineArguments(argc, argv, &dx_config))
	{
		return dx_getTerminationExitCode();
	}

	InitPeripheralsAndHandlers();

	// Main loop
	dx_eventLoopRun();

	ClosePeripheralsAndHandlers();
	Log_Debug("Application exiting.\n");
	return dx_getTerminationExitCode();
}