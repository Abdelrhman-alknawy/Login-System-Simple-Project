/*
 * LCD_Program.c
 *
 *  Created on: Mar 28, 2023
 *      Author: abdelrhman
 */
#include <avr/delay.h>
#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"
#include"../MCAL/DIO/DIO_Interface.h"
#include"LCD_Interface.h"
#include"../MCAL/DIO/DIO_Private.h"
#include"LCD_Config.h"
void LCD_VoidInit(void)
{
	DIO_voidSetPinDirection(LCD_CR,RW,OUTPUT);
	DIO_voidSetPinDirection(LCD_CR,RS,OUTPUT);
	DIO_voidSetPinDirection(LCD_CR,E,OUTPUT);
	DIO_voidSetPortDirection(LCD_DR,PORT_HIGH);
	_delay_ms(32);
	LCD_VoidSendCommand(FUNCTION_SET);
	_delay_ms(1);
	LCD_VoidSendCommand(DISPLAYON_OFF);
	_delay_ms(1);
	LCD_VoidSendCommand(DISPLAY_Clear);
	_delay_ms(1);
	LCD_VoidSendCommand(Entry_Mode_Set_1);
}

void LCD_VoidSendCommand(u8 Copy_u8_Value )
{
	DIO_voidSetPinValue(LCD_CR,RS,LOW);
	DIO_voidSetPinValue(LCD_CR,RW,LOW);
	DIO_voidSetPortValue(LCD_DR,Copy_u8_Value);
	DIO_voidSetPinValue(LCD_CR,E,HIGH);
	_delay_ms(50);
	DIO_voidSetPinValue(LCD_CR,E,LOW);
}
void LCD_VoidSendData(u8 Copy_u8_Value)
{//RS = 1
	DIO_voidSetPinValue(LCD_CR,RS,HIGH);
	DIO_voidSetPinValue(LCD_CR,RW,LOW);
	DIO_voidSetPortValue(LCD_DR,Copy_u8_Value);
	DIO_voidSetPinValue(LCD_CR,E,HIGH);
	_delay_ms(50);
	DIO_voidSetPinValue(LCD_CR,E,LOW);
}

void LCD_VoidSendNum(u16 Copy_u16_Value)
{


    u16 m = 0 ;
    while (Copy_u16_Value!=0)
    {

        m=m*10+(Copy_u16_Value%10);
        Copy_u16_Value/=10;

    }


    while (m!=0)
    {   int mo;
        mo=m%10;
//        LCD_VoidSendData(mo+48);
        m/=10;
    }

}
void LCD_VoidSendString(u8 * ptr)
{
	u8 i = 0;
	while(ptr[i]!='\0')
	{
		LCD_VoidSendData(ptr[i]);
		i++;
	}
}

void LCD_VoidGoto(u8 Copy_u8Line, u8 Copy_u8Column)
{
	switch (Copy_u8Line)
	{
			case LINE_1 : LCD_VoidSendCommand((0x80)+Copy_u8Column);

					break;
			case LINE_2 : LCD_VoidSendCommand((0xC0)+Copy_u8Column);
			break ;
	}
}

void LCD_VoidSendPattern(u8 *Copy_u8ARR ,  u8 Copy_CGRAM_ADDRESS,u8 Copy_u8Line,u8 Copy_u8Column)
{
	u8 Local_Variabl = Copy_CGRAM_ADDRESS*8 ;
	LCD_VoidSendCommand((Local_Variabl)+64);
	u8 Local_iterator ;
	for( Local_iterator = 0 ; Local_iterator<8;Local_iterator++)
	{
		LCD_VoidSendData(Copy_u8ARR[Local_iterator]);
	}
	LCD_VoidGoto(Copy_u8Line,Copy_u8Column);
	LCD_VoidSendData(Copy_CGRAM_ADDRESS);
}
