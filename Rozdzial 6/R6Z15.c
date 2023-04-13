#include <stdio.h>
#include <string.h>
int main(void)
{
    const int ROZMIAR = 255; 
    int i, rozmiar;
    char slowo[ROZMIAR]; 

    printf("Napisz dowolny tekst\n");
   // scanf("%s", slowo);
    
    i=0;
    for (scanf("%c", &slowo[i]), i = 1;  i < ROZMIAR && slowo[i-1] != '\n'; i++)
    {
        scanf("%c", &slowo[i]);  
    }
    
    // for (i=0;  i < strlen(slowo); i++ ) // wyswietlanie liter w poprawnej kolejnosci na ekranie
    //     printf("%c", slowo[i]);


    for (i = strlen(slowo)-2; i >= 0; i--)   // wyswietlanie liter w odwrotnej kolejnosci na ekranie
        printf("%c", slowo[i]);

    return 0;
}