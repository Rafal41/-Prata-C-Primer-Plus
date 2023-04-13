/* addaword.c -- uses fprintf(), fscanf(), and rewind() */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX 41
int main(void)
{
    int i = 0; // numer ostatniej pozycji w odczytywanym pliku
    long licznik, koniec; // zmienne do odczytywania swobodnego pliku
    char ch;
    int licznikcyfr = 0 ;
    bool flag = false; //flaga mówiąca czy jest cyfra czy nie
    long pozycja;   //pozycja w odczytywanym pliku

    FILE *fp; 
    char words[MAX];    //tablica zawierajaca dopisywane slowo razem z numerem
    char temp[MAX]; //tablica zawierajaca samo dopisywane slowo
    char numer[16]; //tablica zawierajaca ostatnią pozycje w odczytywanym pliku
    

    //sprawdzenie ostatniego numeru w pliku

    if ((fp = fopen("wordy", "ab")) == NULL)
    {
        fprintf(stdout,"Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }

    fseek (fp, 0L, SEEK_END);
    koniec = ftell(fp);

    for (licznik = 1L ; licznik <= koniec; licznik++)
    {
        fseek(fp, -licznik, SEEK_END);
        ch = getc(fp);
        if (isdigit(ch))
        {
            flag = true;
            pozycja = ftell(fp) - 1L;
            licznikcyfr++;
            //printf("ch = %c, licznikcyfr = %d\n", ch, licznikcyfr);
        }
        else if (!isdigit(ch) && flag == true)
            break;
        
    }
    
    fseek(fp, pozycja, SEEK_SET);
    for (int j = 0; j < licznikcyfr; j++)
    {
        ch = getc(fp);
        //printf("ch = %c\n", ch);
        numer[j] = ch;
        pozycja += 1L;
        fseek(fp, pozycja, SEEK_SET);
    }

    if(licznikcyfr > 0)
        i = atoi(numer);

    fclose(fp);
    
    //printf("i = %d\n", i);

    //dopisywanie nowych pozycji
    if ((fp = fopen("wordy", "a+")) == NULL)
    {
        fprintf(stdout,"Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }
    puts("Enter words to add to the file; press the #");
    puts("key # at the beginning of a line to terminate.");


    while ((fscanf(stdin,"%40s", temp) == 1) && (temp[0] != '#'))
    {
        i++;
        sprintf(words, "%d.", i);
        strcat(words, temp);
        puts(words);
        fprintf(fp, "%s\n", words);
    }
        

    puts("File contents:");
    rewind(fp); /* go back to beginning of file */

    while (fscanf(fp,"%s",words) == 1)
        puts(words);

    puts("Done!");

    if (fclose(fp) != 0)
        fprintf(stderr,"Error closing file\n");

    return 0;
}