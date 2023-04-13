#include <stdio.h>
#define WIERSZE 3
#define KOLUMNY 5
//prototyp funkcji podwajajacej wartosci w tablicy za pomocą notacji tablicowej
void podwoj_wart(int tab1[][KOLUMNY], int wiersze, int kolumny);
//prototyp funkcji wyswietlającej tabele
void wyswietl_tab(int wiersze, int kolumny, int tab1[][KOLUMNY]);


int main(void)
{
    int zrodlo[WIERSZE][KOLUMNY] = 
    {
        {1, 3, 33, 4, 12},
        {0, 5, 23, 1, 11},
        {34, 6, 129, 1, 6}
    };
   
    wyswietl_tab(WIERSZE,KOLUMNY,zrodlo);
    podwoj_wart(zrodlo,WIERSZE,KOLUMNY);
    wyswietl_tab(WIERSZE,KOLUMNY,zrodlo);

    return 0;
}
void podwoj_wart(int tab1[][KOLUMNY], int wiersze, int kolumny)
{
    int i,j;

    for (i = 0; i < wiersze; i++)
    {
        for (j = 0; j < kolumny ; j++)
        {
            tab1[i][j] *= 2;
            
        }
    }
}


void wyswietl_tab(int wiersze, int kolumny, int tab1[][KOLUMNY])
{
    int i, j;

    for (i = 0; i < wiersze ; i++)
    {
        for (j = 0; j < kolumny; j++)
            printf("%10d", tab1[i][j]);
        printf("\n");
    }
}
