/* Copyright (c) Microsoft Corporation. All rights reserved.
   Licensed under the MIT License. */

// This file defines the mapping from the MT3620 reference development board (RDB) to the
// 'sample hardware' abstraction used by the samples at https://github.com/Azure/azure-sphere-samples.
// Some peripherals are on-board on the RDB, while other peripherals must be attached externally if needed.
// https://docs.microsoft.com/en-us/azure-sphere/app-development/manage-hardware-dependencies
// to enable apps to work across multiple hardware variants.

// This file is autogenerated from ../../azure_sphere_learning_path.json.  Do not edit it directly.

#pragma once
#include "avnet_mt3620_sk.h"

// Button A
#define BUTTON_A AVNET_MT3620_SK_USER_BUTTON_A

// Button B
#define BUTTON_B AVNET_MT3620_SK_USER_BUTTON_B

// Alert LED
#define ALERT_LED AVNET_MT3620_SK_USER_LED_RED

// LED 1
#define LED1 AVNET_MT3620_SK_USER_LED_BLUE

// LED 2
#define LED2 AVNET_MT3620_SK_APP_STATUS_LED_YELLOW

// AVNET: Network Connected
#define NETWORK_CONNECTED_LED AVNET_MT3620_SK_WLAN_STATUS_LED_YELLOW

// Click Relay
#define RELAY AVNET_MT3620_SK_GPIO0

// AVNET Start Kit Definition
#define I2cMaster2 AVNET_MT3620_SK_ISU2_I2C

// AVNET Start Kit Definition
#define Adc0 AVNET_MT3620_SK_ADC_CONTROLLER0

// Red LED
#define LED_RED AVNET_MT3620_SK_USER_LED_RED

// Green LED
#define LED_GREEN AVNET_MT3620_SK_USER_LED_GREEN

// Blue LED
#define LED_BLUE AVNET_MT3620_SK_USER_LED_BLUE

// MT3620 SK: Connect CLICK1: RX (RX), TX (TX), CTS (CS), and RTS (SDI).
#define UART_CLICK1 AVNET_MT3620_SK_ISU0_UART

// MT3620 SK: Connect CLICK2: RX (RX), TX (TX), CTS (CS), and RTS (SDI).
#define UART_CLICK2 AVNET_MT3620_SK_ISU0_UART

