#include <xc.h>
#include "eeprom.h"

unsigned char eprom_read( unsigned int address )
{
    EEADR = address; //bits mais baixos do endere�o
    EECON1bits.EEPGD = 0; //acessa EEPROM externa
    EECON1bits.CFGS = 0; //acessa EEPROM externa ou flash
    EECON1bits.RD = 1; //ativa leitura
    return(EEDATA); //valores dado mem�ria
}

void eprom_write( unsigned int address, unsigned long int data )
{
    unsigned int gie = 0;
    EEADR = address;
    EEDATA = data;
    EECON1bits.EEPGD = 0;
    EECON1bits.CFGS = 0;
    EECON1bits.WREN = 1; //permite ciclos de escrita
    if(INTCONbits.GIE)
    {
        INTCONbits.GIE = 0; //desativa interrup��es
        gie = 1;
    }
    
    EECON2 = 0X55;
    EECON2 = 0XAA;
    EECON1bits.WR = 1;
       
    if( gie )
    {
        INTCONbits.GIE = 1; //ativa interrup��es
    }
    
    while( EECON1bits.WR );
    EECON1bits.WREN = 0; //desativa escrita
}

