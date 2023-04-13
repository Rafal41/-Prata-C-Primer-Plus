#include <stdio.h>
#define ROZMIAR 40
char * wyswodst(char *lan);
int main(void)
{
    
    char lancuch[ROZMIAR];

    printf("Podaj lancuch\n");
    fgets(lancuch, ROZMIAR, stdin);
    puts(wyswodst(lancuch));
    
    return 0;
}

char * wyswodst(char *lan)
{
    while (*lan != '\0' && *lan != ' ')
        lan++;
    if (*lan == '\0')
        lan = NULL; 
    return lan;
}