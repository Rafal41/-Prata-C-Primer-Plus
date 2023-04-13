#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
    int licznikz, liczniko, licznikn;
    licznikz = 0;
    liczniko = 0;
    licznikn = 0;
    printf("Wpisz jakiś tekst lub jego fragment\n");
    while ((ch = getchar()) != '#')
    {
        if (ch == '\n')
            licznikn++;
        else if (isgraph(ch))
            licznikz++;
        else 
            liczniko++;
        
    }
    printf("Podany tekst składa się z %d znaków drukowalnych, %d odstępów i %d znaków nowej linii\n", licznikz, liczniko, licznikn);
    return 0;
}