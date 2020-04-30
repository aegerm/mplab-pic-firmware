#include "lcd.h"

void set_value( int value )
{
    TRISCbits.RC6 = 0;
    TRISCbits.RC7 = 0;
    
    if( value == 0 )
    {
        LATCbits.LC6 = 0;
        LATCbits.LC7 = 0;
        TRISB = 0XF0;
        LATB = 0X00;
    }
    
    if( value == 1 )
    {
        LATCbits.LC6 = 1;
        LATCbits.LC7 = 0;
        TRISB = 0X00;
        LATB = 0X00;
    }
    
    if( value == 3 )
    {
        TRISB = 0X00;
        LATB = 0X00;
        TRISCbits.RC1 = 0;
        TRISAbits.RA5 = 0;
        LATCbits.LC6 = 1;
        LATCbits.LC7 = 1;
    }
}

void send( void )
{
    LCD_EN = 1;
    __delay_us(5);
    LCD_EN = 0;
}

void lcd_clear( void )
{
    set_value(LCD);
    LCD_RS = 0;
    LATB = 0x01;
    send();    
    __delay_ms(2);
}

void lcd_write_cmd( unsigned int command )
{
    LCD_RS = 0;
    LATB = command;
    send();
    __delay_us(41);
}

void lcd_write_data( unsigned int data )
{
    if( data )
    {
        set_value(LCD);
        LCD_RS = 1;
        LATB = data;
        send();
        __delay_us(41);
    }
}

void lcd_set_cursor( unsigned int row, unsigned int col )
{
    set_value(LCD);
    
    if( row == 1 )
    {
       lcd_write_cmd( 0x80 | col );
    }
    
    else 
    {
        lcd_write_cmd( 0x80 | ( 0X40 | col ) );
    }
}

void lcd_cursor( unsigned short int state )
{
     set_value(LCD);
    if( state == PISC )
    {
        lcd_write_cmd( 0x0F );
    }
     
    else
    {
        lcd_write_cmd( 0X0C );
    }
}

void lcd_init( void )
{
     set_value(LCD);
    __delay_ms(20);
    set_value(LCD);     
    LCD_RS = 0;       
    
    LATB = 0X30; 
    send();            
    __delay_ms(5);
    
    LATB = 0X30;
    send();             
    __delay_us(100);
    
    LATB = 0X30;
    send();             
    __delay_us(41);
    
    lcd_write_cmd(0x38);
    
    lcd_write_cmd(0x08);
    
    lcd_clear();        
    
    lcd_write_cmd(0x06);
    
    lcd_write_cmd(0x0C);
}

void lcd_write_str( unsigned char *string )
{
    set_value(LCD);
    
    for( int i=0; string[i]!='\0'; i++ )
    {
        lcd_write_data( string[i] );
    }
}
