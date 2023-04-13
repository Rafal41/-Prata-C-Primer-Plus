#include <stdio.h>

int main(void)
{
    
    int ch;
    int licznik = 0;

    printf("Wpisz dowolny tekst - program policzy znaki\n");
    printf("Aby zakończyć wciśnic CTRL+Z\n");
    while ( (ch = getchar()) != EOF )
    {
        if (ch !='\n')
            licznik++;
    }
    printf("Ilość znaków to %d\n", licznik);
    return 0;
}