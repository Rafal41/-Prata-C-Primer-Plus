#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#define ROZMIAR 80

int main(void)
{
    char ch;
    int licznikwl = 0, licznikml = 0, licznikcyfr = 0, licznikodst = 0, liczniksl = 0;
    int i;
    bool flag;
    puts("Wprowadz łańcuch. Podaj CTRL+Z żeby skończyć");
    while ((ch = getchar()) != EOF)
    {
   
            if (isupper(ch))
                licznikwl++;
            else if (islower(ch))
                licznikml++;
            else if (isdigit(ch))
                licznikcyfr++;
            else if (isspace(ch))
                licznikodst++;
        
            if (!isspace(ch) && !flag)
            {
                flag = true;
                liczniksl++;
            }
            
            if (isspace(ch) && flag)
                flag = false;
            
       
    }
    printf("liczba słów: %d, liczba wielkich liter: %d, liczba małych liter: %d, liczba cyfr: %d, liczba odstępów: %d", liczniksl-1, licznikwl-1, licznikml, licznikcyfr, licznikodst-1); //wyrzuca ostatni ENTER i CTRL+Z

    return 0;
}
