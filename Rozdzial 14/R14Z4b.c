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


void wyswietldane(const struct dane struktura);

int main(void)
{ 
    struct dane person[ILOS] =     {
                                {"99012312303","Rafal","Jan","Nowak"},
                                {"93042533423","Jan","Krzysztof","Jezyna"},
                                {"88040123034","Mateusz","","Kot"} 
                                };
  
    //printf("Adres tablicy person - %p, person[0]= %p, person[1] = %p, person[0].imie[0] = %p\n", &person, &person[0],&person[1], &person[0].pesel[1]);
    for (int i = 0; i < ILOS; i ++)
            wyswietldane(person[i]);

    return 0;
}

void wyswietldane(const struct dane struktura)
{
    char temp[3];
   // printf("Adres tablicy struktura - %p, struktura.pesel= %p, struktura.imie = %p\n", &struktura, &struktura.pesel,&struktura.osoba.imie);
    
        if (strlen(struktura.osoba.drimie) == 0)
        {
            temp[0] = ' ';
            temp[1] = ' ';
        }
        else 
        {
            temp[0] = struktura.osoba.drimie[0];
            temp[1] = '.';
        }
        printf("%s, %s %s -- %s\n",struktura.osoba.nazwisko,struktura.osoba.imie, temp ,struktura.pesel);
 

}