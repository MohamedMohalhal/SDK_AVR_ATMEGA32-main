/*****************************************************************************/
/* Title        	: 	DIO Driver											 */
/* File Name    	: 	DIO_interface.h                                      */
/* Author       	: 	Mohamed Mohalhal                                     */
/* Version      	: 	2.0.0                                                */
/* Origin Date  	: 	13/12/2023                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

/******************************************************************************
* !comment : DIO Ports options Definitions.  			         	          *
******************************************************************************/
#define DIO_u8_PORTA             0
#define DIO_u8_PORTB             1
#define DIO_u8_PORTC             2
#define DIO_u8_PORTD             3

/******************************************************************************
* !comment : DIO Pins options Definition.  			         	          	  *
******************************************************************************/
#define DIO_u8_PIN0              0
#define DIO_u8_PIN1              1
#define DIO_u8_PIN2              2
#define DIO_u8_PIN3              3
#define DIO_u8_PIN4              4
#define DIO_u8_PIN5              5
#define DIO_u8_PIN6              6
#define DIO_u8_PIN7              7

#define DIO_u8_PIN8              8
#define DIO_u8_PIN9              9
#define DIO_u8_PIN10             10
#define DIO_u8_PIN11             11
#define DIO_u8_PIN12             12
#define DIO_u8_PIN13             13
#define DIO_u8_PIN14             14
#define DIO_u8_PIN15             15

#define DIO_u8_PIN16             16
#define DIO_u8_PIN17          	 17
#define DIO_u8_PIN18             18
#define DIO_u8_PIN19             19
#define DIO_u8_PIN20             20
#define DIO_u8_PIN21             21
#define DIO_u8_PIN22             22
#define DIO_u8_PIN23             23

#define DIO_u8_PIN24             24
#define DIO_u8_PIN25             25
#define DIO_u8_PIN26             26
#define DIO_u8_PIN27             27
#define DIO_u8_PIN28             28
#define DIO_u8_PIN29             29
#define DIO_u8_PIN30             30
#define DIO_u8_PIN31             31

/******************************************************************************
* !comment : DIO Pin Mode options Definitions.  			         	      *
******************************************************************************/
#define DIO_u8_OUTPUT            1
#define DIO_u8_INPUT             0

/******************************************************************************
* !comment : DIO Pin Value options Definition.  			         	      *
******************************************************************************/
#define DIO_u8_HIGH              1
#define DIO_u8_LOW               0

/******************************************************************************
* !comment : DIO Port Value options Definition.  			         	      *
******************************************************************************/
#define  DIO_PORT_INPUT      0x00
#define  DIO_PORT_OUTPUT     0xff

/******************************************************************************
* Description : DIO setup function      						              *
* Parameters  : Void													  	  *
* Return type : Void			                                              *
******************************************************************************/
void DIO_voidInit(void);

/******************************************************************************
* Description : DIO set PIN value function.						              *
* Parameters  : PORT number(PORT_A -> PORT_D), PIN number(PIN0 -> PIN7),   	  *
*				Value(HIGH, LOW).     				                          *
* Return type : tenuERorrStatus                                               *
******************************************************************************/
tenuERorrStatus DIO_enuSetPinValue(u8 Copy_u8PinNum, u8 Copy_u8PinValue);

/******************************************************************************
* Description : DIO Get Pin Value function.						              *
* Parameters  : PORT number(PIN number(PIN0 -> PIN7)).   					  *
* Return type : uint8                                                  	 	  *
******************************************************************************/
tenuERorrStatus DIO_enuGetPinValue(u8 Copy_u8PinNum, u8 *Copy_pu8PinValue);
/******************************************************************************
* Description : DIO set PIN direction function.						          *
* Parameters  : PORT number(PORT_A -> PORT_D), PIN number(PIN0 -> PIN7),   	  *
*				Mode(OUTPUT, INPUT).     				                      *
* Return type :   tenuERorrStatus                                             *
******************************************************************************/
tenuERorrStatus DIO_enuSetPinDirection(u8 Copy_u8PinNum, u8 Copy_u8PinDirection);

/******************************************************************************
* Description : DIO set PORT Value function.						          *
* Parameters  : PORT number(PORT_A -> PORT_D), Value(HIGH, LOW).   	          *
* Return type : void                                                  	 	  *
******************************************************************************/
tenuERorrStatus DIO_enuSetPortValue(u8 Copy_u8Port, u8 Copy_u8PortValue);

/******************************************************************************
* Description : DIO set PORT direction function.						      *
* Parameters  : PORT number(PORT_A -> PORT_D), Mode(OUTPUT, INPUT).   	      *
* Return type : void                                                  	 	  *
******************************************************************************/
tenuERorrStatus DIO_enuSetPortDirection(u8 Copy_u8Port, u8 Copy_u8PortDireection);

/******************************************************************************
* Description : DIO Get Pin Value function.						              *
* Parameters  : PORT number(PORT_A -> PORT_D).   	  *
* Return type : uint8                                                  	 	  *
******************************************************************************/
tenuERorrStatus DIO_enuGetPortValue(u8 Copy_u8Port, u8 *Copy_pu8PortValue);

/******************************************************************************
* Description : DIO Toggle PIN function.						              *
* Parameters  : PORT number(PORT_A -> PORT_D), PIN number(PIN0 -> PIN7).   	  *
* Return type : void                                                  	 	  *
*******************************************************************************
* Pre_condition : This function must be used after set PIN direction          *
* 				  function.				 									  *
******************************************************************************/
tenuERorrStatus DIO_enuTogglePin(u8 Copy_u8PinNum);

#endif
/*** !comment : End of gaurd [DIO_INTERFACE_H] *******************************/
