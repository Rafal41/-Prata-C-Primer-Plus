#include <stdio.h>

//prototyp funkcji kopiującej dane za pomocą notacji tablicowej
void kopiuj_tab(int wiersze, int kolumny, double tab1[wiersze][kolumny], double tab2[wiersze][kolumny]);
//prototyp funkcji wyswietlającej tabele
void wyswietl_tab(int wiersze, int kolumny, double tab1[wiersze][kolumny]);

int main(void)
{
    int i,j;
    int a = 3; //ilosc wierszy
    int b = 5;  //ilosc kolumn
    double zrodlo[a][b]; //tablica VLA
    double cel1[a][b]; // docelowa tablica VLA

    //inicjalizacja tablicy VLA
    for (i = 0; i < a; i++)
    {
        for (j = 0; j < b; j++)
            zrodlo[i][j] = i*j + j;  
    } 

    //kopiowanie tablicy
    kopiuj_tab(a, b, zrodlo, cel1);
    wyswietl_tab(a, b, zrodlo);
    wyswietl_tab(a, b, cel1);
   
    return 0;
}


void kopiuj_tab(int wiersze, int kolumny, double tab1[wiersze][kolumny], double tab2[wiersze][kolumny])
{
    int i,j;

    for (i = 0; i < wiersze; i++)
    {
        for (j = 0; j < kolumny ; j++)
        {
            tab2[i][j] = tab1[i][j];
        }
    }
}


void wyswietl_tab(int wiersze, int kolumny, double tab1[wiersze][kolumny])
{
    int i, j;

    for (i = 0; i < wiersze ; i++)
    {
        for (j = 0; j < kolumny; j++)
            printf("%10.2lf", tab1[i][j]);
        printf("\n");
    }
}
