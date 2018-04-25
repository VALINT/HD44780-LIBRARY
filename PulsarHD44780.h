 /* "PULSAR library"
 *
 * Author: VAL
 * Created: 12.02.2018 13:04:21
 * Version: 1.3
 *
 * V 1.0
 * This is a simplified library needed for managing the display 
 * with a HD44780 controller via one wire. Works only in 4-bit mode. 
 * One-wire control is implemented using the shift register SN74HC595. 
 * In theory, you can using SN74HC164, but I didn't check it.
 *
 * V 1.1
 * I modified the library to work with SN74HC164.
 *
 * V 1.2
 * Added support of Cyrillic alphabet.
 *
 * V 1.3
 * Added support of 4-bits and 8-bits work modes.
 */ 


#ifndef PULSARHD44780_H_
#define PULSARHD44780_H_

#define F_CPU 8000000Ul


#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <stdlib.h>

// Below, you can select the desired mode of operation.
//- Work on one wire (using a shift register SN74HC595)
//- Work on two wires (using a shift register SN74HC164)
//- Standard 4-bit mode
//- standard 8-bit mode

//You also need to select the output that will be used to control the LCD. Output can be selected on any ports and in any order. 

//---------------------------------------------------------------------------------------
// Select mode
// #define USE_ONE_WIRE_MODE
// #define USE_FOUR_BIT_MODE
// #define USE_EIGHT_BIT_MODE
#define USE_FOUR_BIT_MODE
//---------------------------------------------------------------------------------------
// Uncomment this definition if you need to use shift register SN74HC164 or his analog.
#define USE_SN74HC164
//---------------------------------------------------------------------------------------
// In this case you can select the PORT and PIN to be used for data transfer.
#define DATAPIN			0
#define DATAPORT		PORTD
#define DATADDR			DDRD
// In this case you can select the PORT and PIN to be used for strobe.
// Only for shift register SN74HC164 or his analog.
#define EPIN			2
#define EPORT			PORTB
#define EDDR			DDRB
// If you need using 4-bit mode select above and below.
#define RSPIN			0
#define RSPORT			PORTB
#define	RSDDR			DDRB

#define RWPIN			1
#define	RWPORT			PORTB
#define	RWDDR			DDRB

#define D7PIN			7
#define	D7PORT			PORTD
#define	D7DDR			DDRD

#define D6PIN			6
#define	D6PORT			PORTD
#define	D6DDR			DDRD

#define D5PIN			5
#define	D5PORT			PORTD
#define	D5DDR			DDRD

#define D4PIN			4
#define	D4PORT			PORTD
#define	D4DDR			DDRD
// If you need using 8-bit mode.
#define D3PIN			3
#define	D3PORT			PORTD
#define	D3DDR			DDRD

#define D2PIN			2
#define	D2PORT			PORTD
#define	D2DDR			DDRD

#define D1PIN			1
#define	D1PORT			PORTD
#define	D1DDR			DDRD

#define D0PIN			0
#define	D0PORT			PORTD
#define	D0DDR			DDRD
//---------------------------------------------------------------------------------------
// You can variate this delay for faster or most stability work
#define STROBE_DELAY_MS 50

//---------------------------------------------------------------------------------------
// Definitions for using in functions
#define COMMAND			0x00
#define DATA			0x01

#define CURSOR_OFF		0x00
#define CURSOR_ON		0x02
#define CURSOR_BLINK	0x03

#define DISPLAY_OFF		0x00
#define DISPLAY_ON		0x04

#define SCROLL_LEFT		0x00
#define SCROLL_RIGHT	0x04
//----------------------------------------------------------------------------------------
//	Sets cursor on desired position.
		void LCD_GotoXY(uint8_t line, uint8_t coloum);
	
//	Scrolls the visible part in the desired direction and on the required number of characters
//	void LCD_Scroll(1, SCROLL_LEFT);
		void LCD_Scroll(uint8_t number, uint8_t dir);
	
//	Sent text data in the LCD
		void LCD_SentLine(char line[],uint8_t lon);
	
//	Sent data byte or command in the LCD
//	LCD_SentByte(data_byte,DATA)
//	LCD_SentByte(aommand_number,COMMAND)
		void LCD_SentByte(uint8_t byte,bool rs);
	
//	Sent data byte in the LCD (analog LCD_SentByte(data_byte,DATA))
		void LCD_SentChar(uint8_t data);
		
//	Sets desired cursor mode
//	LCD_Cursor(CURSOR_BLINK);
		void LCD_Cursor(uint8_t cursor);
		
//	You can turn on LCD or turn off his
//	LCD_State(DISPLAY_ON);
		void LCD_State(uint8_t state);
		
// This function initializations LCD		
		void LCD_Initial(void);
		
// This function clears LCD		
		void LCD_Clear(void);

		

#endif /* PULSARHD44780_H_ */