#include <stdio.h>
void wyswietl(char c, int wysokosc, int szerokosc);
int main(void)
{
    int ch;
    int rzedy, kolumny;
    printf("Podaj znak i dwie liczby całkowite:\n");
    while ((ch = getchar()) != EOF)
    {
        if (scanf("%d %d", &rzedy, &kolumny) != 2)
            break;
        else
            {
                
            wyswietl(ch, rzedy, kolumny);
            while (getchar() == '\n')
                break;
            printf("Podaj kolejny znak i dwie liczby całkowite: \n");
            printf("Aby zakończyć zasymuluj EOF.\n");
            }
    
    }
    printf("Do widzenia.\n");
    return 0;
}

void wyswietl(char c, int wysokosc, int szerokosc)
{
    int rzad, kol;

    for (rzad = 1; rzad <= wysokosc; rzad++)
    {
        for (kol = 1; kol <= szerokosc; kol++)
            putchar(c);
        putchar('\n');
    }
}