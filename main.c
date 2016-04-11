#pragma config  FOSC = XT
#pragma config  WDTE = OFF
#pragma config  PWRTE = ON
#pragma config  CP = OFF

#define _XTAL_FREQ  4000000

#define BUTTON PORTAbits.RA3

#include "lcd.h"
#include <xc.h>

void main() {
    TRISA = 0xFF;
    TRISB = 0x00;

    RW = 0;

    Lcd_Init();
    int num = 1 + rand() % 6;
    
    while (1) {
        
        if(BUTTON) {
            num = 1 + rand() % 6;
        }
        Lcd_Clear();
        Lcd_Set_Cursor(1, 1);
//            
        Lcd_Write_Int(num);
        
    }
}
