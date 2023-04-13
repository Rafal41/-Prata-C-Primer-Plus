//buty2.c -- oblicza dlugosc stopy dla kilku numerow buta
#include <stdio.h>
#define KOREKTA -1 //stała
int main(void)                     
{
       const double MNOZNIK = 0.666666; // drugi rodzaj stałej
       double but, stopa;
       
       printf("Rozmiar buta       Długosc stopy\n");
       but = 24.0 ;
       while (but<45) // początek pętli while
       {                    // początek bloku
              stopa = MNOZNIK * but + KOREKTA;
              printf("%8.1f %17.2f cm \n", but, stopa);
              but = but + 1;
       }             //koniec bloku

       printf("Jezeli but pasuje, nos go");
       return 0;
}
