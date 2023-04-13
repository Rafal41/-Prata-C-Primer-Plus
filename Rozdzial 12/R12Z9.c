#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include <stdbool.h>
#define ROZMIAR 40


int main(void)
{
    int liczbaslow; 
    char **wsk;
    int i = 0;
    bool flag = false;
    int licznikliter = 0;
    char *wskini, *wskdoc;
    int j = 0;


    printf("Podaj liczbe slow do wprowadzenia: ");
    scanf("%d", &liczbaslow);
    getchar(); // odrzuca enter

    
    char tablicadanych[liczbaslow*ROZMIAR];
    wsk = (char **) malloc(liczbaslow * sizeof(char *));

    printf("Wprowadz %d slow:\n", liczbaslow);
    fgets(tablicadanych, liczbaslow*ROZMIAR, stdin);

    while (tablicadanych[i] != '\0')
    {
        if (isalpha(tablicadanych[i]) && flag == false)
        {
            flag = true;
            licznikliter++;
            wskini = &tablicadanych[i];
        }
        else if (isalpha(tablicadanych[i]) && flag == true)
        {
            licznikliter++;
        }
        else if (isspace(tablicadanych[i]) && flag == true)
        {
            //printf("%d\n", licznikliter);
            wskdoc = (char *) malloc(licznikliter * sizeof(char)+1);
            strncpy(wskdoc, wskini, licznikliter);
            wskdoc[licznikliter] = '\0';
            wsk[j] = wskdoc;
            licznikliter = 0;
            j++;
            flag = false;
        }
        i++;
    }

    //puts(tablicadanych);

    for (int i = 0; i < liczbaslow; i++)
    {
        puts(*(wsk+i));
    }

    free(wsk);
    free(wskdoc);
    return 0;
}