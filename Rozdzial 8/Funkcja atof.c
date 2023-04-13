//manuet.c - - techniki realizacji menu
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

    

int main(void)

{
    char we[20];
    char ch;
    int licznikz = 1; //licznik znakow
    int licznikk = 0; // licznik kropek
    int i;
    float num;

    scanf("%s", we);
    printf("Wczytałem %s\n", we);
    
    while (licznikz > 0)
    {
        for (i = 0, licznikz = 0, licznikk = 0; i < strlen(we); i++)
        {
            printf("test1 %c\n", we[i]);
            if (!isdigit(we[i]) && we[i] != '\n')
            {
                printf("test2 %c\n", we[i]);
                if (we[i] != '.')
                {
                    licznikz++;
                    printf("Licznikz %d  we[i] = %c\n", licznikz, we[i]);
                }
                else
                {
                    licznikk++;
                    printf("Licznikk %d we[i] = %c\n", licznikk, we[i]);
                }
            }
        }
        printf("licznikz = %d, licznikk = %d \n", licznikz, licznikk);

        if (licznikz != 0)
        {
            printf("Proszę podać liczbę: ");
            scanf("%s", we);
        }
        else
        {
            if(licznikk > 1)
            {
                printf("Proszę podać liczbę: ");
                scanf("%s", we); 
                licznikz = 1;
            }

            else 
            {
            num = atof(we);
            printf("liczba to %f \n",num);
            }
        }

        // while ((ch = getchar()) != '\n'
        //     putchar(ch);  //pomija błędne dane wejściowe
        // printf(" nie jest liczbą. \nProszę podać liczbę: ");
    }

    return 0;
}

