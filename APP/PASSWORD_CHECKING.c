/*
 * PASSWORD_CHECKING.c
 *
 *  Created on: Apr 15, 2023
 *      Author: abdelrhman
 */

#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"
#include"../KEYPAD/KEYPAD_Interface.h"
#include"../LCD/LCD_Interface.h"
#include<util/delay.h>
#include"../DC_MOTOR/DC_MOTOR_Interface.h"
#include"../DC_MOTOR/DC_MOTOR_Config.h"

//password in data base
u8 PASSWORD[4] = {'1','2','3','4'};
//password entered by user
u8 PASS_CHECK [4]={0};
int main ()
{
	DC_MOTOR_VoidInit();
	static u8 Local_u8Iterator = 0 ;
	LCD_VoidInit();
	KPD_voidInit();
	u8 Local_u8KeyPressed = 255 ;
	u8 Local_flag = 0;
	u8 i  ;
	u8 counter =0;
	static	u8 loopbreaker  = 0 ;

	while (1 )
	{


		if(Local_u8Iterator ==0 )
		{
			LCD_VoidSendCommand(DISPLAY_Clear);
			LCD_VoidSendString("enter pass");
			LCD_VoidGoto(LINE_2,1 );
		}

		do
		{
			Local_u8KeyPressed = KPD_u8GetPressedKey();
		}while(Local_u8KeyPressed	==	255);

			LCD_VoidSendData('*');
			PASS_CHECK [Local_u8Iterator]= Local_u8KeyPressed  ;
			Local_u8KeyPressed = 255 ;
			Local_u8Iterator ++ ;
			if(Local_u8Iterator==4)
			{
				Local_u8Iterator = 0;
				for(i = 0 ; i <= 3 ; i++)
				{
					if	(PASS_CHECK[i]==PASSWORD[i])
					{
						LCD_VoidGoto(LINE_2,1);
						counter ++ ;
					}
					else
					{
						LCD_VoidGoto(LINE_2,1);
						break;
					}
				}
				if(counter == 4 )
				{
					LCD_VoidSendCommand(DISPLAY_Clear);
					LCD_VoidGoto(LINE_1,5);
					LCD_VoidSendString("Welcome!");
					LCD_VoidGoto(LINE_2,3);
					LCD_VoidSendString("To our system ");
					_delay_ms(300);
					//entering the system
					while(1)
					{
						LCD_VoidSendCommand(DISPLAY_Clear);
						LCD_VoidSendString("SELECT MODE  ");
						_delay_ms(300);
						LCD_VoidSendCommand(DISPLAY_Clear);
						LCD_VoidGoto(LINE_1,1);
						LCD_VoidSendString("1-DC MOTOR ");
						LCD_VoidGoto(LINE_2,1);
						LCD_VoidSendString("2- Servo MOTOR ");
						_delay_ms(500);
						LCD_VoidSendCommand(DISPLAY_Clear);
						LCD_VoidSendString("CHOICE ");
						LCD_VoidGoto(LINE_2,1);
						Local_u8KeyPressed = 255 ;
						do
						{
						Local_u8KeyPressed = KPD_u8GetPressedKey();
						}while(Local_u8KeyPressed == 255 );
						LCD_VoidSendData(Local_u8KeyPressed);
						if(Local_u8KeyPressed  == '1' || Local_u8KeyPressed=='2'  )
						{
							switch (Local_u8KeyPressed)
							{
								case	'1' : LCD_VoidSendCommand(DISPLAY_Clear);
												LCD_VoidSendString("1- CW ");
												LCD_VoidGoto(LINE_2,1);
												LCD_VoidSendString("2- CCW ");
												_delay_ms(500);
												Local_u8KeyPressed = 255 ;
												do
												{
												Local_u8KeyPressed = KPD_u8GetPressedKey();
												}while(Local_u8KeyPressed == 255 );
												LCD_VoidSendCommand(DISPLAY_Clear);
												LCD_VoidSendString("CHOICE ");
												LCD_VoidGoto(LINE_2,1);
												LCD_VoidSendData(Local_u8KeyPressed);
												switch(Local_u8KeyPressed)
												{
													/*DC MOTOR MODE CW 	*/
													case '1' : DC_MOTOR_VoidDirection(CW);
													LCD_VoidSendCommand(DISPLAY_Clear);
													LCD_VoidSendString("Motor ON");
													LCD_VoidGoto(LINE_2,1);
													LCD_VoidSendString("CW ");
													_delay_ms(2000);
																break ;
													case '2' : DC_MOTOR_VoidDirection(CCW);
													LCD_VoidSendCommand(DISPLAY_Clear);
													LCD_VoidSendString("Motor ON");
													LCD_VoidGoto(LINE_2,1);
													LCD_VoidSendString("CCW ");
													_delay_ms(2000);
												}
												break;
							}
						}
						else
						{
							Local_u8KeyPressed = 255 ;
							break ;
						}
					}
				}
				else if (counter !=4) {
					LCD_VoidGoto(LINE_2,1);
					LCD_VoidSendCommand(DISPLAY_Clear);
					loopbreaker ++ ;
					if(loopbreaker ==3 )
					{
						LCD_VoidSendCommand(DISPLAY_Clear);
						LCD_VoidSendString("No more tries ");

						break;
					}
					LCD_VoidSendString("Try Again ");
				}
			}
	}
}

