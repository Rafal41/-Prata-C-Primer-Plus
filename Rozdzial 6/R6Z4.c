#include <stdio.h>
int main(void)
{
    const int RZEDY = 6;

    int licznikr, licznikk;
    char x = 'A';

    for (licznikr = 0; licznikr < RZEDY; licznikr++)
    {
        for (licznikk = 0; licznikk < licznikr + 1; licznikk++, x++)
            printf("%c", x);
        printf("\n");
    }
    return 0;

}