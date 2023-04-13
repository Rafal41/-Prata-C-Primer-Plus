#include <stdio.h>
#include <string.h>
int main()                     
{
       
       float predkosc;
       float rozmiar;
       float czas;
       printf("Podaj predkosc pobierania w Mb/s\n");
       scanf("%f", &predkosc);
       printf("Podaj rozmiar pliku do pobrania [w megabajtach]\n");
       scanf("%f", &rozmiar);

       czas = rozmiar*8/predkosc;
       printf("Przy %.2f megabitów na sekunde plik o rozmiarze %.2f megabajta \n"
              "zostanie pobrany w %.2f sekundy", predkosc , rozmiar, czas);
      
       return 0;
}
