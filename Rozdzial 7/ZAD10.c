#include <stdio.h>

int main(void)
{
    char ch;
    printf("Podaj kolejno litery: q, c, h, b\n");
    while ((ch = getchar()) != '#')
    {
        if (ch == '\n')
            ;
        else 
        {
            printf("Krok 1\n");
            if (ch == 'c')
                ;
            else if (ch == 'b')
                break;
            else if (ch == 'h')
                printf("Krok 3\n");
            else
            {
                printf("Krok 2\n");
                printf("Krok 3\n");
            }

        }


    }
    printf("Koniec\n");
    return 0;
}