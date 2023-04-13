#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main(void)
{
    int wynik;
    char wybor;

    srand ((unsigned int) time(0));
    printf("Czy chcesz rzucic kostką? T/N\n");
    wybor = getchar();
    wybor = toupper(wybor);
    while (wybor == 'T')
    {
        wynik = rand() % 2 + 1;
        if (wynik == 1)
            puts("orzeł");
        else
            puts("reszka");

        printf("Czy chcesz rzucic jeszcze raz? T/N\n");
        while (getchar() != '\n')
            continue;
        wybor = getchar();
        wybor = toupper(wybor);
    }
    return 0;
}

