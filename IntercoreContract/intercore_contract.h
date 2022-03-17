#pragma once

typedef enum __attribute__((packed))
{
	IC_UNKNOWN,
	IC_PREDICTION

} INTERCORE_CMD;

typedef struct __attribute__((packed, aligned(4)))
{
	INTERCORE_CMD cmd;
	float temperature;
	char PREDICTION[20];

} INTERCORE_BLOCK;
