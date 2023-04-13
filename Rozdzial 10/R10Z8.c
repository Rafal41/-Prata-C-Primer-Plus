#include <stdio.h>

//prototyp funkcji kopiującej dane za pomocą notacji tablicowej
void kopiuj_tab(double tab1[], double tab2[], int n);
//prototyp funkcji kopiującej dane za pomocą notacji wskaznikowej
void kopiuj_wsk(double tab1[], double tab2[], int n);


int main(void)
{
    int i;
    double zrodlo[7] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    double cel1[3];
    double cel2[3];

    kopiuj_tab(&zrodlo[2], cel1, 3);
    for (i = 0; i < 3 ; i++)
        printf("%10.2f", cel1[i]);
    printf("\n");

    kopiuj_wsk(&zrodlo[2], cel2, 5);
    for (i = 0; i < 3 ; i++)
        printf("%10.2f", cel2[i]);
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
