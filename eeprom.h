/* 
 * File:   eeprom.h
 * Author: Alexandre Marques
 *
 * Created on 24 de Abril de 2017, 00:14
 */

#ifndef EEPROM_H
#define	EEPROM_H
#define _XTAL_FREQ   48000000

unsigned char eprom_read( unsigned int address );
void eprom_write( unsigned int address, unsigned long int data );

#endif