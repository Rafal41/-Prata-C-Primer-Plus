#include <stdio.h>
#define ROZMIAR 40
char * wyswodst(char *lan, char znak);
int main(void)
{
    
    char lancuch[ROZMIAR];
    char ch;
    char * wsk = "a";

    while (wsk != NULL)
    {
        printf("Podaj lancuch.\n");
        fgets(lancuch, ROZMIAR, stdin);
        printf("Podaj znak jaki chcesz znalezc w tym łańcuchu. CTRL+Z kończy\n");
        ch = getchar();
        wsk = wyswodst(lancuch,ch);
        puts(wsk);
    }
    
    puts("Podano wartość która odpowiada wskaźnikowi zerowemu");

    return 0;
}

char * wyswodst(char *lan, char znak)
{
    while (*lan != '\0' && *lan != znak)
        lan++;
    if (*lan == '\0')
        lan = NULL; 
    return lan;
}