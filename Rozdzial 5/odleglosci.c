//odleglosci.c -- przelicza kilometry na mile
#include <stdio.h>
#define KOREKTA 0 //stała
int main(void)                     
{
       const double MNOZNIK = 0.6214; // drugi rodzaj stałej
       double kilometry, mile;
       
       printf("Rozmiar buta       Długosc stopy\n");
       kilometry = 1 ;
       while (kilometry<=100) // początek pętli while
       {                    // początek bloku
              mile = MNOZNIK * kilometry + KOREKTA;
              printf("%8.1f %17.2f\n", kilometry, mile);
              kilometry = kilometry + 1;
       }             //koniec bloku

       printf("I elo");
       return 0;
}
