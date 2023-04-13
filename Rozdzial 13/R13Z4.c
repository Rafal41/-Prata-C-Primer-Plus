#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main (int argc, char *argv[])
{
    int ch;
    FILE *wp;
    
    for (int i = 1; i < argc; i++)
    {
        if ((wp = fopen(argv[i], "r")) == NULL)
        {
            printf("Ne mozna otworzyc %s\n", argv[i]);
            exit(EXIT_FAILURE);
        }

        //wyswietlanie zawartosci
        while ((ch = getc(wp)) != EOF)
            putc(ch,stdout);

        fclose(wp);
    }

    return 0;
}