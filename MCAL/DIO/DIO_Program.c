#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "DIO_Config.h"





void DIO_voidSetPinValue(u8 Copy_u8Portnumber , u8 Copyu8Pinnumber , u8 Copyu8Value)
{
   switch(Copyu8Value)
   {
    case LOW :
              switch(Copy_u8Portnumber)
              {
                case PORTA:
                CLR_BIT(PORTA_REG,Copyu8Pinnumber);
                break;
                case PORTB:
                CLR_BIT(PORTB_REG,Copyu8Pinnumber);
                break;
                case PORTC:
                CLR_BIT(PORTC_REG,Copyu8Pinnumber);
                break;
                case PORTD :
                CLR_BIT(PORTD_REG,Copyu8Pinnumber);
                break;
                default :

                break;

              }

              break;
    case HIGH:
              switch(Copy_u8Portnumber)
              {
                case PORTA:
                SET_BIT(PORTA_REG,Copyu8Pinnumber);
                break;
                case PORTB:
                SET_BIT(PORTB_REG,Copyu8Pinnumber);
                break;
                case PORTC:
                SET_BIT(PORTC_REG,Copyu8Pinnumber);
                break;
                case PORTD :
                SET_BIT(PORTD_REG,Copyu8Pinnumber);
                break;
                default :

                break;
              }

    break;
    default :

    break;
   }
}
void DIO_voidSetPinDirection(u8 Copy_u8Portnumber , u8 Copyu8Pinnumber , u8 Copyu8Direction)
{
switch(Copyu8Direction)
   {
    case INPUT :
              switch(Copy_u8Portnumber)
              {
                case PORTA:
                CLR_BIT(DDRA_REG,Copyu8Pinnumber);
                break;
                case PORTB:
                CLR_BIT(DDRB_REG,Copyu8Pinnumber);
                break;
                case PORTC:
                CLR_BIT(DDRC_REG,Copyu8Pinnumber);
                break;
                case PORTD :
                CLR_BIT(DDRD_REG,Copyu8Pinnumber);
                break;
                default :

                break;

              }

              break;
    case OUTPUT:
              switch(Copy_u8Portnumber)
              {
                case PORTA:
                SET_BIT(DDRA_REG,Copyu8Pinnumber);
                break;
                case PORTB:
                SET_BIT(DDRB_REG,Copyu8Pinnumber);
                break;
                case PORTC:
                SET_BIT(DDRC_REG,Copyu8Pinnumber);
                break;
                case PORTD :
                SET_BIT(DDRD_REG,Copyu8Pinnumber);
                break;
                default :

                break;
              }

    break;
    default :

    break;
   }
}
u8 DIO_voidGetPinValue(u8 Copy_u8Portnumber , u8 Copyu8Pinnumber)
{
u8 Localu8Value ;
    switch(Copy_u8Portnumber)
    {
        case PORTA:
                  Localu8Value = GET_BIT(PINA_REG,Copyu8Pinnumber);
        break;

        case PORTB:
                  Localu8Value = GET_BIT(PINB_REG,Copyu8Pinnumber);
        break;

        case PORTC:
                 Localu8Value = GET_BIT(PINC_REG,Copyu8Pinnumber);
        break;

        case PORTD:
                 Localu8Value = GET_BIT(PIND_REG,Copyu8Pinnumber);
        break;
        default:
        break;

    }  
    return Localu8Value;                    
}

void DIO_voidSetPortValue(u8 Copy_u8Portnumber , u8 Copyu8Value)
{
            switch(Copy_u8Portnumber)
            {
                case PORTA:
                           PORTA_REG =Copyu8Value;
                break;

                case PORTB:
                           PORTB_REG =Copyu8Value;
                break;

                case PORTC:
                          PORTC_REG =Copyu8Value;
                break;

                case PORTD:
                           PORTD_REG =Copyu8Value;
                break;

                default:
                break;
            }
}

void DIO_voidSetPortDirection(u8 Copy_u8Portnumber , u8 Copyu8Direction)
{
   switch(Copy_u8Portnumber)
   {

                case PORTA:
                	DDRA_REG =Copyu8Direction;
                break;

                case PORTB:
                	DDRB_REG =Copyu8Direction;                break;

                case PORTC:
                	DDRC_REG =Copyu8Direction;                break;

                case PORTD:
                	DDRD_REG =Copyu8Direction;                break;

                default:
                break;
               }


}
u8 DIO_voidGetPortValue(u8 Copy_u8Portnumber)
{
 u8 Localu8variable;
 
     switch(Copy_u8Portnumber)
               {
                case PORTA:
                  Localu8variable = PINA_REG;
                break;

                case PORTB:
                  Localu8variable = PINB_REG;
                break;

                case PORTC:
                  Localu8variable = PINC_REG;
                break;

                case PORTD:
                  Localu8variable = PIND_REG;
                break;

                default:
                break;
               }
     return Localu8variable;
 
}
