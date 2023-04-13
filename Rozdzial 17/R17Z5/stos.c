#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stos.h"
void InicjujStos(Stos *wsk)
{
    wsk->item[0] = 0;
    wsk->polozenie = 0;
}

bool PelnyStos(Stos *wsk)
{
    return wsk->polozenie == MAXSTOS;
}

bool PustyStos(Stos *wsk)
{
    return wsk->polozenie == 0;
}

int LiczbaPozycji(Stos *wsk)
{
    return wsk->polozenie;
}
bool PoloznaStos(Stos *wsk, Item item)
{

    if (PelnyStos(wsk))
        return false;
    wsk->item[wsk->polozenie] = item;
    wsk->polozenie++; 
    return true;
}
bool Pobierz(Stos *wsk, Item *iitem)
{
    if (PustyStos(wsk))
        return false;

    Stos pol = *wsk;

    pol.polozenie--;
    *iitem = wsk->item[pol.polozenie];

    wsk->item[wsk->polozenie] = 0;
    wsk->polozenie--;

    if (wsk->polozenie == 0)
        wsk->item[0]  = 0;
    return true;
}


void WyczyscStos(Stos *wsk)
{
    Item dummy;
    while (!PustyStos(wsk))
        Pobierz(wsk, &dummy);
}

