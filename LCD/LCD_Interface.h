/*
 * LCD_Interface.h
 *
 *  Created on: Mar 28, 2023
 *      Author: abdelrhman
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_
#define FUNCTION_SET	0b00111100
#define DISPLAYON_OFF	0b00001100
#define DISPLAY_Clear	0b00000001
#define Entry_Mode_Set_1	0b00000110
#define Entry_Mode_Set_2	0b00000111
#define NEW_LINE        0xC0
#define LINE_1			1
#define LINE_2			2
/*********************************/
/***/
/***/
/***/
/***/

void LCD_VoidInit(void);
void LCD_VoidSendCommand(u8 Copy_u8_Value );
void LCD_VoidSendData (u8 Copy_u8_Value);
void LCD_VoidSendNum(u16 Copy_u16_Value);
void LCD_VoidSendString(u8 * ptr);
void LCD_VoidGoto(u8 Copy_u8Line, u8 Copy_u8Column);
void LCD_VoidSendPattern(u8 *Copy_u8ARR ,  u8 Copy_CGRAM_ADDRESS,u8 Copy_u8Line,u8 Copy_u8Column);
#endif /* HAL_LCD_LCD_INTERFACE_H_ */
