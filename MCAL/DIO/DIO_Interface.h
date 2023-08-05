#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#define PORTA         0
#define PORTB         1
#define PORTC         2
#define PORTD         3

#define PIN0           0
#define PIN1           1
#define PIN2           2
#define PIN3           3
#define PIN4           4
#define PIN5           5
#define PIN6           6
#define PIN7           7

#define LOW            0
#define HIGH           1

#define INPUT          0
#define OUTPUT         1

#define PORT_HIGH	  0XFF
#define PORT_LOW 	   0
#define PORT_SIZE      8
void DIO_voidSetPinValue(u8 Copy_u8Portnumber , u8 Copyu8Pinnumber , u8 Copyu8Value);
void DIO_voidSetPinDirection(u8 Copy_u8Portnumber , u8 Copyu8Pinnumber , u8 Copyu8Direction);
u8 DIO_voidGetPinValue(u8 Copy_u8Portnumber , u8 Copyu8Pinnumber);

void DIO_voidSetPortValue(u8 Copy_u8Portnumber , u8 Copyu8Value);
void DIO_voidSetPortDirection(u8 Copy_u8Portnumber , u8 Copyu8Direction);
u8 DIO_voidGetPortValue(u8 Copy_u8Portnumber);

#endif
