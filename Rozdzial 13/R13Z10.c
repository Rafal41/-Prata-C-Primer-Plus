/* addaword.c -- uses fprintf(), fscanf(), and rewind() */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX 41
int main(void)
{
    char ch;
    long koniec, pozycja;   //pozycja w odczytywanym pliku

    FILE *fp; 
    char nazwa[MAX];

printf("Proszę podać nazwę pliku, który chcesz otworzyć.\n");
scanf("%s",nazwa);
        
if ((fp = fopen(nazwa, "r")) == NULL)
{
    fprintf(stderr, "Nie mozna otworzyc pliku %s",nazwa);
    exit(EXIT_FAILURE);
}
fseek (fp, 0L, SEEK_END);
koniec = ftell(fp);
printf("Proszę podać pozycję w pliku (liczba typu unsigned long) \n");
while (scanf("%lu", &pozycja) == 1 && pozycja >= 0) 
{
    if (pozycja > koniec - 1L)
    {
        printf("Ta pozycja nie znajduje sie w pliku \n");
        printf("Proszę podać pozycję w pliku (liczba typy unsigned long) \n");
    }
        
    else
    {
        fseek (fp, pozycja, SEEK_SET);
        while ((ch = getc(fp)) != '\n' && ch != EOF)
            putchar(ch);
        printf("Proszę podać pozycję w pliku (liczba typy unsigned long) \n");
    }
    printf("Podanie danych nieliczbowych lub liczby ujemnej kończy program) \n");
}

if (fclose(fp) != 0)
    fprintf(stderr,"Error closing file\n");

return 0;
}