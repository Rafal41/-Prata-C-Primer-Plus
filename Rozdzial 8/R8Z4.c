#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main(void)
{
    int ch;
    int licznikl = 0;
    int liczniks = 0;
    bool w_slowie = false;

    printf("Wpisz jakiś tekst lub jego fragment\n");
    printf("Aby zakończyć wciśnic CTRL+Z\n");
    while ((ch = getchar()) != EOF)
    {
     //liczy literki
     if (islower(ch))
          licznikl++;
     else if (isupper(ch))
          licznikl++;
     
     if (!isspace(ch) && !w_slowie)
     {
          w_slowie = true; //zaczeło sie nowe slowo
          liczniks++;
     }
     
     if (isspace(ch) && w_slowie)
          w_slowie = false; // znajduje koniec slowa
    }
    

    printf("Podany tekst zawiera %d liter i %d słow - daje to średnią ilość liter na słowo równą %d \n", licznikl, liczniks, licznikl/liczniks);

    return 0;
}