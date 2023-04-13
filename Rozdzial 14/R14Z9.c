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

char pokazmenu(void);
char pokazmenu2(void);
void pustemcliczba(const struct miejsce tabrezw[]);
void pustemclista(const struct miejsce tabrezw[]);
void alflista(const struct miejsce tabrezw[]);
void rezerwmc(struct miejsce tabrezw[]);
void usunrezerw(struct miejsce tabrezw[]);
void potwrezerw(struct miejsce tabrezw[]);
char * wczytaj(char * z, int ile);

int main (void)
{
    struct miejsce rezmc[REJSY][MIEJSCA];
    char wybor, opcja;
    FILE *prez;
    unsigned int licznik = 0;
    int rozmiar = sizeof (struct miejsce);
    unsigned int nrrejsu, rejs;


    if ((prez = fopen("rezerwacje2.dat","r+b")) == NULL)
    {
        fputs("Nie moge otworzyc pliku rezerwacje.dat", stderr);
        exit(EXIT_FAILURE);
    }
   
    for (int i = 0; i < REJSY; i++)
        for (int j = 0; j < MIEJSCA; j++)
            fread(&rezmc[i][j], rozmiar, 1, prez);

    //fread(&rezmc[0], rozmiar, MIEJSCA * REJSY, prez);
    fclose (prez);

    // for (int i = 0; i < REJSY; i++)
    //     for (int j = 0; j < MIEJSCA; j++)
    //             printf("nr. lotu: %u, nr. miejsca: %u, stan: %d, imie: %s, nazwisko: %s, potwierdzenie: %s\n",rezmc[i][j].rejsid, 
    //             rezmc[i][j].id, (int) rezmc[i][j].stan, rezmc[i][j].imie, rezmc[i][j].nazwisko, rezmc[i][j].potwierdzenie);
    
    while ((opcja = pokazmenu2()) != 'e')
    {
        //printf("opcja = %c\n",opcja);
        if (opcja == 'a')
        {
            nrrejsu = 102; rejs = 0;
        }
        else if (opcja == 'b')
        {
            nrrejsu = 311; rejs = 1;
        }
        else if (opcja == 'c')
        {
            nrrejsu = 444; 
            rejs = 2;
        }
        else if (opcja == 'd')
        {
            nrrejsu = 519; rejs = 3;
        }

        while ((wybor = pokazmenu()) != 'g')
        {
            switch (wybor) 
            {
                case 'a': printf("\nWybrano lot %u\n\n",nrrejsu); pustemcliczba(rezmc[rejs]); break;
                case 'b': printf("\nWybrano lot %u\n\n",nrrejsu); pustemclista(rezmc[rejs]); break;
                case 'c': printf("\nWybrano lot %u\n\n",nrrejsu); alflista(rezmc[rejs]); break;
                case 'd': printf("\nWybrano lot %u\n\n",nrrejsu); rezerwmc(rezmc[rejs]); break;
                case 'e': printf("\nWybrano lot %u\n\n",nrrejsu); usunrezerw(rezmc[rejs]); break;
                case 'f': printf("\nWybrano lot %u\n\n",nrrejsu); potwrezerw(rezmc[rejs]); break;
                default : puts("błąd programu"); break;
            }
        }
    }
    // for (int i = 0; i < MIEJSCA; i++)
    //         printf("nr. miejsca: %u, stan: %d, imie: %s, nazwisko: %s, potwierdzenie: %s\n",rezmc[i].id, (int) rezmc[i].stan, rezmc[i].imie, rezmc[i].nazwisko, rezmc[i].potwierdzenie);
    
    
    if ((prez = fopen("rezerwacje2.dat","wb")) == NULL)
    {
        fputs("Nie moge otworzyc pliku rezerwacje.dat", stderr);
        exit(EXIT_FAILURE);
    }

    // for (int i = 0; i < REJSY; i++)
    //     for (int j = 0; j < MIEJSCA)
    //         licznik++;

    fwrite(&rezmc[0], rozmiar, MIEJSCA * REJSY, prez);
    fclose (prez);

    return 0;
    
}

char pokazmenu(void)
{
    char odp;
    puts("\nAby wybrac opcje, wpisz jej oznaczenie literowe");
    puts("a) Pokaz liczbe pustych miejsc");
    puts("b) Pokaz liste pustych miejsc");
    puts("c) Pokaz alfabetyczna liste miejsc");
    puts("d) Zarezerwuj miejsce dla klienta");
    puts("e) Usun rezerwacje miejsca");
    puts("f) Potwierdzenie rezerwacji miejsca");
    puts("g) Powrot do menu glownego");

    odp = tolower(getchar());

    while (getchar() != '\n')
        continue;

    if (odp < 'a' || odp > 'g') 
    {
        puts("Podano niepoprawny znak.");
        odp = pokazmenu();
    }

    return odp; 
}

char pokazmenu2(void)
{
    char odp;
    puts("\nWybierz rejs którym jesteś zainteresowany");
    puts("Aby wybrac opcje, wpisz jej oznaczenie literowe");
    puts("a) 102");
    puts("b) 311");
    puts("c) 444");
    puts("d) 519");
    puts("e) Koniec");

    odp = tolower(getchar());

    while (getchar() != '\n')
        continue;

    if (odp < 'a' || odp > 'e') 
    {
        puts("Podano niepoprawny znak.");
        odp = pokazmenu2();
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
            printf("nr. lotu: %u, nr. miejsca: %u, stan: %d, imie: %s, nazwisko: %s, potwierdzenie: %s\n",tabrezw[i].rejsid, 
            tabrezw[i].id, (int) tabrezw[i].stan, tabrezw[i].imie, tabrezw[i].nazwisko, tabrezw[i].potwierdzenie);
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
            strcpy(tabrezw[i].potwierdzenie,"brak potwierdzenia");
            puts("Prosze dokonac opcji potwierdzenia rezerwacji przy uzyciu odpowiedniej opcji w menu");
            break;
            // puts("Czy potwierdzasz rezerwacje miejsca? (Y/N)");
            // scanf("%c",&potw);
            // potw = toupper(potw);
            // while (getchar() != '\n')
            //     continue;

            // while (potw != 'Y' && potw != 'N')
            // {
            //     puts("Proszę podac poprawny znak");
            //     puts("Czy potwierdzasz rezerwacje miejsca? (Y/N)");
            //     scanf("%c",&potw);
            //     potw = toupper(potw);

            //     while (getchar() != '\n')
            //         continue;

            // }

            // if (potw == 'Y')
            //     break; 
            // else
            // {
            //     strcpy(tabrezw[i].imie, "empty");
            //     strcpy(tabrezw[i].nazwisko, "empty");
            //     tabrezw[i].stan = false;
            //     break;
            // }
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
                    strcpy(tabrezw[licznik].potwierdzenie,"empty");
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

void potwrezerw(struct miejsce tabrezw[])
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
                puts("Czy chcesz potwierdzic dokonianie rezerwacji miejsca? (Y/N)");
                scanf("%c",&potw);
                potw = toupper(potw);
                while (getchar() != '\n')
                    continue;

                while (potw != 'Y' && potw != 'N')
                {
                    puts("Proszę podac poprawny znak");
                    puts("Czy chcesz potwierdzic dokonianie rezerwacji miejsca? (Y/N)");
                    scanf("%c",&potw);
                    potw = toupper(potw);

                    while (getchar() != '\n')
                        continue;

                }

                if (potw == 'Y')
                {
                    strcpy(tabrezw[licznik].potwierdzenie,"potwierdzono");
                    break;
                }
                else
                {
                    strcpy(tabrezw[licznik].potwierdzenie,"brak potwierdzenia");
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
