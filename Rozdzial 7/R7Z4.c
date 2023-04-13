#include <stdio.h>

int main(void)
{
    char ch;
    int licznikz;
    licznikz = 0;

    printf("Wpisz jakiś tekst lub jego fragment\n");
    while ((ch = getchar()) != '#')
    {
          if (ch == '.')
          {
               printf("!");
               licznikz++;
          }
          else if (ch == '!')
          {
               printf("!!");
               licznikz++;
          }
          else
               printf("%c", ch);
    }
    printf("\n");
    printf("liczba zamian to %d", licznikz);
    return 0;
}