#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define ROZMIAR 4
#define DL 20

struct daneos {
    char imie[DL];
    char nazwisko[DL];
};
struct student {
    struct daneos osoba;
    float oceny[DL];
    float srednia;
};

int pobierzoceny(struct student * struktura);
void obliczsrednia(struct student * struktura, int num);
void sredniatot(struct student struktura[]);
//void wyswietldane(const struct dane struktura[]);

int main(void)
{ 
    struct student person[ROZMIAR] =     {
                                {"Rafal","Nowak"},     //,{2.0, 5.0, 5.0, 4.0, 3.0}, 0.0},
                                {"Jan","Nowak"},        //{2.5, 4.5, 5.0, 3.0, 3.0}, 0.0},
                                {"Jarek","Kwaos"},      //{4.0, 3.0, 2.0, 4.5, 2.5}, 0.0},
                                {"Kuba","Wolak"}       //{2.5, 4.5, 3.0, 3.5, 3.5}, 0.0},
                                };
    
    int ilosc = 0;

    for (int i = 0; i < ROZMIAR; i++)
    {
        ilosc = pobierzoceny(&person[i]);
        obliczsrednia(&person[i], ilosc);
    }

    sredniatot(person);
    
    return 0;
}

int pobierzoceny(struct student * struktura)
{
    int i = 0;
    int kontrol;

    printf("Podaj oceny dla ucznia %s %s\n", struktura->osoba.imie, struktura->osoba.nazwisko);
    puts("Podaj ocenę (q konczy)");
    while (scanf("%f", &struktura->oceny[i]) == 1)
    {
        kontrol = struktura->oceny[i];

        if (struktura->oceny[i] < 1.0 || struktura->oceny[i] > 6.0 )
        {
            puts("podano niepoprawną wartosc. Prosze podac wartosc z zakresu od 1.0 do 6.0");
            continue;
        }
        
        if (struktura->oceny[i] != (float) kontrol && struktura->oceny[i] != (float) kontrol + 0.5 )
        {
            puts("podano niepoprawną wartosc. Prosze podac wartosc z zakresu od 1.0 do 6.0");
            continue;
        } 

        i++;

        if (i > DL) 
        {
            puts("Podano maksymalna liczbe ocen");
            break;
        }
        puts("Podaj następną ocenę (q konczy)");
    }
    while (getchar() != '\n')
        continue;

    return i;

}

void obliczsrednia(struct student * struktura, int num)
{
    float suma = 0;

    for (int i = 0; i < num ; i++)
        suma += struktura->oceny[i];

    struktura->srednia += suma / num;
    printf("srednia ocen ucznia wynosi %.2f\n", struktura->srednia);
    
}

void sredniatot(struct student struktura[])
{
    float suma = 0;

    for (int i = 0; i < ROZMIAR ; i++)
        suma += struktura[i].srednia;
    
    printf("Srednia ocen wszystkich uczniow wynosi %.2f\n", suma/ROZMIAR);

}
