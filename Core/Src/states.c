/*
 * states.c
 *
 *  Created on: 5 мая 2023 г.
 *      Author: fedor.medin
 */


#include "globals.h"
#include "e87types.h"

uint8_t s_ignition = 0;

uint8_t s_light_parking = 0;
uint8_t s_light_dip = 0;
uint8_t s_light_main = 0;
uint8_t s_light_fog = 0;
uint8_t s_handbrake = 0;
uint8_t s_light_indicator = I_OFF;
uint16_t s_speed = 0;
uint16_t s_rpm = 0;
uint16_t s_fuel = 0; // 1000 - max;
uint8_t s_engine_temp = 91;

uint8_t s_time_hour = 13;
uint8_t s_time_minute = 37;
uint8_t s_time_sec = 0;
uint8_t s_time_day = 1;
uint8_t s_time_month = 1;
uint16_t s_time_year = 2019;
