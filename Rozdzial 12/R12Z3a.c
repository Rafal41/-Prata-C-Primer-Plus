//kompilowac razem z R12Z3b.c
// w komentarzach alternatywna wersja
#include <stdio.h>
#include "R12Z3a.h"

int wybierz_tryb(int t, int wyb)
{

    if (t > 1)
    {
        if (wyb == 0)
            printf("Podano nieprawidlową wartość. Wybrano system 0(metryczny).\n");
        if (wyb == 1)
            printf("Podano nieprawidlową wartość. Wybrano system 1(US).\n");
    }
    else
        wyb = t;

    return wyb;
}
//void pobierz_dane(int wyb)
void pobierz_dane(int wyb, float * d, float *p)
{
    //float dystans, paliwo;

    if (wyb == 0)
    {
        printf("Wprowadz przebyta odleglosc w kilometrach: ");
        scanf("%f", d);
        //scanf("%f", &dystans);
        printf("Wprowadz zuzyte paliwo w litrach: ");
        scanf("%f", p);
        //scanf("%f", &paliwo);
        //wyswietl_dane(wyb, dystans, paliwo);
    }
    if (wyb == 1)
    {
        printf("Wprowadz przebyta odleglosc w milach: ");
        scanf("%f", d);
        //scanf("%f", &dystans);
        printf("Wprowadz zuzyte paliwo w galonach: ");
        scanf("%f", p);
        //scanf("%f", &paliwo);
        //wyswietl_dane(wyb, dystans, paliwo);
    }
}

void wyswietl_dane(int wyb, float dyst, float pal)
{
    if (wyb == 0)
    {
        printf("Zuzycie paliwa wynioslo %.2f na 100km.\n",pal/dyst*100);
    }
    if (wyb == 1)
    {
        printf("Zuzycie paliwa wynioslo %.1f mil na galon.\n", dyst/pal);
    }
}