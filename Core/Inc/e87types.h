/*
 * e87types.h
 *
 *  Created on: 5 мая 2023 г.
 *      Author: fedor.medin
 */

#ifndef INC_E87TYPES_H_
#define INC_E87TYPES_H_

typedef enum{
  I_OFF = 0,
  I_LEFT = 1,
  I_RIGHT = 2,
  I_HAZZARD = 3,
} INDICATOR;


/*
  CAN ENUMS
*/
typedef enum{
  L_BRAKE = 0b10000000,
  L_FOG = 0b01000000,
  L_BACKLIGHT = 0b00000100,
  L_MAIN = 0b00000010,
  L_DIP = 0b00100000,
} CAN_LIGHTS;

#endif /* INC_E87TYPES_H_ */
