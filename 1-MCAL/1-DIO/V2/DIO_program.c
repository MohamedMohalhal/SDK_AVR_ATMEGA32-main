/*****************************************************************************/
/* Title        	: 	DIO Driver								 			 */
/* File Name   		: 	DIO_program.c                                        */
/* Author       	: 	Mohamed Mohalhal                                     */
/* Version          : 	2.0.0                                                */
/* Origin Date  	: 	13/12/2023                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
******************************* STD LIB DIRECTIVES ****************************
******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/******************************************************************************
****************************** Component DIRECTIVES ***************************
******************************************************************************/
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

/******************************************************************************
**************************** Function Implementation **************************
******************************************************************************/

void DIO_voidInit         (void)
{
	DIO_u8_DDRA_REG = Conc(DIO_u8_PA7_INTIAL_DIRECTION,DIO_u8_PA6_INTIAL_DIRECTION,DIO_u8_PA5_INTIAL_DIRECTION,DIO_u8_PA4_INTIAL_DIRECTION,
						   DIO_u8_PA3_INTIAL_DIRECTION,DIO_u8_PA2_INTIAL_DIRECTION,DIO_u8_PA1_INTIAL_DIRECTION,DIO_u8_PA0_INTIAL_DIRECTION);

	DIO_u8_DDRB_REG = Conc(DIO_u8_PB7_INTIAL_DIRECTION,DIO_u8_PB6_INTIAL_DIRECTION,DIO_u8_PB5_INTIAL_DIRECTION,DIO_u8_PB4_INTIAL_DIRECTION,
						   DIO_u8_PB3_INTIAL_DIRECTION,DIO_u8_PB2_INTIAL_DIRECTION,DIO_u8_PB1_INTIAL_DIRECTION,DIO_u8_PB0_INTIAL_DIRECTION);

	DIO_u8_DDRC_REG = Conc(DIO_u8_PC7_INTIAL_DIRECTION,DIO_u8_PC6_INTIAL_DIRECTION,DIO_u8_PC5_INTIAL_DIRECTION,DIO_u8_PC4_INTIAL_DIRECTION,
						   DIO_u8_PC3_INTIAL_DIRECTION,DIO_u8_PC2_INTIAL_DIRECTION,DIO_u8_PC1_INTIAL_DIRECTION,DIO_u8_PC0_INTIAL_DIRECTION);

	DIO_u8_DDRD_REG = Conc(DIO_u8_PD7_INTIAL_DIRECTION,DIO_u8_PD6_INTIAL_DIRECTION,DIO_u8_PD5_INTIAL_DIRECTION,DIO_u8_PD4_INTIAL_DIRECTION,
						   DIO_u8_PD3_INTIAL_DIRECTION,DIO_u8_PD2_INTIAL_DIRECTION,DIO_u8_PD1_INTIAL_DIRECTION,DIO_u8_PD0_INTIAL_DIRECTION);

	DIO_u8_PORTA_REG = Conc(DIO_u8_PA7_INTIAL_VALUE,DIO_u8_PA6_INTIAL_VALUE,DIO_u8_PA5_INTIAL_VALUE,DIO_u8_PA4_INTIAL_VALUE,
						   DIO_u8_PA3_INTIAL_VALUE,DIO_u8_PA2_INTIAL_VALUE,DIO_u8_PA1_INTIAL_VALUE,DIO_u8_PA0_INTIAL_VALUE);

	DIO_u8_PORTB_REG = Conc(DIO_u8_PB7_INTIAL_VALUE,DIO_u8_PB6_INTIAL_VALUE,DIO_u8_PB5_INTIAL_VALUE,DIO_u8_PB4_INTIAL_VALUE,
						   DIO_u8_PB3_INTIAL_VALUE,DIO_u8_PB2_INTIAL_VALUE,DIO_u8_PB1_INTIAL_VALUE,DIO_u8_PB0_INTIAL_VALUE);

	DIO_u8_PORTC_REG = Conc(DIO_u8_PC7_INTIAL_VALUE,DIO_u8_PC6_INTIAL_VALUE,DIO_u8_PC5_INTIAL_VALUE,DIO_u8_PC4_INTIAL_VALUE,
						   DIO_u8_PC3_INTIAL_VALUE,DIO_u8_PC2_INTIAL_VALUE,DIO_u8_PC1_INTIAL_VALUE,DIO_u8_PC0_INTIAL_VALUE);

	DIO_u8_PORTD_REG = Conc(DIO_u8_PD7_INTIAL_VALUE,DIO_u8_PD6_INTIAL_VALUE,DIO_u8_PD5_INTIAL_VALUE,DIO_u8_PD4_INTIAL_VALUE,
						   DIO_u8_PD3_INTIAL_VALUE,DIO_u8_PD2_INTIAL_VALUE,DIO_u8_PD1_INTIAL_VALUE,DIO_u8_PD0_INTIAL_VALUE);
}


tenuERorrStatus DIO_enuSetPinValue(u8 Copy_u8PinNum , u8 Copy_u8PinValue)

{
	tenuERorrStatus  enuErorrStatus = STD_TYPES_OK ;
	if((Copy_u8PinNum >= DIO_u8_PIN0) && (Copy_u8PinNum <= DIO_u8_PIN7))
		{
			switch (Copy_u8PinValue)
			{
				case DIO_u8_LOW:  CLR_BIT(DIO_u8_PORTA_REG , Copy_u8PinNum);break;
				case DIO_u8_HIGH: SET_BIT(DIO_u8_PORTA_REG , Copy_u8PinNum);break;
				default: enuErorrStatus = STD_TYPES_NOK ;break;
			}
		}
	else if((Copy_u8PinNum >= DIO_u8_PIN8) && (Copy_u8PinNum <= DIO_u8_PIN15))
	{
		switch (Copy_u8PinValue)
		{
			case DIO_u8_LOW:  CLR_BIT(DIO_u8_PORTB_REG , Copy_u8PinNum%8);break;
			case DIO_u8_HIGH: SET_BIT(DIO_u8_PORTB_REG , Copy_u8PinNum%8);break;
			default: enuErorrStatus = STD_TYPES_NOK ;break;
		}
	}
	else if((Copy_u8PinNum >= DIO_u8_PIN16) && (Copy_u8PinNum <= DIO_u8_PIN23))
	{
		switch (Copy_u8PinValue)
		{
			case DIO_u8_LOW:  CLR_BIT(DIO_u8_PORTC_REG , Copy_u8PinNum%8);break;
			case DIO_u8_HIGH: SET_BIT(DIO_u8_PORTC_REG , Copy_u8PinNum%8);break;
			default: enuErorrStatus = STD_TYPES_NOK ;break;
		}
	}
	else if((Copy_u8PinNum >= DIO_u8_PIN24) && (Copy_u8PinNum <= DIO_u8_PIN31))
	{
		switch (Copy_u8PinValue)
		{
			case DIO_u8_LOW:  CLR_BIT(DIO_u8_PORTD_REG , Copy_u8PinNum%8);break;
			case DIO_u8_HIGH: SET_BIT(DIO_u8_PORTD_REG , Copy_u8PinNum%8);break;
			default: enuErorrStatus = STD_TYPES_NOK ;break;
		}
	}
	else
	{
		enuErorrStatus = ERORR_STD_TYPES_NOK_PARAM_OUT_OF_RANGE ;
	}
	return enuErorrStatus ;
}

tenuERorrStatus DIO_enuGetPinValue(u8 Copy_u8PinNum , u8 *Copy_pu8PinValue)
{
	tenuERorrStatus  enuErorrStatus = STD_TYPES_OK ;
	if(Copy_pu8PinValue != NULL_PTR)
	{
		if((Copy_u8PinNum >= DIO_u8_PIN0) && (Copy_u8PinNum <= DIO_u8_PIN7))
			{
				*Copy_pu8PinValue = GET_BIT(DIO_u8_PINA_REG,Copy_u8PinNum);
			}
		else if((Copy_u8PinNum >= DIO_u8_PIN8) && (Copy_u8PinNum <= DIO_u8_PIN15))
		{
			*Copy_pu8PinValue = GET_BIT(DIO_u8_PINB_REG,Copy_u8PinNum);
		}
		else if((Copy_u8PinNum >= DIO_u8_PIN16) && (Copy_u8PinNum <= DIO_u8_PIN23))
		{
			*Copy_pu8PinValue = GET_BIT(DIO_u8_PINC_REG,Copy_u8PinNum);
		}
		else if((Copy_u8PinNum >= DIO_u8_PIN24) && (Copy_u8PinNum <= DIO_u8_PIN31))
		{
			*Copy_pu8PinValue = GET_BIT(DIO_u8_PIND_REG,Copy_u8PinNum);
		}
		else
		{
			enuErorrStatus = ERORR_STD_TYPES_NOK_PARAM_NULL_POINTER ;
		}
	}
	else
	{
		enuErorrStatus = ERORR_STD_TYPES_NOK_PARAM_OUT_OF_RANGE ;
	}
	return enuErorrStatus ;
}

tenuERorrStatus DIO_enuSetPinDirection(u8 Copy_u8PinNum , u8 Copy_u8PinDirection)
{
	tenuERorrStatus  enuErorrStatus = STD_TYPES_OK ;
	if((Copy_u8PinNum >= DIO_u8_PIN0) && (Copy_u8PinNum <= DIO_u8_PIN7))
		{
			switch (Copy_u8PinDirection)
			{
				case DIO_u8_INPUT:  CLR_BIT(DIO_u8_DDRA_REG , Copy_u8PinNum);break;
				case DIO_u8_OUTPUT: SET_BIT(DIO_u8_DDRA_REG , Copy_u8PinNum);break;
				default: enuErorrStatus = STD_TYPES_NOK ;break;
			}
		}
	else if((Copy_u8PinNum >= DIO_u8_PIN8) && (Copy_u8PinNum <= DIO_u8_PIN15))
	{
		switch (Copy_u8PinDirection)
		{
			case DIO_u8_INPUT:  CLR_BIT(DIO_u8_DDRB_REG , Copy_u8PinNum%8);break;
			case DIO_u8_OUTPUT: SET_BIT(DIO_u8_DDRB_REG , Copy_u8PinNum%8);break;
			default: enuErorrStatus = STD_TYPES_NOK ;break;
		}
	}
	else if((Copy_u8PinNum >= DIO_u8_PIN16) && (Copy_u8PinNum <= DIO_u8_PIN23))
	{
		switch (Copy_u8PinDirection)
		{
			case DIO_u8_INPUT:  CLR_BIT(DIO_u8_DDRC_REG , Copy_u8PinNum%8);break;
			case DIO_u8_OUTPUT: SET_BIT(DIO_u8_DDRC_REG , Copy_u8PinNum%8);break;
			default: enuErorrStatus = STD_TYPES_NOK ;break;
		}
	}
	else if((Copy_u8PinNum >= DIO_u8_PIN24) && (Copy_u8PinNum <= DIO_u8_PIN31))
	{
		switch (Copy_u8PinDirection)
		{
			case DIO_u8_INPUT:  CLR_BIT(DIO_u8_DDRD_REG , Copy_u8PinNum%8);break;
			case DIO_u8_OUTPUT: SET_BIT(DIO_u8_DDRD_REG , Copy_u8PinNum%8);break;
			default: enuErorrStatus = STD_TYPES_NOK ;break;
		}
	}
	else
	{
		enuErorrStatus = ERORR_STD_TYPES_NOK_PARAM_OUT_OF_RANGE ;
	}
	return enuErorrStatus ;
}

tenuERorrStatus DIO_enuSetPortValue(u8 Copy_u8Port, u8 Copy_u8PortValue)
{
	tenuERorrStatus  enuErorrStatus = STD_TYPES_OK ;
	switch(Copy_u8Port)
	{
		case DIO_u8_PORTA: DIO_u8_PORTA_REG = Copy_u8PortValue;break;
		case DIO_u8_PORTB: DIO_u8_PORTB_REG = Copy_u8PortValue;break;
		case DIO_u8_PORTC: DIO_u8_PORTC_REG = Copy_u8PortValue;break;
		case DIO_u8_PORTD: DIO_u8_PORTD_REG = Copy_u8PortValue;break;
		default: enuErorrStatus = ERORR_STD_TYPES_NOK_PARAM_OUT_OF_RANGE ;break;
	}
	return enuErorrStatus ;
}

tenuERorrStatus DIO_enuSetPortDirection(u8 Copy_u8Port, u8  Copy_u8PortDireection)
{
	tenuERorrStatus  enuErorrStatus = STD_TYPES_OK ;
	switch(Copy_u8Port)
		{
		case DIO_u8_PORTA: DIO_u8_DDRA_REG = Copy_u8PortDireection;break;
		case DIO_u8_PORTB: DIO_u8_DDRB_REG = Copy_u8PortDireection;break;
		case DIO_u8_PORTC: DIO_u8_DDRC_REG = Copy_u8PortDireection;break;
		case DIO_u8_PORTD: DIO_u8_DDRC_REG = Copy_u8PortDireection;break;
		default: enuErorrStatus = ERORR_STD_TYPES_NOK_PARAM_OUT_OF_RANGE ;break;
	}
	return enuErorrStatus ;
}

tenuERorrStatus DIO_enuGetPortValue(u8 Copy_u8Port, u8 *Copy_pu8PortValue)
{
	tenuERorrStatus  enuErorrStatus = STD_TYPES_OK ;
	if( Copy_pu8PortValue != NULL_PTR)
	{
		switch (Copy_u8Port)
		{
			case DIO_u8_PORTA: *Copy_pu8PortValue = DIO_u8_PINA_REG;break;
			case DIO_u8_PORTB: *Copy_pu8PortValue = DIO_u8_PINB_REG;break;
			case DIO_u8_PORTC: *Copy_pu8PortValue = DIO_u8_PINC_REG;break;
			case DIO_u8_PORTD: *Copy_pu8PortValue = DIO_u8_PIND_REG;break;
			default : enuErorrStatus = ERORR_STD_TYPES_NOK_PARAM_OUT_OF_RANGE;
		}
	}
	else
	{
		enuErorrStatus = ERORR_STD_TYPES_NOK_PARAM_NULL_POINTER;
	}
	return enuErorrStatus ;
}

tenuERorrStatus DIO_enuTogglePin(u8 Copy_u8PinNum)
{
	tenuERorrStatus  enuErorrStatus = STD_TYPES_OK ;
	if((Copy_u8PinNum >= DIO_u8_PIN0) && (Copy_u8PinNum <= DIO_u8_PIN7))
	{
		TGL_BIT(DIO_u8_PORTA_REG,Copy_u8PinNum);
	}
	else if((Copy_u8PinNum >= DIO_u8_PIN8) && (Copy_u8PinNum <= DIO_u8_PIN15))
	{
		TGL_BIT(DIO_u8_PORTB_REG,Copy_u8PinNum);
	}
	else if((Copy_u8PinNum >= DIO_u8_PIN16) && (Copy_u8PinNum <= DIO_u8_PIN23))
	{
		TGL_BIT(DIO_u8_PORTC_REG,Copy_u8PinNum);
	}
	else if((Copy_u8PinNum >= DIO_u8_PIN24) && (Copy_u8PinNum <= DIO_u8_PIN31))
	{
		TGL_BIT(DIO_u8_PORTD_REG,Copy_u8PinNum);
	}
	else
	{
		enuErorrStatus = ERORR_STD_TYPES_NOK_PARAM_OUT_OF_RANGE;
	}

	return enuErorrStatus ;
}

/******************************************************************************
********************************* END OF PROGRAM ******************************
******************************************************************************/
