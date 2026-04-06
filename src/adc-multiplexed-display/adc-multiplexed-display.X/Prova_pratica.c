
#pragma config FOSC = XT     // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <pic16f877a.h>
#define _XTAL_FREQ 20000000
#define EN1 RC0
#define EN2 RC1
#define EN3 RC2
#define EN4 RC3


int digital_value=0; 
int new_value=0;
unsigned int segments[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

void ADC_Init() 
{
    ADRESL = 0x00;
    ADRESH = 0x00;

    ADCON0bits.ADCS1 = 1;
    ADCON0bits.ADCS0 = 1;
    ADCON0bits.CHS2 = 1;
    ADCON0bits.CHS1 = 0;
    ADCON0bits.CHS0 = 0;
    ADCON0bits.GO_nDONE = 0; //ONLY TURN ON WHEN READING
    ADCON0bits.ADON = 1;

    ADCON1bits.ADFM = 1;
    ADCON1bits.ADCS2 = 0;
    ADCON1bits.ADFM = 1;
    ADCON1bits.PCFG3 = 0;
    ADCON1bits.PCFG2 = 0;
    ADCON1bits.PCFG1 = 0;
    ADCON1bits.PCFG0 = 0;

    PIR1bits.ADIF = 0;
}

void Int_Init() 
{
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    PIE1bits.ADIE = 1;
}

void ADC_Read() 
{
    ADCON0bits.GO_nDONE = 1; //INITIALIZE A/D CONVERTION
}

void Show_Display(int value) 
{
    int a, b, c, d, e, f, g, h;
   
    a=value%10;//4th digit is saved here

    b=value/10;

    c=b%10;//3rd digit is saved here

    d=b/10;

    e=d%10; //2nd digit is saved here
    
    f=d/10;

    g=f%10; //1st digit is saved here

    h=f/10;

    
    EN1 = 0;
    PORTD = segments[g];
    __delay_us(5000);
    EN1 = 1;

    EN2 = 0;
    PORTD = segments[e];
    PORTDbits.RD7=1;
    __delay_us(5000);
    EN2 = 1;

    EN3 = 0;
    PORTD = segments[c];
    __delay_us(5000);
    EN3 = 1;

    EN4 = 0;
    PORTD = segments[a];
    __delay_us(5000);
    EN4 = 1;

}

void __interrupt() TrataInt(void)
{    
  if (ADIF)  //foi a interrup??o de final de convers?o AD?
     {  
        PIR1bits.ADIF = 0; //reseta o flag da interrup??o 
        digital_value=((ADRESH<<8)+ADRESL);
        new_value =digital_value*48.8281;
        Show_Display(new_value);
        
  }
  return;
}

void main(void) {
    
    
    TRISD = 0x00;
    PORTA = 0xFF;
    PORTD = 0x00;
    TRISC = 0x00;
    PORTC = 0x00;
    
    ADC_Init();
    Int_Init();
    while (1) 
    {
        ADC_Read();
        __delay_ms(1);
        
    }



    return;
}
