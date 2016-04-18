#pragma config  FOSC = XT
#pragma config  WDTE = OFF
#pragma config  PWRTE = ON
#pragma config  CP = OFF

#define _XTAL_FREQ  4000000

#define BUTTON PORTAbits.RA3

#include "lcd.h"
#include <xc.h>
//#include <string.h>

//char* SplitText(char Instruction[]) //Function to remove the first 8 chaacters of a string
//{
////    int i;
//    int k = 9;
////    char Instruction[] = "Push button to generate a random number";
//    char SecondPart[16]; //Another empty character array
//    char RightText[16];
//    for (int i = 0; i < 15; i++)
//    {
//        SecondPart[i] = Instruction[k];
//        k++;
//    }
//    strncpy(RightText, SecondPart, 15);
//    RightText[15] = '\0';
//    return RightText;
//}

void main() {
    TRISA = 0xFF;
    TRISB = 0x00;

    RW = 0;

    Lcd_Init();; //generate a random number between 1 & 6

    char *Instruction =  "Push button to generate a random number \0";
    char *Instruction2 = "ton to generate a random number Push but\0";
    
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String(Instruction);
    Lcd_Set_Cursor(2,1);
    Lcd_Write_String(Instruction2);
    
    int run = 1;
    
    while (run)
    {
        __delay_ms(500);
        Lcd_Shift_Left();
        
        if(BUTTON) 
        {
            run = 0;
            int num = 1 + rand() % 6;
            Lcd_Clear();
            Lcd_Write_Int(num);
            __delay_ms(2000);
            Lcd_Clear();
        }        
    }
    
}

//    char LeftText[16]; //Empty character array of size 100
//    strncpy(LeftText, Instruction, 15); //convert 'Instruction' into a string called 'LeftText'==!=
//    LeftText[15] = '\0';
//    char *RightText = SplitText(Instruction); //Call function 'SplitText' 
//
//    Lcd_Set_Cursor(1, 1); //First 8 parts of LCD
//    Lcd_Write_String(LeftText); 
//    Lcd_Set_Cursor(2, 1); //Second 8 parts of LCDpp
//    Lcd_Write_String(RightText); 
//
////need to write it so that it stays on the number until the button is pressed again...
