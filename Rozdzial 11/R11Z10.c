#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define ROZMIAR 120

void usuwaodst(char *lan); //funkcja usuwająca odstępy z łańcucha

int main(void)
{
    char lancuch[ROZMIAR];
    char * wsk;

    puts("Wprowadz łańcuch. Pusty wiersz kończy program");
    while (fgets(lancuch, ROZMIAR, stdin) != NULL && lancuch[0] != '\n')
    {
        usuwaodst(lancuch);
        puts(lancuch);
        puts("Wprowadz łańcuch. Pusty wiersz kończy program");
    }
    
    return 0;
}

void usuwaodst(char *lan)
{
    int i = 0;
    int licznikodst = 0, licznikzn = 0;
    bool odstep = false;
    char * wsk;

    
    while (lan[i] != '\0' ) 
    {
        if (isspace(lan[i]) && odstep == false)
        {
            odstep = true;
            wsk = &lan[i]; 
            licznikodst++;
        }
        else if (isspace(lan[i]) && odstep == true)
        {
            while (licznikzn > 0)
            {
                *wsk = lan[i-licznikzn];
                wsk++;
                licznikzn--;
            }
            wsk = &lan[i-licznikodst];
            licznikodst++;
        }
        else if (!isspace(lan[i]) && odstep == true)
            licznikzn++;
        else        //!isspace(*lan) && odstep == false
            ;
        i++;
    }
    i = i-licznikodst; // reset wskaznika do lancucha
    while (lan[i] != '\0')
    {
        lan[i] = '\0';
        i++;
    }

}

