/*****************************************************************************/
/* Title        	: 	DIO Driver											 */
/* File Name    	: 	DIO_private.h                                        */
/* Author       	: 	 Mohamed Mohalhal                                    */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	17/11/2023                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

/******************************************************************************
* !comment : PORTx Registers Addesses Definitions.  			         	  *
******************************************************************************/
#define DIO_u8_PORTA_REG        *((volatile u8 *)0X3B)
#define DIO_u8_PORTB_REG        *((volatile u8 *)0X38)
#define DIO_u8_PORTC_REG        *((volatile u8 *)0X35)
#define DIO_u8_PORTD_REG        *((volatile u8 *)0X32)


/******************************************************************************
* !comment : DDRx Registers Addesses Definitions.  			         	      *
******************************************************************************/
#define DIO_u8_DDRA_REG         *((volatile u8 *)0X3A)
#define DIO_u8_DDRB_REG         *((volatile u8 *)0X37)
#define DIO_u8_DDRC_REG         *((volatile u8 *)0X34)
#define DIO_u8_DDRD_REG         *((volatile u8 *)0X31)


/******************************************************************************
* !comment : PINx Registers Addesses Definitions.  			         	      *
******************************************************************************/
#define DIO_u8_PINA_REG         *((volatile u8 *)0X39)
#define DIO_u8_PINB_REG         *((volatile u8 *)0X36)
#define DIO_u8_PINC_REG         *((volatile u8 *)0X33)
#define DIO_u8_PIND_REG         *((volatile u8 *)0X30)

#define DIO_u8_INTIAL_OUTPUT						1
#define DIO_u8_INTIAL_INPUT							0

#define DIO_u8_OUTPUT_LOW							0
#define DIO_u8_OUTPUT_HIGH							1
#define DIO_u8_INPUT_FLOATING						0
#define DIO_u8_INPUT_PULLUP							1

#define Conc(b7,b6,b5,b4,b3,b2,b1,b0)           Conc_Help(b7,b6,b5,b4,b3,b2,b1,b0)
#define Conc_Help(b7,b6,b5,b4,b3,b2,b1,b0)      0b##b7##b6##b5##b4##b3##b2##b1##b0

#endif
/*** !comment : End of gaurd [DIO_PRIVATE_H] *********************************/