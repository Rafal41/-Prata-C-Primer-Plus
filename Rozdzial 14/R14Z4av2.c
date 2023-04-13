#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define ROZMIAR 20
#define ILOS 3

struct daneos {
    char imie[ROZMIAR];
    char drimie[ROZMIAR];
    char nazwisko[ROZMIAR];
};
struct dane {
    char pesel[12];
    struct daneos osoba;
};


void wyswietldane(const struct dane * struktura[]);

int main(void)
{ 
    const struct dane person[ILOS] =     {
                                {"99012312303","Rafal","Jan","Nowak"},
                                {"93042533423","Jan","Krzysztof","Jezyna"},
                                {"88040123034","Mateusz","","Kot"} 
                                };
    
    printf("Adres tablicy person - %p, person[0]= %p, person[1] = %p, person[0].imie[1] = %p\n", &person, &person[0],&person[1], &person[0].pesel[1]);
    const struct dane * wsk [ILOS];
    for (int i = 0; i < ILOS; i++)
        wsk[i] = &person[i];
     printf("Adres tablicy wsk- %p, wsk[0]= %p, wsk[1] = %p, wsk[2] = %p\n", &wsk, &wsk[0], &wsk[1], &wsk[2]);
    wyswietldane(wsk);

    return 0;
}

void wyswietldane(const struct dane * struktura[])
{
    char temp[3];
    printf("Adres tablicy struktura - %p, struktura[0]= %p, struktura[1] = %p, struktura[0].imie[1] = %p\n", &struktura, &struktura[0],&struktura[1], &struktura[0]->pesel[1]);
    for (int i = 0; i < ILOS; i++)
    {
        if (strlen(struktura[i]->osoba.drimie) == 0)
        {
            temp[0] = ' ';
            temp[1] = ' ';
        }
        else 
        {
            temp[0] = struktura[i]->osoba.drimie[0];
            temp[1] = '.';
        }
        printf("%s, %s %s -- %s\n",struktura[i]->osoba.nazwisko,struktura[i]->osoba.imie, temp ,struktura[i]->pesel);
    }  

}