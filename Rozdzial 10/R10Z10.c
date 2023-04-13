#include <stdio.h>

//prototyp funkcji tworzącej tablice jako sumę elementów dwóch innych tablic
void tworz_tab(int tab1[], int tab2[], int tab3[], int rozmiar);
//prototyp funkcji wyswietlajacej tablice
void wyswietl_tab(int rozmiar, int tab1[]);

int main(void)
{
    int i,j;
    int tablica1[4] = {2, 4, 5, 8};
    int tablica2[4] = {1, 0, 4, 6};
    int tablica3[4];
    
    //kopiowanie tablicy
    tworz_tab(tablica1, tablica2, tablica3, 4);

    wyswietl_tab(4, tablica1);
    wyswietl_tab(4, tablica2);
    wyswietl_tab(4, tablica3);
   
    return 0;
}


void tworz_tab(int tab1[], int tab2[], int tab3[], int rozmiar)
{
    int i;

    for (i = 0; i < rozmiar; i++)
    {
        tab3[i] = tab1[i] + tab2[i];
    }
}


void wyswietl_tab(int rozmiar, int tab1[])
{
    int i;

    for (i = 0; i < rozmiar ; i++)
        printf("%10d", tab1[i]);
    printf("\n");
}
