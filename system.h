/* 
 * File:   system.h
 * Author: Alexandre Marques
 *
 * Created on 24 de Abril de 2017, 00:16
 */

#ifndef SYSTEM_H
#define	SYSTEM_H

#pragma config PLLDIV = 5     
#pragma config CPUDIV = OSC1_PLL2
#pragma config USBDIV = 1

#pragma config FOSC = HSPLL_HS  
#pragma config FCMEN = OFF      
#pragma config IESO = OFF       

#pragma config PWRT = ON       
#pragma config BOR = ON        
#pragma config BORV = 3         
#pragma config VREGEN = OFF     

#pragma config WDT = OFF        
#pragma config WDTPS = 32768    

#pragma config CCP2MX = OFF     
#pragma config PBADEN = OFF     
#pragma config LPT1OSC = OFF    
#pragma config MCLRE = ON       

#pragma config STVREN = ON     
#pragma config LVP = OFF         
#pragma config XINST = OFF      

#pragma config CP0 = OFF        
#pragma config CP1 = OFF        
#pragma config CP2 = OFF        
#pragma config CP3 = OFF        

#pragma config CPB = OFF        
#pragma config CPD = OFF        

#pragma config WRT0 = OFF       
#pragma config WRT1 = OFF       
#pragma config WRT2 = OFF       
#pragma config WRT3 = OFF      

#pragma config WRTC = OFF       
#pragma config WRTB = OFF       
#pragma config WRTD = OFF       

#pragma config EBTR0 = OFF      
#pragma config EBTR1 = OFF     
#pragma config EBTR2 = OFF      
#pragma config EBTR3 = OFF     

#pragma config EBTRB = OFF      

#include <xc.h>
#define _XTAL_FREQ 48000000 
#include "lcd.h"
#include "keyboard.h"
#include "eeprom.h"
#include "students.h"
#include "screen.h"
#include <string.h>

int time_delay = 60;
char owner[] = "DBA000";

#endif

