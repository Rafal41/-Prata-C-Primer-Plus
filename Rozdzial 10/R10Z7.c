#include <stdio.h>

//prototyp funkcji kopiującej dane za pomocą notacji tablicowej
void kopiuj_tab(double tab1[][5], double tab2[][5], int wiersze, int kolumny);
//prototyp funkcji kopiującej dane za pomocą notacji wskaźnikowej
void kopiuj_wsk(double tab1[][5], double tab2[][5], int wiersze, int kolumny);


int main(void)
{
    int i,j;
    double zrodlo[3][5] = 
    {
        {1.1, 2.2, 3.3, 4.4, 5.5},
        {2.0, 22.1, 3.33, 13.3, 0.5},
        {0.1, 12.3, 9.3, 4.4, 3.44}
    };
    double cel1[3][5];
    double cel2[3][5];

    kopiuj_tab(zrodlo, cel1, 3, 5);
    for (i = 0; i < 3 ; i++)
    {
        for (j = 0; j < 5; j++)
            printf("%10.2f", cel1[i][j]);
        printf("\n");
    }

    kopiuj_wsk(zrodlo, cel2, 3, 5);
    for (i = 0; i < 3 ; i++)
    {
        for (j = 0; j < 5; j++)
            printf("%10.2f", cel2[i][j]);
        printf("\n");
    }

    return 0;
}
void kopiuj_tab(double tab1[][5], double tab2[][5], int wiersze, int kolumny)
{
    int i,j;

    for (i = 0; i < wiersze; i++)
    {
        for (j = 0; j < kolumny ; j++)
        {
            tab2[i][j] = tab1[i][j];
            //printf("%10.2f", tab2[i][j]);
        }
        //printf("\n");
    }
}

void kopiuj_wsk(double tab1[][5], double tab2[][5], int wiersze, int kolumny)
{
    int i,j;

     for (i = 0; i < wiersze; i++)
    {
        for (j = 0; j < kolumny ; j++)
        {
            *(*(tab2 + i)+j) = *(*(tab1 + i)+j);
            //printf("%10.2f",  *(*(tab2 + i)+j));
        }
        //printf("\n");
    }

}
