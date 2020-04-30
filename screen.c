#include "screen.h"

void delay(void)
{
    int i;
    
    for( i = 0; i < 5; i++ )
    {
        __delay_ms(1000);
    }
}

void screen_a( char *string )
{
    lcd_clear();
    lcd_write_str("SISTEMA VOTACAO");
    lcd_set_cursor(2, 0);
    lcd_write_str("ENTRE SEU CODIGO");
    
    int i;
    
    for( i = 0; i < 6; i++ )
    {
        string[i] = get_kb();
    }
        string[i] = '\0';
}

void screen_b( char *string )
{
    int i;
    
    lcd_clear();
    lcd_write_str("VOTACAO ABERTA");
    lcd_set_cursor(2, 0);
    lcd_cursor(PISC);
    
    for( i = 0; i < 6; i++ )
    {
        string[i] = get_kb();
        lcd_write_data(string[i]);
    }
    
    string[i] = '\0';
    lcd_cursor( CLOAK );
}
    
int screen_c( char *string )
{
    char var = 0;
    
    lcd_clear();
    lcd_write_str(string);
    lcd_set_cursor(2, 0);
    lcd_write_str("#CANCEL *CONFIRM");
    
    do
    {
        var = get_kb();
    }
    
    while((var!='#') && (var!='*'));
    
    if(var == '*') return (1);
    
    else return (0);
}

void screen_d( void )
{
    lcd_clear();
    lcd_write_str("VOTO REGISTRADO");
    delay();
}

void screen_error( int error )
{
    lcd_clear();
    lcd_cursor( CLOAK );
    
    if( error == 1 )
    {
        lcd_write_str("CODIGO INVALIDO");
        lcd_set_cursor(2, 0);
        lcd_write_str("VOTACAO FECHADA");
        delay();
    }
    
    if( error == 2 )
    {
        lcd_write_str("USUARIO JA VOTOU");
        lcd_set_cursor(2, 0);
        lcd_write_str("VOTACAO FECHADA");
        delay();
    }
    
    if( error == 3)
    {
        lcd_write_str("VOTO CANCELADO");
        delay();
    }
    
    if( error == 4)
    {
        lcd_write_str("TEMPO EXCEDIDO");
        lcd_set_cursor(2, 0);
        lcd_write_str("VOTACAO FECHADA");
        delay();
    }
}

int screen_owner( void )
{
    int var;
    
    lcd_clear();
    lcd_write_str("ADMINISTRADOR");
    lcd_set_cursor(2, 0);
    lcd_write_str("#ZERA *APURACAO");
    
    do
    {
        var = get_kb();
    }
    
    while((var!='#') && (var!='*'));
    
    if(var == '*') return (1);
    
    else return (0);
}

void screen_owner_root( void )
{
    lcd_clear();
    lcd_write_str("VOTACAO ZERADA");
    delay();
}

void screen_owner_super( char *president, char *vice_president )
{
    lcd_clear();
    lcd_write_str("REPRESENT:");
    lcd_write_str(president);
    lcd_set_cursor(2, 0);
    lcd_write_str("VICE-REPR:");
    lcd_write_str(vice_president);
    get_kb();
}