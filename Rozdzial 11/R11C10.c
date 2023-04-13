#include <stdio.h>
#define ROZMIAR 40
int strl(const char *lan);
int main(void)
{
    
    char lancuch[ROZMIAR];

    printf("Podaj lancuch\n");
    fgets(lancuch, ROZMIAR, stdin);
    strl(lancuch);
    
    return 0;
}

int strl(const char *lan)
{
    int i=0;

    while (*lan++ != '\0')
        i++;
    printf("%d",i);

    return i;
}