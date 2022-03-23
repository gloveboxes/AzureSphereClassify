#pragma once

#include "app_exit_codes.h"
#include "hw/azure_sphere_learning_path.h"

#include "dx_azure_iot.h"
#include "dx_config.h"
#include "dx_intercore.h"
#include "dx_terminate.h"
#include "dx_utilities.h"
#include "dx_version.h"
#include "intercore_contract.h"

#include <applibs/applications.h>
#include <applibs/log.h>

// https://docs.microsoft.com/en-us/azure/iot-pnp/overview-iot-plug-and-play
#define IOT_PLUG_AND_PLAY_MODEL_ID "dtmi:AzureSphere:PredictiveMaintenance;1"
#define NETWORK_INTERFACE          "wlan0"
#define SAMPLE_VERSION_NUMBER      "1.0"

#define CORE_ENVIRONMENT_COMPONENT_ID "6583cf17-d321-4d72-8283-0b7c5b56442b"

#define Log_Debug(f_, ...) dx_Log_Debug((f_), ##__VA_ARGS__)
#define JSON_MESSAGE_BYTES 256

// Variables
static char Log_Debug_Time_buffer[128];
static char msgBuffer[JSON_MESSAGE_BYTES] = {0};
static DX_USER_CONFIG dx_config;
static bool azure_connected;
INTERCORE_BLOCK intercore_block;

// Forward declarations
static void intercore_environment_receive_msg_handler(void *data_block, ssize_t message_length);

// Bindings

// clang-format off

static DX_DEVICE_TWIN_BINDING dt_hvac_sw_version = {.propertyName = "SoftwareVersion", .twinType = DX_DEVICE_TWIN_STRING};
static DX_DEVICE_TWIN_BINDING dt_utc_startup = {.propertyName = "StartupUtc", .twinType = DX_DEVICE_TWIN_STRING};
static DX_DEVICE_TWIN_BINDING dt_prediction = {.propertyName = "FaultPrediction", .twinType = DX_DEVICE_TWIN_STRING};
static DX_GPIO_BINDING gpio_network_led = {.pin = NETWORK_CONNECTED_LED, .name = "network_led", .direction = DX_OUTPUT, .initialState = GPIO_Value_Low, .invertPin = true};

DX_INTERCORE_BINDING intercore_environment_ctx = {.sockFd = -1,
	.nonblocking_io                                       = true,
	.rtAppComponentId                                     = CORE_ENVIRONMENT_COMPONENT_ID,
	.interCoreCallback                                    = intercore_environment_receive_msg_handler,
	.intercore_recv_block                                 = &intercore_block,
	.intercore_recv_block_length                          = sizeof(intercore_block)};

// clang-format on

// All bindings referenced are initialised in the InitPeripheralsAndHandlers function
DX_DEVICE_TWIN_BINDING *device_twin_bindings[]         = {&dt_utc_startup, &dt_hvac_sw_version, &dt_prediction};
DX_DIRECT_METHOD_BINDING *direct_method_binding_sets[] = {};
DX_GPIO_BINDING *gpio_binding_sets[]                   = {&gpio_network_led};
DX_TIMER_BINDING *timer_binding_sets[]                 = {};
