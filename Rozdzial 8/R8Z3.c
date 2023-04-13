#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int ch;
    int licznikz = 0;
    int licznikm = 0;
    int licznikd = 0;

    printf("Wpisz jakiś tekst lub jego fragment\n");
    printf("Aby zakończyć wciśnic CTRL+Z\n");
    while ((ch = getchar()) != EOF)
    {
     if (islower(ch))
          licznikm++;
     else if (isupper(ch))
          licznikd++;
     else
          licznikz++;
    }
    printf("Podany tekst zawiera %d dużych liter, %d małych liter, %d znaków\n", licznikd, licznikm, licznikz);

    return 0;
}