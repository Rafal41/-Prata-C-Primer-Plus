#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define TYP_MASKA           0xFF
#define ROZMIAR_MASKA       0X7F00
#define W_LEWO              0x000000
#define W_SRODEK            0x010000
#define W_PRAWO             0x020000
#define WYROWNANIE_MASKA    0x030000
#define WYTL_MASKA          0x040000
#define KURS_MASKA          0x080000
#define PODK_MASKA          0x100000

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
void wyswietl(const unsigned long * dane);
void zmianaczc(unsigned long * dane);
void zmianaroz(unsigned long * dane);
void zmianawyr(unsigned long * dane);
void zmianawytl(unsigned long * dane);
void zmianapoch(unsigned long * dane);
void zmianapodk(unsigned long * dane);


int main (void)
{
    unsigned long czcionka = 0L;
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

void wyswietl(const unsigned long * dane)
{
    puts("Typ   Rozmiar   Wyrownanie   Wytl.   Kurs.   Podkr.");
    printf("%-3u   %-7u   ", *dane & TYP_MASKA , (*dane & ROZMIAR_MASKA) >> 8);
    switch(*dane & WYROWNANIE_MASKA)
    {
        case W_LEWO :     printf("%-10s   ","lewo"); break;
        case W_SRODEK :   printf("%-10s   ","srodek"); break;
        case W_PRAWO :    printf("%-10s   ","prawo"); break;
        default :         printf("%-10s   ","błąd");
    }
    printf("%-5s   %-5s   %-6s\n", (*dane & WYTL_MASKA) == WYTL_MASKA? "wl":"wy", (*dane & KURS_MASKA) == KURS_MASKA? "wl":"wy", (*dane & PODK_MASKA) == PODK_MASKA? "wl":"wy");
}


void zmianaczc(unsigned long * dane)
{
    unsigned int temp = 256;

    *dane &= ~TYP_MASKA;  

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

    //temp &= TYP_MASKA;
    *dane |= temp;
    

}

void zmianaroz(unsigned long * dane)
{
    unsigned int temp = 256;

    *dane &= ~ROZMIAR_MASKA;  


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
    temp <<= 8;
    *dane |= temp;
}


void zmianawyr(unsigned long * dane)
{
    char odp;
    const char odpowiedzi[4] = {'l', 's', 'p'};

    *dane &= ~WYROWNANIE_MASKA;

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
        case 'l' :      *dane |= W_LEWO; break;
        case 's' :      *dane |= W_SRODEK; break;
        case 'p' :      *dane |= W_PRAWO; break;
        default :      puts("blad");
    }

}

void zmianawytl(unsigned long * dane)
{
    *dane ^= WYTL_MASKA;
}

void zmianapoch(unsigned long * dane)
{
    *dane ^= KURS_MASKA;
}

void zmianapodk(unsigned long * dane)
{
    *dane ^= PODK_MASKA;
}
