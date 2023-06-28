/*
 * can.c
 *
 *  Created on: 5 мая 2023 г.
 *      Author: fedor.medin
 */

#include "can.h"
#include "globals.h"
#include "main.h"
#include "e87types.h"

extern CAN_HandleTypeDef hcan;

uint32_t TxMailbox = 0;

CAN_TxHeaderTypeDef ignitionKeyOnHeader;
uint8_t ignitionKeyOnData[5] 	= {0x45, 0x42, 0x69, 0x8f, 0xE2};
uint8_t ignitionKeyOffData[5] 	= {0x00, 0x00, 0xC0, 0x0f, 0xE2};
CAN_TxHeaderTypeDef RPMHeader;
uint8_t RPMData[8] 				= {0x5F, 0x59, 0xFF, 0x00, 0x34, 0x0D, 0x80, 0x99};
CAN_TxHeaderTypeDef ignitionStatusHeader;
uint8_t ignitionStatusData[8] 	= {0x40, 0x40, 0x7F, 0x50, 0xFF, 0xFF, 0xFF, 0xFF};
CAN_TxHeaderTypeDef fuelLevelHeader;
uint8_t fuelLevelData[5] 		= {0x00, 0x00, 0x00, 0x00, 0x00};
CAN_TxHeaderTypeDef airbagSeatbeltHeader;
uint8_t airbagSeatbeltData[2] 	= {0xC3, 0xFF};
CAN_TxHeaderTypeDef ABSBrake1Header;
uint8_t ABSBrake1Data[8] 		= {0xF0, 0xFF};
CAN_TxHeaderTypeDef ABSBrake2Header;
uint8_t ABSBrake2Data[8] 		= {0x00, 0xE0, 0xB3, 0xFC, 0xF0, 0x43, 0x00, 0x65};
CAN_TxHeaderTypeDef seatBeltLightOffHeader;
uint8_t seatBeltLightOffData[8] = {0x40, 0x4D, 0x00, 0x28, 0xFF, 0xFF, 0xFF, 0xFF};
CAN_TxHeaderTypeDef seatBeltLightOnHeader;
uint8_t seatBeltLightOnData[8] 	= {0x40, 0x4D, 0x00, 0x29, 0xFF, 0xFF, 0xFF, 0xFF};
CAN_TxHeaderTypeDef speedHeader;
uint8_t speedData[8] 			= {0x13, 0x4D, 0x46, 0x4D, 0x33, 0x4D, 0xD0, 0xFF};
CAN_TxHeaderTypeDef lightsOffHeader;
uint8_t lightsOffData[3] 		= {0x00, 0x00, 0xf7};
CAN_TxHeaderTypeDef steeringWheelHeader;
uint8_t steeringWheelData[7] 	= {0x83, 0xFD, 0xFC, 0x00, 0x00, 0xFF, 0xF1};
CAN_TxHeaderTypeDef indicatorHeader;
uint8_t indicatorData[2] 		= {0x80, 0xF0};
CAN_TxHeaderTypeDef coolantHeader;
uint8_t coolantData[8] 			= {0x8B, 0xFF, 0x63, 0xCD, 0x5D, 0x37, 0xCD, 0xA8};
CAN_TxHeaderTypeDef handbrakeHeader;
uint8_t handbrakeData[2] 		= {0xFE, 0xFF};
CAN_TxHeaderTypeDef dateTimeHeader;
uint8_t dateTimeData[8] 			= {0x0B, 0x10, 0x00, 0x0D, 0x1F, 0xDF, 0x07, 0xF2};

void K_CAN_FramesInit(void){

	 ignitionKeyOnHeader.StdId 		= 0x130;
	  RPMHeader.StdId 				= 0x0AA;
	  ignitionStatusHeader.StdId 	= 0x26E;
	  fuelLevelHeader.StdId 		= 0x349;
	  airbagSeatbeltHeader.StdId 	= 0x0D7;
	  ABSBrake1Header.StdId 		= 0x0C0;
	  ABSBrake2Header.StdId 		= 0x19E;
	  seatBeltLightOffHeader.StdId 	= 0x581;
	  seatBeltLightOnHeader.StdId 	= 0x394;
	  speedHeader.StdId 			= 0x1A6;
	  lightsOffHeader.StdId 		= 0x21A;
	  steeringWheelHeader.StdId 	= 0x0C4;
	  indicatorHeader.StdId 		= 0x1F6;
	  coolantHeader.StdId 			= 0x1D0;
	  handbrakeHeader.StdId 		= 0x34F;
	  dateTimeHeader.StdId 			= 0x39E;

	  dateTimeHeader.RTR =
	  handbrakeHeader.RTR =
	  coolantHeader.RTR =
	  indicatorHeader.RTR =
	  ignitionKeyOnHeader.RTR =
	  RPMHeader.RTR =
	  ignitionStatusHeader.RTR =
	  fuelLevelHeader.RTR =
	  airbagSeatbeltHeader.RTR =
	  ABSBrake1Header.RTR =
	  ABSBrake2Header.RTR =
	  seatBeltLightOffHeader.RTR =
	  seatBeltLightOnHeader.RTR =
	  speedHeader.RTR =
	  steeringWheelHeader.RTR =
	  lightsOffHeader.RTR = CAN_RTR_DATA;

	  dateTimeHeader.IDE =
	  handbrakeHeader.IDE =
	  coolantHeader.IDE =
	  indicatorHeader.IDE =
	  ignitionKeyOnHeader.IDE =
	  RPMHeader.IDE =
	  ignitionStatusHeader.IDE =
	  fuelLevelHeader.IDE =
	  airbagSeatbeltHeader.IDE =
	  ABSBrake1Header.IDE =
	  ABSBrake2Header.IDE =
	  seatBeltLightOffHeader.IDE =
	  seatBeltLightOnHeader.IDE =
	  speedHeader.IDE =
	  steeringWheelHeader.IDE =
	  lightsOffHeader.IDE = CAN_ID_STD;

	  dateTimeHeader.DLC		= 8;
	  handbrakeHeader.DLC 		= 2;
	  coolantHeader.DLC 		= 8;
	  indicatorHeader.DLC 		= 2;
	  ignitionKeyOnHeader.DLC 	= 5;
	  RPMHeader.DLC 			= 8;
	  ignitionStatusHeader.DLC 	= 8;
	  fuelLevelHeader.DLC 		= 5;
	  airbagSeatbeltHeader.DLC 	= 2;
	  ABSBrake1Header.DLC 		= 2;
	  ABSBrake2Header.DLC 		= 8;
	  seatBeltLightOffHeader.DLC= 8;
	  seatBeltLightOnHeader.DLC = 8;
	  speedHeader.DLC 			= 8;
	  lightsOffHeader.DLC 		= 3;
	  steeringWheelHeader.DLC 	= 7;

	  dateTimeHeader.TransmitGlobalTime =
	  handbrakeHeader.TransmitGlobalTime =
	  coolantHeader.TransmitGlobalTime =
	  indicatorHeader.TransmitGlobalTime =
	  ignitionKeyOnHeader.TransmitGlobalTime =
	  RPMHeader.TransmitGlobalTime =
	  ignitionStatusHeader.TransmitGlobalTime =
	  fuelLevelHeader.TransmitGlobalTime =
	  airbagSeatbeltHeader.TransmitGlobalTime =
	  ABSBrake1Header.TransmitGlobalTime =
	  ABSBrake2Header.TransmitGlobalTime =
	  seatBeltLightOffHeader.TransmitGlobalTime =
	  seatBeltLightOnHeader.TransmitGlobalTime =
	  speedHeader.TransmitGlobalTime =
	  steeringWheelHeader.TransmitGlobalTime =
	  lightsOffHeader.TransmitGlobalTime = 0;

}

void sendFrame(const CAN_TxHeaderTypeDef *pHeader, const uint8_t aData[]){
	while(!HAL_CAN_GetTxMailboxesFreeLevel(&hcan));
	HAL_CAN_AddTxMessage(&hcan, pHeader, aData, &TxMailbox);
}

void canSendIgnitionFrame(void){
  if(s_ignition){
    sendFrame(&ignitionKeyOnHeader, ignitionKeyOnData);
    ignitionKeyOnData[4]++;
  }else{
	sendFrame(&ignitionKeyOnHeader, ignitionKeyOffData);
	ignitionKeyOffData[4]++;
  }
}

void canSendRPM(void){
  uint16_t value = s_rpm * 4;

  RPMData[4] = value;
  RPMData[5] = (value >> 8);

  sendFrame(&RPMHeader, RPMData);
}

uint16_t last_speed_value = 0;

void canSendSpeed(void){

  const uint8_t delta_time = 100; // const
  uint16_t speed_value = s_speed + last_speed_value;

  uint16_t counter = (speedData[6] | (speedData[7] << 8)) & 0x0FFF;
  counter += (float)delta_time * 3.14159265358979323846;

  speedData[0] = speed_value;
  speedData[1] = (speed_value >> 8);

  speedData[2] = speedData[0];
  speedData[3] = speedData[1];

  speedData[4] = speedData[0];
  speedData[5] = speedData[1];

  speedData[6] = counter;
  speedData[7] = (counter >> 8) | 0xF0;

  sendFrame(&speedHeader, speedData);
  last_speed_value = speed_value;

}

void canSendSteeringWheel(void){
  steeringWheelData[1] = 0;
  steeringWheelData[2] = 0;

  sendFrame(&steeringWheelHeader, steeringWheelData);
}

void canSendLights(void){
  uint16_t lights = 0;

  if(s_light_parking) lights |= L_BACKLIGHT;
  if(s_light_dip) lights |= L_DIP;
  if(s_light_main) lights |= L_MAIN;
  if(s_light_fog) lights |= L_FOG;

  lightsOffData[0] = lights;

  sendFrame(&lightsOffHeader, lightsOffData);
}

uint8_t last_indicator = I_OFF; // off;
unsigned long last_indicator_time = 0;
unsigned long last_frame_time = 0;
const unsigned long INDICATOR_OFF_DELAY = 500;

void canSendIndicator(void){ //
  /*
  80 - off

  90 - left constant
  a0 - right constant
  b0 - hazzard constant

  91 - left normal blink
  a1 - right normal blink
  b1 - hazzard normal blink

  92 - left fast blink
  a2 - right fast blink
  b2 - hazzard fast blink
  */

  unsigned long time_now = globalTimer_ms;

  //Delay off signal. Helps if signal is blinking.
  uint8_t light_indicator = last_indicator;
  if(s_light_indicator == I_OFF){
    unsigned long off_delta_time = time_now - last_indicator_time;
    if(off_delta_time > INDICATOR_OFF_DELAY){
      light_indicator = s_light_indicator;
    }
  }else{
    light_indicator = s_light_indicator;
    last_indicator_time = time_now;
  }

  //Main decition block. 600ms interval or on signal change.
  unsigned long frame_delta_time = time_now - last_frame_time;
  if((last_indicator != light_indicator) || (frame_delta_time >= 600)){
    if(light_indicator != I_OFF){
      switch (light_indicator) {
        case I_LEFT:
          indicatorData[0] = 0x91;
          break;
        case I_RIGHT:
          indicatorData[0] = 0xA1;
          break;
        case I_HAZZARD:
          indicatorData[0] = 0xB1;
          break;
      }

      if(last_indicator == light_indicator){
        indicatorData[1] = 0xF1;
      }else{
        indicatorData[1] = 0xF2;
      }
    }else{
      indicatorData[0] = 0x80;
      indicatorData[1] = 0xF0;
    }

    last_indicator = light_indicator;
    last_frame_time = time_now;
    sendFrame(&indicatorHeader, indicatorData);
  }
}

void canSendAbs(void){
  ABSBrake2Data[2] = ((((ABSBrake2Data[2] >> 4) + 3) << 4) & 0xF0) | 0x03;
  sendFrame(&ABSBrake2Header, ABSBrake2Data);
}

void canSendEngineTemp(void){
  coolantData[0] = s_engine_temp + 48;
  coolantData[2]++;
  sendFrame(&coolantHeader, coolantData);
}

void canSendAbsCounter(void){
  sendFrame(&ABSBrake1Header, ABSBrake1Data);
  ABSBrake1Data[0] = ((ABSBrake1Data[0] + 1) | 0xF0);
}

void canSendAirbagCounter(void){
  sendFrame(&airbagSeatbeltHeader, airbagSeatbeltData);
  airbagSeatbeltData[0]++;
}

void canSendFuel(void){

  uint16_t level = (100+(s_fuel*8) < 8000) ? 100+(s_fuel*8) : 8000;
  fuelLevelData[0] = level;
  fuelLevelData[1] = (level >> 8);

  fuelLevelData[2] = fuelLevelData[0];
  fuelLevelData[3] = fuelLevelData[1];

  sendFrame(&fuelLevelHeader, fuelLevelData);
}

void canSendHandbrake(void){
  if(s_handbrake){
    handbrakeData[0] = 0xFE;
  }else{
	handbrakeData[0] = 0xFD;
  }
  sendFrame(&handbrakeHeader, handbrakeData);
}

void canSendTime(){
  dateTimeData[0] = s_time_hour;
  dateTimeData[1] = s_time_minute;
  dateTimeData[2] = s_time_sec;

  dateTimeData[3] = s_time_day;
  dateTimeData[4] = (s_time_month << 4) | 0x0F;

  dateTimeData[5] = (uint8_t)s_time_year;
  dateTimeData[6] = (uint8_t)(s_time_year >> 8);
  sendFrame(&dateTimeHeader, dateTimeData);
}



