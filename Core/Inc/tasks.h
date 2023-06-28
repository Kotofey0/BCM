/*
 * tasks.h
 *
 *  Created on: 5 мая 2023 г.
 *      Author: fedor.medin
 */

#ifndef INC_TASKS_H_
#define INC_TASKS_H_

#include "stm32f3xx_hal.h"
#include "can.h"

void task_1ms(void);
void task_10ms(void);
void task_200ms(void);
void task_500ms(void);
void task_1000ms(void);


#endif /* INC_TASKS_H_ */
