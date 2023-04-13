#include <stdio.h>
#include <stdlib.h>
int main (void)
{
    int ch;
    FILE *wp;
    char nazwa[40];
    unsigned long licznik = 0;
    printf("Podaj nazwe pliku, który chcesz otworzyć\n");
    scanf("%s", nazwa);

    if ((wp = fopen(nazwa, "r")) == NULL)
    {
        printf("Ne mozna otworzyc %s\n", nazwa);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(wp)) != EOF)
    {
        putc(ch,stdout);
        licznik++;
    }
    fclose(wp);
    puts("\n");
    printf("Plik %s zawiera %lu znakow\n", nazwa, licznik);
    return 0;
}