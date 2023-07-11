/*
 * globals.h
 *
 *  Created on: 5 мая 2023 г.
 *      Author: fedor.medin
 */

#ifndef INC_GLOBALS_H_
#define INC_GLOBALS_H_

#include "stm32f1xx_hal.h"

extern uint8_t s_ignition;
extern uint8_t s_light_parking;
extern uint8_t s_light_dip;
extern uint8_t s_light_main;
extern uint8_t s_light_fog;
extern uint8_t s_handbrake;
extern uint8_t s_light_indicator;
extern uint16_t s_rpm;
extern uint16_t s_speed;
extern uint16_t s_fuel;
extern uint8_t s_engine_temp;

extern uint64_t globalTimer_ms;

extern uint8_t s_time_hour;
extern uint8_t s_time_minute;
extern uint8_t s_time_sec;
extern uint8_t s_time_day;
extern uint8_t s_time_month;
extern uint16_t s_time_year;

extern uint32_t TxMailbox;



#endif /* INC_GLOBALS_H_ */
