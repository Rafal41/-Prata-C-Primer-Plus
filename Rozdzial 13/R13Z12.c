#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define TEMPTAB1 20
#define TEMPTAB2 30
int main(void)
{
    char nazwa[40];
    int tab[TEMPTAB1][TEMPTAB2];
    char tabznk[TEMPTAB1][TEMPTAB2];
    FILE *wp;
    int ch; 

    printf("Podaj nazwe pliku do wczytania\n");
    scanf("%s", nazwa);
    
    if ((wp = fopen(nazwa, "r")) == NULL)
    {
        fprintf(stderr, "Błąd otwarcia pliku %s\n", nazwa);
        exit(EXIT_FAILURE);
    }
    
    //wczytywanie liczb z pliku do tablicy tab
    for (int i = 0; i < TEMPTAB1; i++)
        for (int j = 0; j < TEMPTAB2+1; j++)
            while ((ch = getc(wp)) != '\n' && ch != EOF)
                if (isdigit(ch))
                {
                    
                    tab[i][j] = ch;
                    //printf("i= %d, j = %d, ch = %c, tab[i][j] = %c\n", i, j, ch, tab[i][j]);
                    break;
                }
    
    fclose(wp);
    
    //wyswietlamy tabele tab
    for (int i = 0; i < TEMPTAB1; i++)
    {
        for (int j = 0; j < TEMPTAB2; j++)
            putchar(tab[i][j]);
        putchar('\n');
    }

    //tworzenie nowej tablicy znakowej
    for (int i = 0; i < TEMPTAB1; i++)
        for (int j = 0; j < TEMPTAB2; j++)
        {
                if (tab[i][j] == '0')
                    tabznk[i][j] = ' ';
                else if (tab[i][j] == '1')
                    tabznk[i][j] = '.';
                else if (tab[i][j] == '2')
                    tabznk[i][j] = '\'';
                else if (tab[i][j] == '3')
                    tabznk[i][j] = ':';
                else if (tab[i][j] == '4')
                    tabznk[i][j] = '~';
                else if (tab[i][j] == '5')
                    tabznk[i][j] = '*';
                else if (tab[i][j] == '6')
                    tabznk[i][j] = '=';
                else if (tab[i][j] == '7')
                    tabznk[i][j] = '$';
                else if (tab[i][j] == '8')
                    tabznk[i][j] = '%';
                else // (tab[i][j] == 9)
                    tabznk[i][j] = '#';
        }


    printf("Podaj nazwe pliku do zapisu\n");
    scanf("%s", nazwa);
    if ((wp = fopen(nazwa, "w")) == NULL)
    {
        fprintf(stderr, "Błąd otwarcia pliku %s\n", nazwa);
        exit(EXIT_FAILURE);
    }
    
    
    //wyswietlanie tablicy
    for (int i = 0; i < TEMPTAB1; i++)
    {
        for (int j = 0; j < TEMPTAB2; j++)
        {
            putc(tabznk[i][j],wp);
            putchar(tabznk[i][j]);
        }
        putc('\n',wp);
        putchar('\n');
    }

    
    return 0;
}