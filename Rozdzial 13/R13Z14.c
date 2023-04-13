#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#define TEMPTAB1 20
#define TEMPTAB2 30
int main(void)
{
    char nazwa[40];
    int tab[TEMPTAB1][TEMPTAB2];
    char tabznk[TEMPTAB1][TEMPTAB2];
    FILE *wp;
    int ch; 
    bool flag = false;
    double wynik;

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

    for (int i = 0; i < TEMPTAB1; i++)
        for (int j = 0, flag = false; j < TEMPTAB2 + 1; j++, flag = false)
        { 
            //narozne
            if ((i == 0 || i == TEMPTAB1 - 1) && (j == 0 || j == TEMPTAB2))
            {
                
                if (j - 1 > 0 && (tab[i][j] - tab[i][j-1])*(tab[i][j] - tab[i][j-1]) > 1)
                    flag = true;
                else if (j + 1 < TEMPTAB2 && (tab[i][j] - tab[i][j+1])*(tab[i][j] - tab[i][j+1]) > 1)
                    flag = true;
                else if (i - 1 > 0 && (tab[i][j] - tab[i-1][j])*(tab[i][j] - tab[i-1][j]) > 1)
                    flag = true;
                else if (i + 1 < TEMPTAB1 - 1 && (tab[i][j] - tab[i+1][j])*(tab[i][j] - tab[i+1][j]) > 1)
                    flag = true;
                else
                    continue;
                
                if (flag == true)
                {
                    
                    if (i == 0 && j == 0)
                        wynik = (double)(tab[i][j+1] + tab[i+1][j])/2.0;
                    else if (i == 0 && j == TEMPTAB2)
                        wynik = (double)(tab[i][j-1] + tab[i+1][j])/2.0;
                    else if (i == TEMPTAB1 - 1 && j == 0)
                        wynik = (double)(tab[i][j+1] + tab[i-1][j])/2.0;
                    else if (i == TEMPTAB1 - 1 && j == TEMPTAB2)
                        wynik = (double)(tab[i][j-1] + tab[i-1][j])/2.0;
                    
                    if (wynik - (int)wynik >= 0.5)
                        wynik = (int)wynik + 1;
                    else
                        wynik = (int)wynik;
                    tab[i][j] = wynik;
                }
            }
        
            //SRODKOWE
            else if (i > 0 && i < TEMPTAB1 - 1 && j > 0 && j < TEMPTAB2)
            {
                if ((tab[i][j] - tab[i][j-1])*(tab[i][j] - tab[i][j-1]) > 1)
                    flag = true;
                else if ((tab[i][j] - tab[i][j+1])*(tab[i][j] - tab[i][j+1]) > 1)
                    flag = true;
                else if ((tab[i][j] - tab[i-1][j])*(tab[i][j] - tab[i-1][j]) > 1)
                    flag = true;
                else if ((tab[i][j] - tab[i+1][j])*(tab[i][j] - tab[i+1][j]) > 1)
                    flag = true;
                else
                    continue;
                
                if (flag == true)
                {
                    wynik = (double)(tab[i][j-1] + tab[i][j+1] + tab[i-1][j] + tab[i+1][j])/4.0;
                    if (wynik - (int)wynik >= 0.5)
                        wynik = (int)wynik + 1;
                    else
                        wynik = (int)wynik;
                    tab[i][j] = wynik;
                }
            }
            else //boczne
            {
                if (i == 0 && (j != 0 && j != TEMPTAB2))
                {
                    if ((tab[i][j] - tab[i][j-1])*(tab[i][j] - tab[i][j-1]) > 1)
                        flag = true;
                    else if ((tab[i][j] - tab[i][j+1])*(tab[i][j] - tab[i][j+1]) > 1)
                        flag = true;
                    else if ((tab[i][j] - tab[i+1][j])*(tab[i][j] - tab[i+1][j]) > 1)
                        flag = true;
                    else
                        continue;
                }
            
                else if (i == TEMPTAB1 - 1 && (j != 0 && j != TEMPTAB2))
                {
                    if ((tab[i][j] - tab[i][j-1])*(tab[i][j] - tab[i][j-1]) > 1)
                        flag = true;
                    else if ((tab[i][j] - tab[i][j+1])*(tab[i][j] - tab[i][j+1]) > 1)
                        flag = true;
                    else if ((tab[i][j] - tab[i-1][j])*(tab[i][j] - tab[i-1][j]) > 1)
                        flag = true;
                    else
                        continue;
                }

                else if (j == 0 && (i != 0 && i != TEMPTAB1 - 1))
                {
                    if ((tab[i][j] - tab[i][j+1])*(tab[i][j] - tab[i][j+1]) > 1)
                        flag = true;
                    else if ((tab[i][j] - tab[i-1][j])*(tab[i][j] - tab[i-1][j]) > 1)
                        flag = true;
                    else if ((tab[i][j] - tab[i+1][j])*(tab[i][j] - tab[i+1][j]) > 1)
                        flag = true;
                    else
                        continue;                    
                }

                else if (j == TEMPTAB2 && (i != 0 && i != TEMPTAB1 - 1))
                {
                    if ((tab[i][j] - tab[i][j-1])*(tab[i][j] - tab[i][j-1]) > 1)
                        flag = true;
                    else if ((tab[i][j] - tab[i-1][j])*(tab[i][j] - tab[i-1][j]) > 1)
                        flag = true;
                    else if ((tab[i][j] - tab[i+1][j])*(tab[i][j] - tab[i+1][j]) > 1)
                        flag = true;
                    else
                        continue;                    
                }

                if (flag == true)
                {
                    
                    if (i == 0 && (j != 0 && j != TEMPTAB2))
                        wynik = (double)(tab[i][j-1] + tab[i][j+1] + tab[i+1][j])/3.0;
                    else if (i == TEMPTAB1 - 1 && (j != 0 && j != TEMPTAB2))
                        wynik = (double)(tab[i][j-1] + tab[i][j+1] + tab[i-1][j])/3.0;
                    else if (j == 0 && (i != 0 && i != TEMPTAB1 - 1))
                        wynik = (double)(tab[i][j+1] + tab[i-1][j] + tab[i+1][j])/3.0;
                    else if (j == TEMPTAB2 && (i != 0 && i != TEMPTAB1 - 1))
                        wynik = (double)(tab[i][j-1] + tab[i-1][j] + tab[i+1][j])/3.0;
                    
                    if (wynik - (int)wynik >= 0.5)
                        wynik = (int)wynik + 1;
                    else
                        wynik = (int)wynik;
                    tab[i][j] = wynik;
                }

            }
        }




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