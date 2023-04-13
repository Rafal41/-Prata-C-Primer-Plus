#include <stdio.h>
int main(void)
{
    const int RZEDY = 4;
    const int KOLUMNY = 8;

    int licznikr, licznikk;
    char x = '$';

    for (licznikr = 0; licznikr < RZEDY; licznikr++)
    {
        for (licznikk = 0; licznikk < KOLUMNY; licznikk++)
            printf("%c", x);
        printf("\n");
    }
    return 0;

}