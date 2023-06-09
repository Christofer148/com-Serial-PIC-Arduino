/*
fuente comunicacion serial:
https://controlautomaticoeducacion.com/microcontroladores-pic/16-comunicacion-serial-con-pic/
*/

#include <16f877a.h>
#fuses XT, NOWDT, NOPROTECT, PUT, NOBROWNOUT, NOLVP
#use delay (clock = 8000000)
#USE RS232(BAUD=9600, XMIT=PIN_C6, RCV=PIN_C7)

#use standard_io(b)
#use standard_io(a)
#define btn pin_A0

unsigned int contador;
int btnActivado = 0;

void main()
{
   contador = 0;
   
   while (true) 
   {
      if(input(btn)){                  // validamos si el boton esta presionado
         if(btnActivado){              // validamos si es la primera vez que se va a sumar
                                       // como ya se sumo una vez ya no debe de sumar
         }else{                        // si no se ha sumado por primera vez se activa
            delay_ms(20);              // hacemos delay para que no haya rebotes
            if(contador == 255){       // definimos como m�ximo 255 al valor contador
               contador = 0;
            }else{                     // si no ha llegado al m�ximo sumamos 1
               contador++;
            }
            btnActivado = 1;           // indicamos que el boton ya ha sumado 1 vez
         }
      }else{
         btnActivado = 0;              // en caso que no est� presionado el bot�n se declara como que no ha sumado
      }
      PUTC(contador);                  // imprime a trav�s del serial la variable contador
   }
}
