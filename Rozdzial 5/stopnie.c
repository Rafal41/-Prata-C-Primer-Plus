//stopnie.c -- przelicza stopnie Celsjusza na stopnie Farenheita
#include <stdio.h>
#define KOREKTA 32 //stała
int main(void)                     
{
       const double MNOZNIK = 1.8; // drugi rodzaj stałej
       double stopnieC, stopnieF;
       
       printf("Rozmiar buta       Długosc stopy\n");
       stopnieC = 0 ;
       while (stopnieC<=100) // początek pętli while
       {                    // początek bloku
              stopnieF = MNOZNIK * stopnieC + KOREKTA;
              printf("%8.1f %17.2f\n", stopnieC, stopnieF);
              stopnieC = stopnieC + 1;
       }             //koniec bloku

       printf("I elo");
       return 0;
}
