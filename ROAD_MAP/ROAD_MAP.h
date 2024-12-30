/*
 * ROAD_MAP.h
 *
 *  Created on: Sep 6, 2024
 *      Author: Mohamed
 */

#ifndef ROAD_MAP_ROAD_MAP_H_
#define ROAD_MAP_ROAD_MAP_H_

/*********************** DIO ***********************/

#define PORTA *((volatile u8*)0x3B)
#define DDRA *((volatile u8*)(0x3A))
#define PINA *((volatile u8*)(0x39))

#define PORTB *((volatile u8*)(0x38))
#define DDRB *((volatile u8*)(0x37))
#define PINB *((volatile u8*)(0x36))

#define PORTC *((volatile u8*)(0x35))
#define DDRC *((volatile u8*)(0x34))
#define PINC *((volatile u8*)(0x33))

#define PORTD *((volatile u8*)(0x32))
#define DDRD *((volatile u8*)(0x31))
#define PIND *((volatile u8*)(0x30))

/***********************STATUS REGISTER ***********************/

#define SREG *((volatile u8*)(0x5F))
#define I	7 										//global interrupt pin

/***********************EXTI INTERRUPTS ***********************/
#define GICR *((volatile u8*)(0x5B))
#define INT1	7 									//Interrupt 1 PIE Peripheral Interrupt Enable
#define INT0	6								 	//Interrupt 0 PIE
#define INT2	5 									//Interrupt 2 PIE

/**************************************************************/
#define GIFR *((volatile u8*)(0x5A))
#define INTF1	7 									//Interrupt 1 by Hardware
#define INTF0	6									//Interrupt 0 by Hardware
#define INTF2	5 									//Interrupt 2 by Hardware

/**************************************************************/
#define MCUCR *((volatile u8*)(0x55))
#define ISC00	0 									//for Interrupt 0 mode
#define ISC01	1 									//for Interrupt 0 mode
#define ISC10	2 									//for Interrupt 1 mode
#define ISC11	3									//for Interrupt 1 mode

/**************************************************************/
#define MCUCSR *((volatile u8*)(0x54))
#define ISC2 	6									//for Interrupt 2 mode



/***********************ADC ***********************/
#define ADMUX *((volatile u8*)(0x27))
#define REFS1	7
#define REFS0	6
#define ADLAR	5
#define MUX4	4
#define MUX3	3
#define MUX2	2
#define MUX1	1
#define MUX0	0

/**************************************************************/
#define ADCSRA *((volatile u8*)(0x26))
#define ADEN	7
#define ADSC	6
#define ADATE	5
#define ADIF	4
#define ADIE	3
#define ADPS2	2
#define ADPS1	1
#define ADPS0	0

/**************************************************************/
#define ADCL *((volatile u8*)(0x24))
#define ADCL_REG *((volatile u16*)(0x24))

/**************************************************************/
#define SFIOR *((volatile u8*)(0x50))
#define ADTS2	7
#define ADTS1	6
#define ADTS0	5

#define ACME	3
#define PUD		2
#define PSR2	1
#define PSR10	0

/*********************** Timer ***********************/
/*******TIMER0*******/
#define TIMSK *((volatile u8*)(0x59))
#define TOIE0	 0
#define OCIE0	 1


#define TIFR  *((volatile u8*)(0x58))
#define TOV0	0
#define OCF0 	1

#define TCNT0 *((volatile u8*)(0x52)) //TIMER REGISTER


#define TCCR0 *((volatile u8*)(0x53))
#define CS00	0
#define CS01	1
#define CS02	2
#define WGM01	3
#define COM00	4
#define COM01 	5
#define WGM00	6

#define OCR0 *((volatile u8*)(0x5C))
/*******TIMER2*******/
#define OCIE2 7
#define TOIE2 6

#define OCF2 7
#define TOV2 6

#define SFIOR *((volatile u8*)(0x50))
#define PSR2 1

#define TCCR2 *((volatile u8*)(0x45))
#define CS20	0
#define CS21	1
#define CS22	2
#define WGM21	3
#define COM20	4
#define COM21 	5
#define WGM20	6

#define TCNT2 *((volatile u8*)(0x44)) //TIMER REGISTER

#define OCR2 *((volatile u8*)(0x43))

#define ASSR *((volatile u8*)(0x42))
#define TCR2UB		0
#define OCR2UB		1
#define TCN2UB 		2
#define AS2			3
/*********Timer 1*******************/
#define ICR1   		*((volatile u16*)(0x46))
#define ICR1L    	*((volatile u8*)(0x46))
#define ICR1H     	*((volatile u8*)(0x47))
#define OCR1B    	*((volatile u16*)(0x48))
#define OCR1BL    	*((volatile u8*)(0x48))
#define OCR1BH      *((volatile u8*)(0x49))
#define OCR1A       *((volatile u16*)(0x4A))
#define OCR1AL   	*((volatile u8*)(0x4A))
#define OCR1AH     	*((volatile u8*)(0x4B))
#define TCNT1       *((volatile u16*)(0x4C))
#define TCNT1L    	*((volatile u8*)(0x4C))
#define TCNT1H    	*((volatile u8*)(0x4D))
#define TCCR1B      *((volatile u8*)(0x4E))
#define TCCR1A      *((volatile u8*)(0x4F))

#define SFIOR        *((volatile u8*)(0x50))

#define OSCCAL       *((volatile u8*)(0x51))

/* TCCR1A */
#define COM1A1  7
#define COM1A0  6
#define COM1B1  5
#define COM1B0  4
#define FOC1A   3
#define FOC1B   2
#define WGM11   1
#define WGM10   0

/* TCCR1B */
#define ICNC1   7
#define ICES1   6
/* bit 5 reserved */
#define WGM13   4
#define WGM12   3
#define CS12    2
#define CS11    1
#define CS10    0

/* WDTCR */
#define WDTCR    (*(volatile unsigned char*)0x41)
/* bits 7-5 reserved */
#define WDTOE   4
#define WDE     3
#define WDP2    2
#define WDP1    1
#define WDP0    0
/*timsk*/
#define TOIE1   2
#define OCIE1B  3
#define OCIE1A  4
#define TICIE1  5
/* UART  */
#define UDR		(*(volatile u8*)0x2C)
#define UCSRA	(*(volatile u8*)0x2B)
#define RXC         7
#define TXC         6
#define UDRE        5
#define FE 			4
#define DOR			3
#define PE			2
#define U2X			1
#define MPCM		0

#define UCSRB   (*(volatile u8*)0x2A)
#define RXCIE       7
#define TXCIE       6
#define UDRIE       5
#define RXEN        4
#define TXEN        3
#define UCSZ2		2
#define RXB8		1
#define TXB8 		0
#define UMREL       7
#define UCSZ0       1
#define UCSZ1       2

#define UCSRC	(*(volatile u8*)0x40)
#define URSEL   7
#define UMSEL   6
#define UPM1    5
#define UPM0    4
#define USBS    3
#define UCSZ1   2
#define UCSZ0   1
#define UCPOL   0
#define UBRRL	(*(volatile u8*)0x29)
/* SPI */
/* SPI Control Register */
#define SPCR       (*(volatile unsigned char*)0x2D)
/* SPI Status Register */
#define SPSR       (*(volatile unsigned char*)0x2E)
/* SPI I/O Data Register */
#define SPDR       (*(volatile unsigned char*)0x2F)

/* SPI Status Register - SPSR */
#define    SPIF         7
#define    WCOL         6
#define    SPI2X        0

/* SPI Control Register - SPCR */
#define    SPIE         7
#define    SPE          6
#define    DORD         5
#define    MSTR         4
#define    CPOL         3
#define    CPHA         2
#define    SPR1         1
#define    SPR0         0
/********************I2C**********************/
#define TWBR  	*((volatile u8*)(0x20))  	//  Bit Rate Register

#define TWCR	*((volatile u8*)(0x56))
#define TWINT	7		// TWI Interrupt Flag
#define TWEA	6		// TWI Enable Acknowledge Bit
#define TWSTA	5		// TWI START Condition Bit
#define TWSTO	4		// TWI STOP Condition Bit
#define TWWC	3		// TWI Write Collision Flag
#define TWEN	2		// TWI Enable Bit
#define TWIE	0		// TWI Interrupt Enable

#define TWSR 	*((volatile u8*)(0x21))
#define TWS7	7		// TWI Status
#define TWS6	6
#define TWS5	5
#define TWS4	4
#define TWS3	3
#define TWPS1	1		// TWI Prescaler Bits
#define TWPS0	0

#define TWDR 	*((volatile u8*)(0x23))		// TWI Data Register

#define TWD0 	0

#define TWAR	*((volatile u8*)(0x22))
#define TWA6	7		// TWI (Slave) Address Register
#define TWA5	6
#define TWA4	5
#define TWA3	4
#define TWA2	3
#define TWA1	2
#define TWA0	1
#define TWGCE	0		//  TWI General Call Recognition Enable Bit
#endif /* ROAD_MAP_ROAD_MAP_H_ */
