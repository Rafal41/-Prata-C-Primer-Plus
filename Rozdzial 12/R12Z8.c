#include <stdio.h>
#include <stdlib.h>
int * stworz_tablice (int elem, int wart);
void pokaz_tablice (const int tab[], int n);

int main (void)
{
    int * wt;
    int rozmiar;
    int wartosc;

    printf("Podaj liczbe elementow: ");
    while (scanf("%d", &rozmiar) == 1 && rozmiar > 0)
    {
        printf("Podaj wartosc początkową: ");
        scanf("%d", &wartosc);
        wt = stworz_tablice (rozmiar, wartosc);
        if (wt)
        {
            pokaz_tablice(wt, rozmiar);
            free(wt);
        }
        printf("Podaj liczbe elementow (<1 - koniec)");
    }
    puts("Koniec.");
    return 0;
}

int * stworz_tablice (int elem, int wart)
{
    int * wsk;

    wsk = (int *) malloc(elem * sizeof(int));
    for (int i = 0; i < elem ; i++)
        wsk[i] = wart;
    
    return wsk;
}

void pokaz_tablice (const int tab[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", tab[i]);
}