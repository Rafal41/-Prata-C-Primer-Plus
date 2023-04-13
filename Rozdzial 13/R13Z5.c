/* append.c -- appends files to a file */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
//#define SLEN 81
void append(FILE *source, FILE *dest);
//char * s_gets(char * st, int n);
int main(int argc, char *argv[])
{
    FILE *fa, *fs; // fa for append file, fs for source file
    int files = 0; // number of files appended
    // char file_app[SLEN]; // name of append file
    // char file_src[SLEN]; // name of source file
    int ch;

    // puts("Enter name of destination file:");
    // s_gets(file_app, SLEN);
    if (argc == 1)
    {
        printf("Wrong number of arguments.\n");
        printf("The way to use: %s destination_file source_file1 source_file2 ...\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (argc == 2)
    {
        printf("Wrong number of arguments. Please use at least one source file\n");
        printf("The way to use: %s destination_file source_file1 source_file2 ...\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fa = fopen(argv[1], "a+")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
    {
        fputs("Can't create output buffer\n", stderr);
        exit(EXIT_FAILURE);
    }

    //puts("Enter name of first source file (empty line to quit):");
    //for (s_gets(file_src, SLEN) && file_src[0] != '\0')
    for (int i = 2; i < argc; i++)
    {
        // if ((fs = fopen(argv[i], "r")) == NULL)
        // {
        //     fprintf(stderr, "Can't open %s\n", argv[i]);
        //     exit(EXIT_FAILURE);
        // }

        if (strcmp(argv[1], argv[i]) == 0)
            fputs("Can't append file to itself\n",stderr);
        else if ((fs = fopen(argv[i], "r")) == NULL)
            fprintf(stderr, "Can't open %s\n", argv[i]);
        else
        {
            if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
            {
                fputs("Can't create input buffer\n",stderr);
                continue;
            }

            append(fs, fa);

            if (ferror(fs) != 0)
                fprintf(stderr,"Error in reading file %s.\n", argv[i]);
                
            if (ferror(fa) != 0)
                fprintf(stderr,"Error in writing file %s.\n", argv[1]);
                
            fclose(fs);
            files++;
            printf("File %s appended.\n", argv[i]);
            //puts("Next file (empty line to quit):");
        }
    }

    printf("Done appending. %d files appended.\n", files);

    rewind(fa);

    printf("%s contents:\n", argv[1]);
    while ((ch = getc(fa)) != EOF)
        putchar(ch);

    puts("Done displaying.");
    fclose(fa);
    return 0;
}

void append(FILE *source, FILE *dest)
{
    size_t bytes;
    static char temp[BUFSIZE]; // allocate once

    while ((bytes = fread(temp,sizeof(char),BUFSIZE,source)) > 0)
        fwrite(temp, sizeof (char), bytes, dest);
}

// char * s_gets(char * st, int n)
// {
//     char * ret_val;
//     char * find;

//     ret_val = fgets(st, n, stdin);
//     if (ret_val)
//     {
//         find = strchr(st, '\n'); // look for newline
//         if (find) // if the address is not NULL,
//             *find = '\0'; // place a null character there
//         else
//             while (getchar() != '\n')
//                 continue;
//     }
//     return ret_val;
// }