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
//    int num = 1 + rand() % 6;
    char *start = "Push bu";
    char *end = "tton";
    
    while (1) {
        Lcd_Clear();
        Lcd_Set_Cursor(1, 1);
        Lcd_Write_String(end);
//        if(BUTTON) {
//            num = 1 + rand() % 6;
//        }
//        Lcd_Clear();
        //Lcd_Set_Cursor(1, 1);
        Lcd_Shift_Right();
        Lcd_Shift_Right();
        Lcd_Shift_Right();
        Lcd_Shift_Right();
        Lcd_Shift_Right();
        Lcd_Shift_Right();
        Lcd_Shift_Right();
        Lcd_Shift_Right();
        Lcd_Write_String(start);
        //Lcd_Write_Int(num);
        
        
        
    }
}
