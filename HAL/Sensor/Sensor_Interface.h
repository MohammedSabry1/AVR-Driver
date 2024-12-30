/*
 * Sensor_Interface.h
 *
 *  Created on: Sep 21, 2024
 *      Author: Mohamed
 */

#ifndef HAL_SENSOR_SENSOR_INTERFACE_H_
#define HAL_SENSOR_SENSOR_INTERFACE_H_

extern volatile u16 pulse_width;
extern volatile u8 echo_received;
u16 u16ADCVoltRead(u8 Channel);
u16 u16ADCTempRead(u8 Channel);
u8 u8DigitalFlameRead();
void vUltraSonicInit(void);
u32 u32UltraSonicMeasure();
#endif /* HAL_SENSOR_SENSOR_INTERFACE_H_ */
