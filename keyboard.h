/* 
 * File:   keyboard.h
 * Author: Alexandre Marques
 *
 * Created on 24 de Abril de 2017, 00:15
 */

#ifndef KEYBOARD_H
#define	KEYBOARD_H

#define _XTAL_FREQ 48000000 
#include <xc.h>
#include "lcd.h"

const char keyboard_map[][4] = 
{   {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}      
};

extern unsigned char get_kb( void );

#endif