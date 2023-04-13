#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define ROK 12

struct miesiac {
    char nazwamsc[12];
    char skrot[4];
    int dni;
    int nummsc;
};
struct miesiac rok [12] = {
    {"Styczen", "stn", 31, 1},
    {"Luty", "lut", 28, 2},
    {"Marzec", "mar", 31, 3},
    {"Kwiecien", "kwi", 30, 4},
    {"Maj", "maj", 31, 5},
    {"Czerwiec", "cze", 30, 6},
    {"Lipiec", "lip", 31, 7},
    {"Sierpien", "sie", 31, 8},
    {"Wrzesien", "wrz", 30, 9},
    {"Pazdziernik", "paz", 31, 10},
    {"Listopad", "lis", 30, 11},
    {"Grudzien", "gru", 31, 12},

};

int wyswietldane(char nazwamies[]);

int main(void)
{ 
    char mscuser[12];

    printf("Podaj dowolny miesiac, a ja policze liczbe dni od poczatku roku do konca tego miesiaca\n");
    scanf("%s", mscuser);
    mscuser[0] = toupper(mscuser[0]);
    for (int i = 1; i < strlen(mscuser); i++)
        mscuser[i] = tolower(mscuser[i]);
    
    printf("Liczba dni do końca wskazanego przez Ciebie miesiaca to %d\n", wyswietldane(mscuser));

    return 0;
}

int wyswietldane(char nazwamies[])
{
    int wynik = 0;
    int i = 0;
    //int flag = 0;

    while (strcmp(rok[i].nazwamsc,nazwamies) != 0)
    {
        if (i >= 12)
        {
            puts("Podano niepoprawna nazwe miesiaca.");
            exit(EXIT_FAILURE);
        }
        
        wynik += rok[i].dni;
        i++;
    }
    wynik += rok[i].dni;
     
    // for (int i = 0; i < ROK; i++)
    // {
    //     if (strcmp(rok[i].nazwamsc,nazwamies) == 0)
    //     {
    //         wynik += rok[i].dni;
    //         flag = 1;
    //         break;
    //     }
    //     else
    //         wynik += rok[i].dni;
   
    // }

    // if (flag = 0)
    // {
    //     puts("Podano niepoprawna nazwe miesiaca.")
    //     exit(EXIT_FAILURE):
    // }
        
    return wynik;
}