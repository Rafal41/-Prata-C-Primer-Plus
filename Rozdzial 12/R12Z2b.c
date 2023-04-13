//kompilowac razem z R12Z2b.c
#include <stdio.h>
#include "R12Z2a.h"

int main(void)
{
    int tryb;
    printf("Wybierz: 0 - system metryczny, 1 - system US: ");
    scanf("%d", &tryb);
    while (tryb >= 0)
    {
        wybierz_tryb(tryb);
        pobierz_dane();
        wyswietl_dane();
        printf("Wybierz: 0 - system metryczny, 1 - system US");
        printf(" (-1 aby zakończyć): ");
        scanf("%d", &tryb);
        
    }
    printf("Koniec.\n");

    return 0;
}