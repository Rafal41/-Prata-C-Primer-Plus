#include <stdio.h>
int main(void)
{
    const int RZEDY = 5;

    int licznikr, licznikk;
    char x = '$';

    for (licznikr = 0; licznikr < RZEDY; licznikr++)
    {
        for (licznikk = 0; licznikk <= licznikr; licznikk++)
            printf("%c", x);
        printf("\n");
    }
    return 0;

}