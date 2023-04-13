//pszenica.c -- wzrost wykladniczy
#include <stdio.h>
#define POLA 64 
int main(void)                     
{
       const double PLON = 2E16; 
       double biezace, suma;
       int licznik = 1;

       printf("pole         dodane ziarna        suma ziaren        czesc rocznej\n");
       printf("                                                       produkcji swiatowej\n");
       suma = biezace = 1.0;
       printf("%-4d         %-13.2e        %-11.2e        %-25.2e \n",licznik,biezace, suma, suma/PLON);
       while (licznik<65) 
       {                   
              licznik = licznik +1;
              biezace = 2.0 * biezace;
              suma = suma + biezace;
              printf("%-4d         %-13.2e        %-11.2e        %-25.2e \n",licznik,biezace, suma, suma/PLON);             
       }             

       return 0;
}
