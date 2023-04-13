#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ROZMIAR 5
#define SPRAWDZAM

void inicjujtab(int tab[]);
bool szukpoz(int tab[], int liczba, int ilosc);
void sortuj(int tab[]);
int znajdz(int tab[], int liczba, int num);
int porownaj(int val, int num);
int main (void)
{
    int tablica[ROZMIAR];
    int szuk;


    srand((unsigned int) time(0));
    inicjujtab(tablica);

#ifdef SPRAWDZAM
    for (int i = 0; i < ROZMIAR; i++)
        printf("pozycja i = %d : %d\n", i, tablica[i]);
    putchar('\n');
#endif

    sortuj(tablica);
    
#ifdef SPRAWDZAM
    for (int i = 0; i < ROZMIAR; i++)
        printf("pozycja i = %d : %d\n", i, tablica[i]);
#endif
    puts("Podaj liczbe calkowitą jaką chcesz znaleźć");
    while (scanf("%d", &szuk) == 1)
    {
        if (znajdz(tablica, ROZMIAR, szuk))
            puts("Znaleziono wskazaną liczbę w zbiorze liczb");
        else
            puts("Wskazanej liczby nie ma w tym zbiorze liczb");

        puts("Podaj nastepna liczbe calkowitą jaką chcesz znaleźć. q konczy");
    }

    return 0;
}

void inicjujtab(int tab[])
{
    int liczba;
   

    for (int i = 0; i < ROZMIAR; i++)
    {
        liczba = rand() % 20 + 1;
        while (szukpoz(tab, liczba, i))
        {
            liczba = rand() % 20 + 1;
        }
        tab[i] = liczba; 
    }   

}

bool szukpoz(int tab[], int liczba, int ilosc)
{
    for (int i = 0; i < ilosc; i++)
    {
        if (tab[i] == liczba)
            return true;
    }
    return false;
}

void sortuj(int tab[])
{
    int dol, szuk;
    int temp;

    for (dol = 0; dol < ROZMIAR - 1; dol++)
        for (szuk = dol + 1; szuk < ROZMIAR; szuk++)
            if (tab[dol] > tab[szuk])
            {
                temp = tab[dol];
                tab[dol] = tab[szuk];
                tab[szuk] = temp;
            }


}

int znajdz(int tab[], int liczba, int num)
{
    int currentpos;
    int dol, gora;
    int wynik;
    
    dol = 0;
    gora = liczba - 1;
    currentpos = (gora + dol)/2;
    
    while (dol < gora)
    {
        wynik = porownaj(tab[currentpos], num);
        if (wynik == 0)
            return 1;
        else if (wynik == 1)
        {  
            dol = currentpos + 1;
            currentpos = (gora + dol)/2;
        }
        else
        {
            gora = currentpos - 1;
            currentpos = (gora + dol)/2 ;
        }
    }

    if (tab[dol] == num)
        return 1;
        
    return 0;
}


int porownaj(int val, int num)
{
    if (num == val)
        return 0;
    else if (num > val)
        return 1;
    else 
        return -1;

}