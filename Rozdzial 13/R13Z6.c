// reducto.c -- reduces your files by two-thirds!
#include <stdio.h>
#include <stdlib.h> // for exit()
#include <string.h>
#define LEN 40

int main(void)
{
    FILE *in, *out; // declare two FILE pointers
    int ch;
    char namesrc[LEN]; // input filename
    char name[LEN]; // storage for output filename
    int count = 0;
    char *wsk;

    printf("Podaj nazwę pliku zrodlowego\n");
    scanf("%s", namesrc);
  
    // set up input
    if ((in = fopen(namesrc, "r")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n", namesrc);
        exit(EXIT_FAILURE);
    }

    // set up output

    strncpy(name,namesrc, LEN - 5); 
    wsk = strchr(name,'.');
    *wsk = '\0';
   
    strcat(wsk,".red"); // append .red

    if ((out = fopen(name, "w")) == NULL)
    { // open file for writing
        fprintf(stderr,"Can't create output file.\n");
        exit(3);
    }

    // copy data
    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out); // print every 3rd char

    // clean up
    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr,"Error in closing files\n");
    return 0;
}