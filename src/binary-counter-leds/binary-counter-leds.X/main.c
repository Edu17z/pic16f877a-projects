#include <xc.h>
#include <pic16f877a.h>  //***inclus?o da biblioteca do chip espec?fico
#include <stdio.h>
#define _XTAL_FREQ 4000000

// NOTE: To use the macros below, YOU must have previously defined _XTAL_FREQ
//#define __delay_us(x) _delay((unsigned long)((x)*(_XTAL_FREQ/4000000.0)))
//#define __delay_ms(x) _delay((unsigned long)((x)*(_XTAL_FREQ/4000.0)))

void main(void) {
                  //76543210
    TRISB   = 0b00000000;
    PORTB = 0b00000000;
    
    while(1){
        
        //PORTBbits.RB0 = 1;
        //__delay_ms(1000);
        //PORTBbits.RB0 = 0;
        //__delay_ms(1000);   
  
        PORTB++;
        __delay_ms(500);
    }
}

