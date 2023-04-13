//kompilowac razem z R12Z2b.c
#include <stdio.h>
#include "R12Z2a.h"
static int tr;
static float dystans;
static float paliwo;

void wybierz_tryb(int t)
{
    extern int tr;

    if (t > 1)
    {
        if (tr == 0)
            printf("Podano nieprawidlową wartość. Wybrano system 0(metryczny).\n");
        if (tr == 1)
            printf("Podano nieprawidlową wartość. Wybrano system 1(US).\n");
    }
    else
        tr = t;
}

void pobierz_dane(void)
{
    extern int tr;
    extern float dystans, paliwo;

    if (tr == 0)
    {
        printf("Wprowadz przebyta odleglosc w kilometrach: ");
        scanf("%f", &dystans);
        printf("Wprowadz zuzyte paliwo w litrach: ");
        scanf("%f", &paliwo);
    }
    if (tr == 1)
    {
        printf("Wprowadz przebyta odleglosc w milach: ");
        scanf("%f", &dystans);
        printf("Wprowadz zuzyte paliwo w galonach: ");
        scanf("%f", &paliwo);
    }
}

void wyswietl_dane(void)
{
    extern int tr;
    extern float dystans, paliwo;
    
    if (tr == 0)
    {
        printf("Zuzycie paliwa wynioslo %.2f na 100km.\n",paliwo/dystans*100);
    }
    if (tr == 1)
    {
        printf("Zuzycie paliwa wynioslo %.1f mil na galon.\n", dystans/paliwo);
    }
}