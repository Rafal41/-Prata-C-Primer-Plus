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
struct miesiac rokzw [12] = {
    {"Styczen", "sty", 31, 1},
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

int wyswietldane(struct miesiac * nazwamies);

int main(void)
{ 
    struct miesiac mscuser;
    char temp[12];
    int dni;
    int rok;
    int i;

    printf("Podaj dowolną datę w roku, a ja policze liczbe dni od poczatku roku do tej daty\n");
    printf("Najpierw podaj dzień\n");
    scanf("%d", &mscuser.dni);
    printf("Teraz podaj miesiac\n");
    scanf("%s", temp);
    
    if (strlen(temp) == 1 || strlen(temp) == 2)
    {
        mscuser.nummsc = atoi(temp);
        if (mscuser.nummsc < 1 || mscuser.nummsc > 12)
        {
            puts("Podano niepoprawna miesiac.");
            exit(EXIT_FAILURE);
        }
        
        for (i = 0; i < ROK; i++)
            if (rokzw[i].nummsc == mscuser.nummsc)
                {
                    strcpy(mscuser.nazwamsc,rokzw[i].nazwamsc);
                    break;
                }
    }
    else if (strlen(temp) == 3)
    {
        for (int i = 0; i < strlen(temp); i++)
            temp[i] = tolower(temp[i]);
        for (i = 0; i < ROK; i++)
            if (strcmp(rokzw[i].skrot,temp) == 0)
                {
                    strcpy(mscuser.nazwamsc,rokzw[i].nazwamsc);
                    mscuser.nummsc = rokzw[i].nummsc;
                    break;
                }
    }
    else if (strlen(temp) > 3)
    {
        strcpy(mscuser.nazwamsc,temp);
        mscuser.nazwamsc[0] = toupper(mscuser.nazwamsc[0]);
        for (int i = 1; i < strlen(mscuser.nazwamsc); i++)
            mscuser.nazwamsc[i] = tolower(mscuser.nazwamsc[i]);
        for (i = 0; i < ROK; i++)
            if (strcmp(mscuser.nazwamsc,rokzw[i].nazwamsc) == 0)
                {
                    mscuser.nummsc = rokzw[i].nummsc;
                    break;
                }
    }

    printf("Na koniec podaj rok\n");
    scanf("%d", &rok);

    if (rok % 4 == 0)
        rokzw[1].dni = 29;

    if (mscuser.dni > rokzw[i].dni)
    {
    
        puts("Podano niepoprawny dzień.");
        exit(EXIT_FAILURE);
    }


    // if (rok % 4 != 0 && mscuser.nummsc == 2 && mscuser.dni == 29)
    // {
    //     puts("Podany dzień który nie występuje w tym roku.");
    //     exit(EXIT_FAILURE);
    // }
    
    if (rok % 4 != 0)
        printf("Liczba dni od poczatku roku do wskazanego przez ciebie miesiaca to %d\n", wyswietldane(&mscuser));
    else
    {
        puts("Twoj rok jest rokiem przestepnym");
        printf("Liczba dni od poczatku roku do wskazanego przez ciebie miesiaca to %d\n", wyswietldane(&mscuser));

    }
        

    return 0;
}

int wyswietldane(struct miesiac * nazwamies)
{
    int wynik = 0;
    int i = 0;

    while (strcmp(rokzw[i].nazwamsc,nazwamies->nazwamsc) != 0)
    {
        if (i >= 12)
        {
            puts("Podano niepoprawna nazwe miesiaca.");
            exit(EXIT_FAILURE);
        }
        
        wynik += rokzw[i].dni;
        i++;
    }
    wynik += nazwamies->dni;
        
    return wynik;
}