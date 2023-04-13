#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define ROZMIAR 40
#define MIEJSCA 12
#define REJSY 4
#define ROZMIARPOTW 19

struct miejsce {
    unsigned int rejsid;
    unsigned int id;
    bool stan;
    char imie[ROZMIAR];
    char nazwisko[ROZMIAR];
    char potwierdzenie[ROZMIARPOTW];
};


int main (void)
{
    struct miejsce rezmc[REJSY][MIEJSCA];
    char wybor;
    FILE *prez;
    unsigned int licznik = 0;
    int rozmiar = sizeof (struct miejsce);
    unsigned int nrrejsu;

    if ((prez = fopen("rezerwacje2.dat","wb")) == NULL)
    {
        fputs("Nie moge otworzyc pliku rezerwacje.dat", stderr);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < REJSY; i++)
    {   
        if (i == 0)
            nrrejsu = 102;
        else if (i == 1)
            nrrejsu = 311;
        else if (i == 2)
            nrrejsu = 444;
        else if (i == 3)
            nrrejsu = 519;

        for (licznik = 0; licznik < MIEJSCA; licznik++)
        {
            rezmc[i][licznik].rejsid = nrrejsu;
            rezmc[i][licznik].id = licznik + 1;
            rezmc[i][licznik].stan = false;
            strcpy(rezmc[i][licznik].imie,"empty");
            strcpy(rezmc[i][licznik].nazwisko,"empty");
            strcpy(rezmc[i][licznik].potwierdzenie,"empty");
        }
    }

    fwrite(&rezmc[0], rozmiar, MIEJSCA * REJSY, prez);
    
    fclose(prez);
    return 0;
}
