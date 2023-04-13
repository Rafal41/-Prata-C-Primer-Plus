
#include <stdio.h>
#include <string.h>
int main(void)
{
    const int ILOSC = 8;
    int i, rozmiar;
    int liczba[ILOSC]; 

    printf("Podaj 8 liczb całkowitych\n");

    for ( i=0; i<ILOSC; i++ )
    {
        printf("Podaj liczbe\n");
        scanf("%d", &liczba[i]);
    }

        for ( i = ILOSC-1; i >= 0; i-- )   // wyswietlanie cyfr w odwrotnej kolejnosci na ekranie
            printf("%d ", liczba[i]);

    return 0;
}