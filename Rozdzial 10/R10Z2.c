#include <stdio.h>

//prototyp funkcji kopiującej dane za pomocą notacji tablicowej
void kopiuj_tab(double tab1[], double tab2[], int n);
//prototyp funkcji kopiującej dane za pomocą notacji wskaznikowej
void kopiuj_wsk(double tab1[], double tab2[], int n);
//??
void kopiuj_wsk2(double tab1[], double tab2[], double *wsk);

int main(void)
{
    int i;
    double zrodlo[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double cel1[5];
    double cel2[5];
    double cel3[5];
    kopiuj_tab(zrodlo, cel1, 5);
    for (i = 0; i < 5 ; i++)
        printf("%10.2f", cel1[i]);
    printf("\n");

    kopiuj_wsk(zrodlo, cel2, 5);
    for (i = 0; i < 5 ; i++)
        printf("%10.2f", cel2[i]);
    printf("\n");

    kopiuj_wsk2(zrodlo, cel3, zrodlo + 5);
    for (i = 0; i < 5 ; i++)
        printf("%10.2f", cel3[i]);
    printf("\n");
   
    return 0;
}
void kopiuj_tab(double tab1[], double tab2[], int n)
{
    int i;

    for (i = 0; i < n ; i++)
    {
        tab2[i] = tab1[i];
        //printf("%10.2f", tab2[i]);
    }
    //printf("\n");
}

void kopiuj_wsk(double tab1[], double tab2[], int n)
{
    int i;

    for (i = 0; i < n ; i++)
    {
        *(tab2 + i) = *(tab1 + i);
        //printf("%10.2f", *(tab2 + i));
    }
    //printf("\n");
}

void kopiuj_wsk2(double tab1[], double tab2[], double *wsk)
{
    int i;
    double *m;

    for (i = 0, m = tab1; m < wsk ; i++, m++)
    {
        *(tab2 + i) = *(tab1 + i);
        //printf("%10.2f", *(tab2 + i));
    }
    //printf("\n");
}