// program wyświetla numer litery w alfabecie
#include <stdio.h>
#include <ctype.h>
// funkcja pobierająca znaki
char pobierz_znak(void);
// funkcja wyswietla numer litery w alfabecie
int numer_litery(char zn);

int main(void)
{
    
    int ch;
    int num;
    
    printf("Podaj literę, a ja wyświetlę jej numer w alfabecie\n");
    while ((ch = pobierz_znak()) != EOF)
    {
        
        num = numer_litery(ch);
        printf("Numer wybranej przez ciebie litery to: (-1 gdy znak nie jest literą)\n");
        printf("%d\n", num);
        printf("Podaj literę, a ja wyświetlę jej numer w alfabecie\n");
    }
    
    return 0;
}


char pobierz_znak(void)
{
    int ch;

    ch = getchar();
    if (ch == EOF)
        return ch;
    while (ch < 32 || ch > 176)
    {
        printf("Podaj poprawny znak\n");
        ch = getchar();
    }
    while (getchar() != '\n' && getchar() != EOF)
        continue;
   
    return ch;
}

int numer_litery(char zn)
{
    char znak;
    int numer;

    znak = toupper(zn);
    numer = (int) znak - 64;
    if (numer >= 1 && numer <= 26)
    {
        printf("Ten znak jest literą\n"); 
        return numer;
    }
    else
    {
        printf("Ten znak nie jest literą\n");
        return -1;
    }
}