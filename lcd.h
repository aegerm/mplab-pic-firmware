/* 
 * File:   lcd.h
 * Author: Alexandre Marques
 *
 * Created on 24 de Abril de 2017, 00:14
 */

#ifndef LCD_H
#define	LCD_H

#include <xc.h>

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 48000000 
#endif

#define LCD 3
#define LEDS 1
#define KEYB 0

#define LCD_RS  LATCbits.LC1
#define LCD_EN  LATAbits.LA5
#define PISC   1
#define CLOAK  0

extern void set_value( int value );
void send( void );
extern void lcd_clear( void );
void lcd_write_comand( unsigned int command );
void lcd_write_data( unsigned int data );
extern void lcd_set_cursor( unsigned int row, unsigned int col );
void lcd_cursor( unsigned short int state );
extern void lcd_init( void );
void lcd_write_str( unsigned char *string );

#endif
