//kompilowac razem z R12Z3b.c
// w komentarzach alternatywna wersja
#include <stdio.h>
#include "R12Z3a.h"

int main(void)
{
    int tryb;
    int wybor = 0;
    float dystans, paliwo;

    printf("Wybierz: 0 - system metryczny, 1 - system US: ");
    scanf("%d", &tryb);
    while (tryb >= 0)
    {
        wybor = wybierz_tryb(tryb, wybor);
        //pobierz_dane(wybor);
        pobierz_dane(wybor, &dystans, &paliwo);
        wyswietl_dane(wybor, dystans, paliwo);
        printf("Wybierz: 0 - system metryczny, 1 - system US");
        printf(" (-1 aby zakończyć): ");
        scanf("%d", &tryb);
        
    }
    printf("Koniec.\n");

    return 0;
}