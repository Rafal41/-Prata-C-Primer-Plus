#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    char ch;
    int licznik = 0;
    bool flaga = false;

    printf("Wpisz jakiś tekst lub jego fragment\n");
    while ((ch = getchar()) != '#')
    {
          if (ch == 'o' && !flaga)
          {
               flaga = true;
          }
          else if (ch == 't' && flaga)
          {
               licznik++;
               flaga = false;
          }
    }
    printf("\n");
    printf("liczba powtórzeń ciągu znaków \"ot\" to %d", licznik);
    return 0;
}