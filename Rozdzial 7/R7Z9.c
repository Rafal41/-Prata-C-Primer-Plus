// program znajduje liczby pierwsze bazując na sicie Erastotenesa
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    
    unsigned int granica, mnoznik, i, j;
    
    printf("Ten program wyświetla wszystkie liczby pierwsze z danego przedziału\n");
    printf("Podaj dodatnią liczbę całkowitą\n");
    scanf("%u", &granica);

     // stworzenie tablicy wypelnionej wartosciami
     bool tablica[granica];

     tablica[0] = false;
     tablica[1] = false; 
     for (i = 2; i < granica; i++)
          tablica[i] = true;

     // znajdywanie liczb pierwszych
     for ( i = 2; (i*i) <= granica; i++)
     {
          if (tablica[i] == true)
          {
               for (mnoznik = 2, j=1; j <= granica ; mnoznik++)
               {
                    j = i*mnoznik;
                    tablica[j] = false;
               }
          }
     }
     //wyswietlanie liczb pierwszych
     printf("liczby pierwsze zawarte w przedziale od 2 do %u to \n", granica);
     for ( i = 2; i <= granica; i++)
     {
          if (tablica[i] == true)
               printf("%u ", i);
     }
    return 0;
}