//program podaje liczby z przedzialu
#include <stdio.h>

int main(void)                     
{
       int liczba, warunek;

       printf("Podaj liczbę całkowitą\n");
       scanf("%d", &liczba);
       warunek = liczba + 10; 
       
       while (liczba <= warunek)
       printf("%5d ", liczba++);

       return 0;
}
