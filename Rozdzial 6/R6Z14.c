
#include <stdio.h>
#include <string.h>
int main(void)
{
    const int ILOSC = 8;
    double tablica1[ILOSC], tablica2[ILOSC]; 
    int i, suma;

    printf("Podaj 8 liczb zmiennoprzecinkowych\n");

    for ( i=0; i<ILOSC; i++ )
    {
        printf("Podaj liczbe\n");
        scanf("%lf", &tablica1[i]);
    }

    for ( suma = 0, i=0; i<ILOSC; i++ )
    {
        tablica2[i] = tablica2[i-1] + tablica1[i];
    }

    for ( i=0; i<ILOSC; i++ )
    {
        printf("%10.3lf ", tablica1[i]);
    }

    printf("\n");

    for ( i=0; i<ILOSC; i++ )
    {
        printf("%10.3lf ", tablica2[i]);
    }




    return 0;
}