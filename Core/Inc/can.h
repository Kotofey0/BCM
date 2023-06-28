/*
 * can.h
 *
 *  Created on: 5 мая 2023 г.
 *      Author: fedor.medin
 */

#ifndef INC_CAN_H_
#define INC_CAN_H_

#include "main.h"



void K_CAN_FramesInit(void);
void sendFrame(const CAN_TxHeaderTypeDef *pHeader, const uint8_t aData[]);
void canSendIgnitionFrame(void);
void canSendRPM(void);
void canSendSpeed(void);
void canSendSteeringWheel(void);
void canSendLights(void);
void canSendIndicator(void);
void canSendAbs(void);
void canSendEngineTemp(void);
void canSendAbsCounter(void);
void canSendAirbagCounter(void);
void canSendFuel(void);
void canSendHandbrake(void);
void canSendTime();


#endif /* INC_CAN_H_ */
