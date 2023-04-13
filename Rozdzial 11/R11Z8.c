#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define ROZMIAR 40

char * zawiera_lan(char *lan1, char *lan2); //funkcja sprawdzająca czy jeden łańcuch zawiera się w drugim

int main(void)
{
    char lancuch1[ROZMIAR];
    char lancuch2[ROZMIAR];
    char * wsk;

    printf("Podaj pierwszy lancuch.\n");
    fgets(lancuch1, ROZMIAR, stdin);
    printf("Podaj drugi lancuch.\n");
    fgets(lancuch2, ROZMIAR, stdin);
    wsk = zawiera_lan(lancuch1, lancuch2);
    puts(wsk);
    
    return 0;
}

char * zawiera_lan(char *lan1, char *lan2)
{
    int licznik1 = 0, licznik2 = 0;
    bool flag = false;
    int dl1 = strlen(lan1);
    int dl2 = strlen(lan2);
    char * wsk;

    if (dl1 < dl2)
        return NULL;
    
    while (lan1[licznik1] != '\0' && lan2[licznik2] != '\0' && lan2[licznik2] != '\n')
    {
        if (lan1[licznik1] == lan2[licznik2] && flag == false)
        {
            flag = true;
            wsk = &lan1[licznik1];
            licznik2++;
        }
        else if (lan1[licznik1] == lan2[licznik2] && flag == true)
            licznik2++;

        else        //lan1[licznik1] != lan2[licznik2]
        {
            flag = false;
            wsk = NULL;
            licznik2 = 0; //reset licznika2
        }

        licznik1++;
    }

    return wsk;
}

