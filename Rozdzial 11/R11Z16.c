#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char ch;

    puts("Wprowadz łańcuch. Podaj CTRL+Z żeby skończyć");
    while ((ch = getchar()) != EOF)
    {
        if (argc < 2)
            putchar(ch);
        else
            if (!strcmp (argv[1],"-p")) //lancuchy są identyczne
                putchar(ch);
            else if (!strcmp (argv[1],"-u"))
                putchar(toupper(ch));
            else if (!strcmp (argv[1],"-l"))
                putchar(tolower(ch));
    }       
    return 0;
}
