#pragma config  FOSC = XT
#pragma config  WDTE = OFF
#pragma config  PWRTE = ON
#pragma config  CP = OFF

#define _XTAL_FREQ  4000000

#define BUTTON PORTAbits.RA3

#include "lcd.h"
#include <xc.h>

int SplitText(char Instruction[]) //Function to remove the first 8 chaacters of a string
{
    int i;
    int k = 9;
    char Instruction[] = "Push button to generate a random number";
    char SecondPart[100]; //Another empty character array
    char RightText[100];
    for (int i = 0; i < 50; i++)
    {
        SecondPart[i] = Instruction[k];
        k++;
    }
    strncpy(RightText, SecondPart, 50);
    RightText[50] = "\0";
    return RightText;
}

void main() {
    TRISA = 0xFF;
    TRISB = 0x00;

    RW = 0;

    Lcd_Init();
    int num = 1 + rand() % 6; //generate a random number between 1 & 6

    char Instruction[] = "Push button to generate a random number";
    char LeftText[100]; //Emptry character array of size 100
    strncpy(LeftText, Instruction, 50); //convert 'Instruction' into a string called 'LeftText'==!=
    LeftText[50] = '\0';
    char *RightText = SplitText(Instruction); //Call function 'SplitText' 

    Lcd_Set_Cursor(1, 1); //First 8 parts of LCD
    Lcd_Write_String(LeftText); 
    Lcd_Set_Cursor(2, 1); //Seocnd 8 parts of LCDpp
    Lcd_Write_String(RightText); p

//need to write it so that it stays on the number until the button is pressed again...
    while (1) {
        Lcd_Shift_Left();
        if(BUTTON) 
        {
            num = 1 + rand() % 6;
            Lcd_Write_Int(num);
        }        
    }
}


