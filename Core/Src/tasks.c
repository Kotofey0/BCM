/*
 * tasks.c
 *
 *  Created on: 5 мая 2023 г.
 *      Author: fedor.medin
 */
#include "tasks.h"
#include "can.h"
#include "globals.h"


uint64_t globalTimer_ms = 0;

void task_1ms(void){
	//global timer update, ADC, RPM meter, etc
}

void task_10ms(void){
	//send frames: ignition, RPM, Speed, steering wheel
	canSendIgnitionFrame();
	canSendRPM();
	canSendSpeed();
	canSendSteeringWheel();

}

void task_200ms(void){
	//send frames: Lights, Indicator, ABS, Coolant temp, ABS counter, Airbag counter, Fuel
	canSendLights();
	canSendIndicator(); // internal 600ms timer
	canSendAbs();
	canSendEngineTemp();
	canSendAbsCounter();
	canSendAirbagCounter();
	canSendFuel();
}

void task_500ms(void){
	//send frames:
	canSendHandbrake();
}

void task_1000ms(void){
	canSendTime();
	if(++s_time_sec == 60){
		s_time_sec = 0;
		if(++s_time_minute == 60){
			s_time_minute = 0;
			if(++s_time_hour == 24){
				s_time_hour = 0;
			}
		}
	}
}
