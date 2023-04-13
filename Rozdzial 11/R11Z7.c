#include <stdio.h>
#define ROZMIAR 40
#define ROZMIAR2 10
char * kopiuj(char *landoc, char *lanzr, int rozmiar); //funkcja kopiująca lancuch zrodlowy do docelowego i biorąca pod uwagę zadeklarowaną dlugosc

int main(void)
{
    
    char lancuchzrodlowy[ROZMIAR];
    char lancuchdocelowy[ROZMIAR2];
    char * wsk;
    int ilosc = 0;

    printf("Podaj lancuch który chcesz skopiować.\n");
    fgets(lancuchzrodlowy, ROZMIAR, stdin);
    wsk = kopiuj(lancuchdocelowy, lancuchzrodlowy, ROZMIAR2-1);
    lancuchdocelowy[ROZMIAR2-1] = '\0';  //  dodaje znak zerowy na koncu łancucha
    puts(lancuchdocelowy);
    
    return 0;
}

char * kopiuj(char *landoc, char *lanzr, int rozmiar)
{
    int licznik;

    for (licznik = 0 ; licznik < rozmiar; licznik++)
    {
        if (lanzr[licznik] != '\0' && lanzr[licznik] != '\n')
            landoc[licznik] = lanzr[licznik];
        else    
        {
            while (licznik < rozmiar)
            {
                landoc[licznik] = '\0';
                licznik++;
            }
        }
    }
    return landoc;
}

