#include <stdio.h>
#include <string.h>
#define ROZMIAR 40

//prototyp funkcji odwraca kolejność łańcucha
void zamien_kol(char* lan);


int main(void)
{
    char lancuch[ROZMIAR];

    printf("Podaj lancuch.\n");
    fgets(lancuch, ROZMIAR, stdin);
    zamien_kol(lancuch);
    puts(lancuch);
    
    return 0;
}
void zamien_kol(char * lan)
{
    int i;
    char * temp;
    int dl = strlen(lan)-2;

    for (i = 0; i < dl/2 ; i++)
    {
       *temp = lan[i];
       lan[i] = lan[dl-i];
       lan[dl-i] = *temp;
    }
    lan[dl+1] = '\0';
}
