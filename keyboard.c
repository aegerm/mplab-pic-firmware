#include "keyboard.h"

char run( void )
{
    int i = 0x00;
    int j = 0x00;
    int out = 0X01;
    int in = 0x10;
    
    for( i = 0; i < 4; i++ )
    {   
        if( PORTB & in ) break;
        
        LATB = out;  
        out<<=1;
        in = 0x10;
        
        for( j = 0; (( j < 4 )); j++ )
        {
            if( PORTB & in )
            {
                __delay_ms(5);
                if(PORTB && in)break;
            }
            
            in <<= 1;
        }      
    }
    
    if( (i == 4) && (j==4) )
    {
        return (0);
    }
    
    return( keyboard_map[i-1][j] );
}

unsigned char get_kb( void )
{
    set_value(KEYB);
    
    unsigned char buf;
    
    do
    {
        buf = run();
    }
    
    while( !buf );
    
    while( run() );
    
    return ( buf );
}
