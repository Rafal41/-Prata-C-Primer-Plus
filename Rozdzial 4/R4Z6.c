#include <stdio.h>
#include <string.h>
int main()                     
{
       char imie[30];
       char nazwisko[30];
       int literyimie;
       int literynazwisko;
       printf("Podaj swoje imie i nazwisko\n");
       scanf("%s %s", imie, nazwisko);
      
       literyimie = strlen(imie);
       literynazwisko = strlen(nazwisko);
       //printf("%s %s \n", imie, nazwisko);
       printf("%*d %*d \n", literyimie,literyimie,literynazwisko, literynazwisko);
       printf("%-*d %-*d \n", literyimie,literyimie,literynazwisko, literynazwisko);
       return 0;
}
