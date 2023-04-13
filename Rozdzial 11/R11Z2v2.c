#include <stdio.h>
#include <ctype.h>
#define SIZE 41
char * wczytaj(char * st, int n);

int main(void)
{
    char tablica[SIZE];

    printf("Podaj tekst o długości %d znaków\n", SIZE-1);
    wczytaj(tablica, SIZE);
    puts(tablica);
    return 0;
}
char * wczytaj(char * st, int n)
{
    char * wynik;
    int i = 0;

    wynik = fgets(st, n, stdin);
    if (wynik)
    { 
        while (isalpha(st[i]))
            i++;
        if (isspace(st[i]))
            st[i] ='\0';
        else 
            while (getchar() != '\n')
                continue;
    }
    return wynik;
}