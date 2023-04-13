#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define ROZMIAR 40
#define MIEJSCA 12

struct miejsce {
    unsigned int id;
    bool stan;
    char imie[ROZMIAR];
    char nazwisko[ROZMIAR];
};


int main (void)
{
    struct miejsce rezmc[MIEJSCA];
    char wybor;
    FILE *prez;
    unsigned int licznik = 0;
    int rozmiar = sizeof (struct miejsce);

    if ((prez = fopen("rezerwacje.dat","wb")) == NULL)
    {
        fputs("Nie moge otworzyc pliku rezerwacje.dat", stderr);
        exit(EXIT_FAILURE);
    }

    for (licznik = 0; licznik < MIEJSCA; licznik++)
    {
        rezmc[licznik].id = licznik + 1;
        rezmc[licznik].stan = false;
        strcpy(rezmc[licznik].imie,"empty");
        strcpy(rezmc[licznik].nazwisko,"empty");
    }

    fwrite(&rezmc[0], rozmiar, MIEJSCA, prez);
    
    fclose(prez);
    return 0;
}
