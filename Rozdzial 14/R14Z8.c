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

char pokazmenu(void);
void pustemcliczba(const struct miejsce tabrezw[]);
void pustemclista(const struct miejsce tabrezw[]);
void alflista(const struct miejsce tabrezw[]);
void rezerwmc(struct miejsce tabrezw[]);
void usunrezerw(struct miejsce tabrezw[]);
char * wczytaj(char * z, int ile);

int main (void)
{
    struct miejsce rezmc[MIEJSCA];
    char wybor;
    FILE *prez;
    unsigned int licznik = 0;
    int rozmiar = sizeof (struct miejsce);

    if ((prez = fopen("rezerwacje.dat","r+b")) == NULL)
    {
        fputs("Nie moge otworzyc pliku rezerwacje.dat", stderr);
        exit(EXIT_FAILURE);
    }

    while (licznik < MIEJSCA && fread(&rezmc[licznik], rozmiar, 1, prez) == 1)
        licznik++;

    fclose (prez);
    
    while ((wybor = pokazmenu()) != 'f')
    {
        switch (wybor) 
        {
            case 'a': pustemcliczba(rezmc); break;
            case 'b': pustemclista(rezmc); break;
            case 'c': alflista(rezmc); break;
            case 'd': rezerwmc(rezmc); break;
            case 'e': usunrezerw(rezmc); break;
            default : puts("błąd programu"); break;
        }
    }

    // for (int i = 0; i < MIEJSCA; i++)
    //         printf("nr. miejsca: %u, stan: %d, imie: %s, nazwisko: %s\n",rezmc[i].id, (int) rezmc[i].stan, rezmc[i].imie, rezmc[i].nazwisko);
    
    
    if ((prez = fopen("rezerwacje.dat","wb")) == NULL)
    {
        fputs("Nie moge otworzyc pliku rezerwacje.dat", stderr);
        exit(EXIT_FAILURE);
    }
    fwrite(&rezmc[0], rozmiar, MIEJSCA, prez);
    fclose (prez);

    return 0;
    
}

char pokazmenu(void)
{
    char odp;
    puts("Aby wybrac opcje, wpisz jej oznaczenie literowe");
    puts("a) Pokaz liczbe pustych miejsc");
    puts("b) Pokaz liste pustych miejsc");
    puts("c) Pokaz alfabetyczna liste miejsc");
    puts("d) Zarezerwuj miejsce dla klienta");
    puts("e) Usun rezerwacje miejsca");
    puts("f) Koniec");

    odp = tolower(getchar());

    while (getchar() != '\n')
        continue;

    if (odp < 'a' || odp > 'f') 
    {
        puts("Podano niepoprawny znak.");
        odp = pokazmenu();
    }

    return odp; 
}

void pustemcliczba(const struct miejsce tabrezw[])
{
    int licznik = 0;

    for (int i = 0; i < MIEJSCA; i++)
        if (tabrezw[i].stan == false)
            licznik++;
    
    printf("Ilosc pustych miejsc wynosi %d\n", licznik);

}

void pustemclista(const struct miejsce tabrezw[])
{
    puts("Oto lista pustych miejsc");
    for (int i = 0; i < MIEJSCA; i++)
        if (tabrezw[i].stan == false)
            printf("nr. miejsca: %u\n",tabrezw[i].id);
}

void alflista(const struct miejsce tabrezw[])
{
    puts("Oto lista wszystkich miejsc");
    for (int i = 0; i < MIEJSCA; i++)
            printf("nr. miejsca: %u, stan: %d, imie: %s, nazwisko: %s\n",tabrezw[i].id, (int) tabrezw[i].stan, tabrezw[i].imie, tabrezw[i].nazwisko);
}

void rezerwmc(struct miejsce tabrezw[])
{
    unsigned int licznik = 0;
    char potw;

    for (int i = 0; i < MIEJSCA; i++)
    {
        if (tabrezw[i].stan == false)
        {
            puts("podaj imie");
            wczytaj(tabrezw[i].imie, ROZMIAR);
            puts("podaj nazwisko");
            wczytaj(tabrezw[i].nazwisko, ROZMIAR);
            tabrezw[i].stan = true;


            puts("Czy potwierdzasz rezerwacje miejsca? (Y/N)");
            scanf("%c",&potw);
            potw = toupper(potw);
            while (getchar() != '\n')
                continue;

            while (potw != 'Y' && potw != 'N')
            {
                puts("Proszę podac poprawny znak");
                puts("Czy potwierdzasz rezerwacje miejsca? (Y/N)");
                scanf("%c",&potw);
                potw = toupper(potw);

                while (getchar() != '\n')
                    continue;

            }


            if (potw == 'Y')
                break;
            else
            {
                strcpy(tabrezw[i].imie, "empty");
                strcpy(tabrezw[i].nazwisko, "empty");
                tabrezw[i].stan = false;
                break;
            }
        }
        else if (tabrezw[i].stan == true)
        {
            licznik++;
            if (licznik == MIEJSCA)
            {
                puts("Nie ma już wolnych miejsc");
                break;
            }
        } 
    }
}

void usunrezerw(struct miejsce tabrezw[])
{
    unsigned int licznik = 0;
    char temp[ROZMIAR];
    char temp2[ROZMIAR];
    char potw;

    puts("Proszę podać imie na ktore jest zrobiona rezerwacja");
    wczytaj(temp, ROZMIAR);
    puts("Proszę podać nazwisko na ktore jest zrobiona rezerwacja");
    wczytaj(temp2, ROZMIAR);
    
    for (int i = 0; i < MIEJSCA; i++)
    {
        if (strcmp(tabrezw[i].imie, temp) == 0)
        {
            if (strcmp(tabrezw[i].nazwisko, temp2) == 0)
            {
                puts("Czy potwierdzasz usuniecie rezerwacji miejsca? (Y/N)");
                scanf("%c",&potw);
                potw = toupper(potw);
                while (getchar() != '\n')
                    continue;

                while (potw != 'Y' && potw != 'N')
                {
                    puts("Proszę podac poprawny znak");
                    puts("Czy potwierdzasz usuniecie rezerwacji miejsca? (Y/N)");
                    scanf("%c",&potw);
                    potw = toupper(potw);

                    while (getchar() != '\n')
                        continue;

                }

                if (potw == 'Y')
                {
                    strcpy(tabrezw[licznik].imie,"empty");
                    strcpy(tabrezw[licznik].nazwisko,"empty");
                    tabrezw[i].stan = false;
                    puts("Rezerwacja zostala pomyślnie usunięta");
                    break;
                }
                else
                {
                    puts("Nie usunieto rezerwacji");
                    break;
                }
                    
            }
        }    
        else //(strcmp(tabrezw[i].imie, temp) != 0)
        {
            licznik++;
            if (licznik == MIEJSCA)
            {
                puts("Nie ma rezerwacji na takie dane osobowe");
                break;
            }
        } 
    }
}


char * wczytaj(char * z, int ile)
{
    char * wynik;
    char * tutaj;
   
    scanf("%s", z);
    while (getchar() != '\n')
        continue;
    //wynik = fgets(z, ile, stdin);
    // if (wynik)
    // { 
    //     tutaj = strchr(z,' ');
    //     if (tutaj)
    //         *tutaj ='\0';
    //     else 
    //         tutaj = strchr(z,'\n');
    //         if (tutaj)
    //             *tutaj ='\0';
    //         else 
    //             while (getchar() != '\n')
    //                 continue;
    // }
    return z;
}
