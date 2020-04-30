/* 
 * File:   screen.h
 * Author: Alexandre Marques
 *
 * Created on 24 de Abril de 2017, 00:15
 */

#ifndef SCREEN_H
#define	SCREEN_H

#include <xc.h>
#include "lcd.h"
#include "keyboard.h"

void screen_a( char *string );
void screen_b( char *string );
int screen_c( char *string );
void screen_d( void );
void screen_error( int error );
int screen_owner( void );
void screen_owner_root( void );
void screen_owner_super( char *president, char *vice_president );

#endif

