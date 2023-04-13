#include <stdio.h>
#include "stos.h"

int main(void)
{
    Stos st;
    Item ch;
    Item pozycja;

    InicjujStos(&st);
    puts("Wpisz dowolny lancuch");
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        if (PelnyStos(&st))
        {
            puts("stos jest pełny");
            break;
        }
        else
        {
            PoloznaStos(&st, ch);
        }

    }
    
    while (!PustyStos(&st))
    {
        Pobierz(&st,&pozycja);  
        printf("%c",pozycja);  
    }
    
    WyczyscStos(&st);
    puts("\nto koniec");
    return 0;
}