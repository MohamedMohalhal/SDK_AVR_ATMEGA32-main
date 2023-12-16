/*****************************************************************************/
/* Title        	: 	STD TYPES File									     */
/* File Name    	: 	STD_TYPES.h  		                                 */
/* Author       	: 	Moohamed Mohalhal                                    */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	05/08/2023                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

 #ifndef   STD_TYPES_H
 #define   STD_TYPES_H
 
 
typedef  unsigned char      u8    ;
typedef  unsigned short int u16   ;
typedef  unsigned long  int u32   ;
typedef  signed char        s8    ;
typedef  signed short  int  s16   ;
typedef  signed long   int  s32   ;
typedef  float              f32   ;
typedef  double             f64   ;
typedef  long double        f128  ;



#define  NULL_PTR    ((void *)0)

typedef enum
{
	STD_TYPES_OK,
	STD_TYPES_NOK,
	ERORR_STD_TYPES_NOK_PARAM_OUT_OF_RANGE,
	ERORR_STD_TYPES_NOK_PARAM_NULL_POINTER,
	ERORR_STD_TYPES_NOK_CONFIG_ERROR,
}tenuERorrStatus;

#endif 
/*** !comment : End of gaurd [STD_TYPES_H] ***********************************/


