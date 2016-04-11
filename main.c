#pragma config  FOSC = XT
#pragma config  WDTE = OFF
#pragma config  PWRTE = ON
#pragma config  CP = OFF

#define _XTAL_FREQ  4000000

#include "lcd.h"
#include <xc.h>


void main() {
    unsigned int counter = 0;
    TRISB = 0x00;
    //char *name = "Lauael";
    
    RW = 0;
    
    Lcd_Init();
    
    while(1) {
        //Lcd_Clear();
        Lcd_Set_Cursor(1,1);
        
        //Lcd_Write_String(name);
        
        Lcd_Write_Int(counter);
        __delay_ms(1000);
        counter++;
    }
    return;
}
