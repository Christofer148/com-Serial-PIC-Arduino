#include "16f877a.h"
#fuses XT, NOWDT, NOPROTECT, PUT, NOBROWNOUT, NOLVP
#use delay (clock=4000000)
#use rs232 (baud=9600, xmit=pin_c6, rcv=pin_c7)
#use standard_io(b)
#use standard_io(a)

void main()
{
char x;
while(true)
{
   getc();
   x=getc();
   
      if ((x=='a'))
      {
         printf("Dato a recibido \n\r");
         output_high(pin_b0);
         delay_ms(100);
         output_low(pin_b3);
         delay_ms(100);
      }
      else if ((x=='b'))
      {
         printf("Dato b recibido \n\r");
         output_low(pin_b0);
         delay_ms(100);
         output_high(pin_b3);
         delay_ms(100);
      }
}
}
