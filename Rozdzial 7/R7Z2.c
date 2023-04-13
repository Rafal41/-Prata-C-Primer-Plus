#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
    int licznikz;
    licznikz = 0;

    printf("Wpisz jakiś tekst lub jego fragment\n");
    while ((ch = getchar()) != '#')
    {
       if (ch != '\n')
            printf("Znak \'%c\' ma kod ASCII %d   ", ch, ch);
       else
            printf("Znak \'ENTER\' ma kod ASCII %d   ", ch);

       licznikz++;
       if (licznikz % 8 ==0)
            printf("\n");
    }
    return 0;
}