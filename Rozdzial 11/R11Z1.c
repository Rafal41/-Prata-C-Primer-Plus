#include <stdio.h>
#define SIZE 41
void * wczytaj(char * st, int n);

int main(void)
{
    char tablica[SIZE];

    printf("Podaj tekst o długości %d znaków\n", SIZE-1);
    wczytaj(tablica, SIZE);
    puts(tablica);
    return 0;
}
void * wczytaj(char * st, int n)
{
    fgets(st, n, stdin);
    while (getchar() != '\n')
        continue;
}