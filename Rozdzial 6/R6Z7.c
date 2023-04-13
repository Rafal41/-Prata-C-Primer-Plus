
#include <stdio.h>
#include <string.h>
int main(void)
{
    
    int i, rozmiar;
    char slowo[rozmiar]; 

    printf("Podaj dowolne slowo\n");
    scanf("%s", slowo);
    rozmiar = strlen(slowo);

    //     for (i = 0; i <= strlen(slowo); i++)   // wyswietlanie liter w poprawnej kolejnosci na ekranie      
    //          printf("%c", slowo[i]);

    //  printf("\n");

        for (i = strlen(slowo)-1; i >= 0; i--)   // wyswietlanie liter w odwrotnej kolejnosci na ekranie
            printf("%c", slowo[i]);

    return 0;
}