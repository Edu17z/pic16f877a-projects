/*
 * File:   ChaveLed.c
 * Author: Roderval
 *
 * Created on 30 de Mar?o de 2020, 14:42
 */

#include <xc.h>          //***inclus?o da biblioteca do compilador
#include <pic16f877a.h>  //***inclus?o da biblioteca do chip espec?fico
#include <stdio.h>       //***inclus?o da biblioteca standard padr?o "C"


#define _XTAL_FREQ 4000000 //***Defini a frequencia do clock, 4Mhz neste caso

__bit led;   // vari?rvel led para receber o valor l?gico do bot?o
             // tipo de dados bit precisa ser global ou static
int valor;
void main(void) 
{
  // static __bit led;   // tipo de dados bit precisa ser global ou 
                         // static para ser local. Static fica local na mem?ria
   TRISB = 0b00000000;    //***configurando a porta B como sa?da
   PORTB = 0;             //*** inicializando port B com 0V em todos pinos
   TRISD = 0b11111111;    //*** configurando port C como entrada, todos pinos
                        
   while (1)
   {
       led = PORTDbits.RD1;
       
       if (led == 0)
           PORTBbits.RB0 = 1; //acende led
       else
           PORTBbits.RB0 = 0; //apaga led
    
           
   }
 }