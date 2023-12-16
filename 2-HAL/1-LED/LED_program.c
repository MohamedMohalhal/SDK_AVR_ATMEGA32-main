/********************************************************************************/
/* Title        	: 	LED Driver											    */
/* File Name    	: 	LED_program.c   		                                */
/* Author       	: 	Mohamed Mohalhal                                        */
/* Version      	: 	1.0.0                                                   */
/* Origin Date  	: 	13/12/2023                                              */
/* Notes        	: 	None                                                    */
/********************************************************************************/

/*********************************************************************************
******************************* STD LIB DIRECTIVES *******************************
*********************************************************************************/

#include "STD_Types.h"
#include "BIT_Math.h"

/*********************************************************************************
********************************* DIO DIRECTIVES *********************************
*********************************************************************************/

#include "DIO_interface.h"

/*********************************************************************************
****************************** Component DIRECTIVES ******************************
*********************************************************************************/

#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"


/*********************************************************************************
***************************** Function Implementation ****************************
*********************************************************************************/


/*********************************************************************************
* Description 	: Configuring an LED as output.						        	 *
* Parameters  	: none   		                                    	 		 *
* Return type 	: void                                                  	 	 *
*********************************************************************************/

void LED_voidInit(u8 Copy_u8PinNumber){

	/* Setting the pin as output */
	DIO_enuSetPinDirection(Copy_u8PinNumber, DIO_u8_OUTPUT);
	
	/* Setting the initial value as low */
	DIO_enuSetPinValue(Copy_u8PinNumber, DIO_u8_LOW);

}


/*********************************************************************************
* Description 	: Control the state of an LED.							         *
* Parameters  	: PORT number(PORT_A -> PORT_D), PIN number(PIN0 -> PIN7),       *
*				  LED Value (LED_ON, LED_OFF, LED_TOG).     				     *
* Return type 	: void.                                                    	 	 *
**********************************************************************************
* Pre_condition : This function must be used after LED initialized.              *
*********************************************************************************/

tenuERorrStatus LED_enuLedValue(u8 Copy_u8PinNumber, u8 Copy_u8State)
{
	tenuERorrStatus  enuErorrStatus = STD_TYPES_OK ;
	switch(Copy_u8State){

		case LED_ON :
			/* Setting the pin value as high */
			DIO_enuSetPinValue(Copy_u8PinNumber, LED_MODE);
	    break;

		case LED_OFF:
			/* Setting the pin value as low */
			DIO_enuSetPinValue(Copy_u8PinNumber, !(LED_MODE));
		break;

		case LED_TOG:
			/* Setting the pin value as toggle */
			DIO_enuTogglePin(Copy_u8PinNumber);
		break;
		default: enuErorrStatus = ERORR_STD_TYPES_NOK_PARAM_OUT_OF_RANGE;
		break;
	}
	return enuErorrStatus;
}


/*********************************************************************************
********************************* END OF PROGRAM *********************************
*********************************************************************************/
