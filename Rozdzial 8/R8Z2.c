#include <stdio.h>
#include <ctype.h>

int main(void)
{
    const int DOLNA = 32;
    const int GORNA = 126;
    int ch;
    int licznikz;
    licznikz = 0;

    printf("Wpisz jakiś tekst lub jego fragment\n");
    printf("Aby zakończyć wciśnic CTRL+Z\n");
    while ((ch = getchar()) != EOF)
    {
     if (ch >= DOLNA && ch <= GORNA)
          printf("Znak \'%c\' ma kod ASCII %d   ", ch, ch);
     else if (ch == '\n')
          printf("Znak \'\\n\' ma kod ASCII %d   ", ch);
     else if (ch == '\t')
          printf("Znak \'\\t\' ma kod ASCII %d   ", ch);
     else if (ch == 127)
          printf("Znak \'DEL\' ma kod ASCII %d   ", ch);
     else
          printf("Znak \'CTRL+%d\' ma kod ASCII %d   ", ch + 64, ch);

     licznikz++;

     if (licznikz % 10 == 0)
          printf("\n");

     if (ch == '\n')
          licznikz = 0;
    }
    return 0;
}