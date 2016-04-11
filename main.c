#pragma config  FOSC = XT
#pragma config  WDTE = OFF
#pragma config  PWRTE = ON
#pragma config  CP = OFF

#define _XTAL_FREQ  4000000

#include "lcd.h"
#include <xc.h>


void main() {
//    unsigned int counter = 0;
    TRISB = 0x00;
    char *name = "MikeLaur";
    
    RW = 0;
    
    Lcd_Init();
    
    while(1) {
        Lcd_Clear();
        Lcd_Set_Cursor(1,1);
        
        Lcd_Write_String(name);
        
//        Lcd_Write_Int(counter);
//        __delay_ms(10);
//        counter++;
//        RW = 0;
//        EN = 1;
//        D5 = 1;
//        __delay_ms(500);
//        RW = 1;
//        __delay_ms(500);
    }
}
