/* filmy2.c -- korzystanie z listy łączonej struktur */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROZT 45

struct film {
    //struct film * poprz;
    char tytul[ROZT];
    int ocena;
    struct film * nast;
};

char * wczytaj(char *z, int ile);
void wyswietlodtylu(struct film *);
int main(void)
{
    struct film * glowny = NULL;
    struct film * poprz, * biezacy;
    char wejscie[ROZT];
    /* pobieranie i zapisywanie informacji */
    puts("Podaj pierwszy tytul filmu:");
    while (wczytaj(wejscie,ROZT) != NULL && wejscie[0] != '\0')
    {
        biezacy = (struct film *) malloc (sizeof(struct film));
        if (glowny == NULL)
        {
            glowny = biezacy;
            //biezacy->poprz = NULL;
            //poprz = biezacy;
        }
        else
        {
            poprz->nast = biezacy;
            //biezacy->poprz = poprz;
        }

        biezacy->nast = NULL;
       
        strcpy(biezacy->tytul, wejscie);
        puts("podaj twoja ocene <0-10>");
        scanf("%d", &biezacy->ocena);
        while (getchar() != '\n')
            continue;
        puts("Podaj nastepny tytul filmu (pusty wiersz konczy program):");
        poprz = biezacy; 
    }

    /* wypisanie listy filmow */
    if (glowny == NULL)
        printf("Nie wpisano zadnych danych. ");
    else    
        printf("Oto lista filmow:\n");
    biezacy = glowny;
    while (biezacy != NULL)
    {
        printf("Film: %s, ocena: %d\n", biezacy->tytul, biezacy->ocena);
        biezacy = biezacy->nast;
    }

    puts("\nTeraz wyświetlam liste od tyłu");
    wyswietlodtylu(glowny);

    /*przebieg  programu zakonczony, zwalniamy przydzielona pamiec */
    biezacy = glowny;
    while (biezacy != NULL)
    {
        poprz = biezacy;
        biezacy = poprz->nast;
        free(poprz);
    }

    printf("Do widzenia\n");
    return 0;
}
void wyswietlodtylu(struct film * wsk)
{
    if (wsk->nast != NULL)
        wyswietlodtylu(wsk->nast);     
    printf("Film: %s, ocena: %d\n", wsk->tytul, wsk->ocena);
}

char * wczytaj(char *z, int ile)
{
    char * wynik;
    char * tutaj;
    wynik = fgets(z, ile, stdin);
    if(wynik)
    {
        tutaj = strchr(z, '\n');
        if(tutaj)
            *tutaj = '\0';
        else
            while (getchar() != '\n')
                continue;
        
    }
    return wynik;
}