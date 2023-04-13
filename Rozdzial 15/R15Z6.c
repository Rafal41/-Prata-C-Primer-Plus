#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define LEWO 0
#define SRODEK 1
#define PRAWO 2


struct wl_czc {
    unsigned int typ        : 8;
    unsigned int rozmiar    : 7;
    unsigned int            : 1;
    unsigned int wyrownanie : 2; 
    bool wytluszczenie      : 1;
    bool kursywa            : 1;
    bool podkreslenie       : 1;
    unsigned int            : 3;
};

char pokaz_menu();
void wyswietl(const struct wl_czc *);
void zmianaczc(struct wl_czc *);
void zmianaroz(struct wl_czc *);
void zmianawyr(struct wl_czc *);
void zmianawytl(struct wl_czc *);
void zmianapoch(struct wl_czc *);
void zmianapodk(struct wl_czc *);


int main (void)
{
    struct wl_czc czcionka = {1,12, LEWO, false, false, false};
    char ch;
    wyswietl(&czcionka);
    while ( (ch = pokaz_menu()) != 'k')
    {
        switch (ch)
        {
            case 't': zmianaczc(&czcionka); break;
            case 'r': zmianaroz(&czcionka); break;
            case 'w': zmianawyr(&czcionka); break;
            case 'b': zmianawytl(&czcionka); break;
            case 'i': zmianapoch(&czcionka); break;
            case 'u': zmianapodk(&czcionka); break;
            default : puts("błąd programu");
        }

        wyswietl(&czcionka);
    }
    
    return 0;
}

char pokaz_menu()
{
    char odp;
    const char odpowiedzi[8] = {'t', 'r', 'w', 'b', 'i', 'u', 'k'};
    //const char odpowiedzi[8] = {"trwbiuk"};


    puts("t) zmiana czcionki    r) zmiana rozmiaru      w) zmiana wyrownania");
    puts("b) przelacz BOLD      i) przelacz ITALIC      u) przelacz UNDERLINE");
    puts("k) wyjscie");

    odp = tolower(getchar());
    
    while (getchar() != '\n')
        continue;

    if (strchr(odpowiedzi, odp) == NULL) 
    {
        puts("Podano niepoprawny znak.");
        odp = pokaz_menu();
    }

    return odp;
}

void wyswietl(const struct wl_czc * dane)
{
    puts("Typ   Rozmiar   Wyrownanie   Wytl.   Kurs.   Podkr.");
    printf("%-3u   %-7u   ", dane->typ, dane->rozmiar);
    switch(dane->wyrownanie)
    {
        case LEWO :     printf("%-10s   ","lewo"); break;
        case SRODEK :   printf("%-10s   ","srodek"); break;
        case PRAWO :    printf("%-10s   ","prawo"); break;
        default :       printf("%-10s   ","błąd");
    }
    printf("%-5s   %-5s   %-6s\n", dane->wytluszczenie == true? "wl":"wy", dane->kursywa == true? "wl":"wy", dane->podkreslenie == true? "wl":"wy");
}


void zmianaczc(struct wl_czc * dane)
{
    unsigned int temp = 256;

    puts("Podaj typ czcionki - 0-255");
    scanf("%u", &temp );

    while (getchar() != '\n')
        continue;

    while (temp < 0 || temp > 255)
    {
        puts("Niepoprawnie podany numer");
        puts("Podaj typ czcionki - 0-255");
        scanf("%u", &temp);

        while (getchar() != '\n')
        continue;
    }

    dane->typ = temp;
}

void zmianaroz(struct wl_czc * dane)
{

    unsigned int temp = 256;

    puts("Podaj rozmiar czcionki - 0-127");
    scanf("%u", &temp );

    
    while (getchar() != '\n')
        continue;

    while (temp < 0 || temp > 127)
    {
        puts("Niepoprawnie podany numer");
        puts("Podaj rozmiar czcionki - 0-127");
        scanf("%u", &temp);
        while (getchar() != '\n')
        continue;
    }
    
    dane->rozmiar = temp;
}


void zmianawyr(struct wl_czc * dane)
{
    char odp;
    const char odpowiedzi[4] = {'l', 's', 'p'};
    puts("Wybierz wyrownanie:");
    puts("l) w lewo   s) na srodek   p) w prawo");

    odp = tolower(getchar());
    
    while (getchar() != '\n')
        continue;

    while (strchr(odpowiedzi, odp) == NULL) 
    {
        puts("Podano niepoprawny znak.");
        puts("Wybierz wyrownanie:");
        puts("l) w lewo   s) na srodek   p) w prawo");
        odp = tolower(getchar());

        while (getchar() != '\n')
            continue;
    }

    switch(odp)
    {
        case 'l' :    dane->wyrownanie = LEWO; break;
        case 's' :    dane->wyrownanie = SRODEK; break;
        case 'p' :    dane->wyrownanie = PRAWO; break;
        default :      puts("blad");
    }

}

void zmianawytl(struct wl_czc * dane)
{
    dane->wytluszczenie = !(dane->wytluszczenie);
}

void zmianapoch(struct wl_czc * dane)
{
    dane->kursywa = !(dane->kursywa);
}

void zmianapodk(struct wl_czc * dane)
{
    dane->podkreslenie = !(dane->podkreslenie);
}