/*
 * BIT_MATH.h
 *
 *  Created on: Aug 10, 2024
 *      Author: Mohamed
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(var, bit) (var |= (1 << bit))
#define CLEAR_BIT(var, bit) (var &= (~(1 << bit)))
#define TOG_BIT(var, bit) (var ^= (1 << (bit)))
#define READ_BIT(var, bit) ((var >> bit) & 1)


#endif /* BIT_MATH_H_ */
