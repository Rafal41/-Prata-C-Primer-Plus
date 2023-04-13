/* manybook.c -- multiple book inventory */
#include <stdio.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 20 /* maximum number of books */

struct book { /* set up book template */
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

char * s_gets(char * st, int n);
void strlan(struct book *lancuchy[], int num);

int main(void)
{
    struct book library[MAXBKS]; /* array of book structures */
    int count = 0;
    int index;
    float totalval = 0.00;
    struct book *wsk[MAXBKS];

    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");

    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
    {
        wsk[count] = &library[count];
        printf("Now enter the author.\n");
        s_gets(library[count].author, MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f", &library[count++].value);

        while (getchar() != '\n')
            continue; /* clear input line */
        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }
    if (count > 0)
    {
        strlan(wsk, count);
        printf("Here is the list of your books:\n");
        for (index = 0; index < count; index++)
        {
            printf("%s by %s: $%.2f\n", wsk[index]->title,wsk[index]->author, wsk[index]->value);
            totalval += library[index].value;
        }
        
        printf("total value of all books is equal = %.2f$ \n", totalval);
    }
    else
        printf("No books? Too bad.\n");
    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); // look for newline
        if (find) // if the address is not NULL,
            *find = '\0'; // place a null character there
        else
            while (getchar() != '\n')
                continue; // dispose of rest of line
    }
    return ret_val;
}

void strlan(struct book *lancuchy[], int num)
{
    struct book *temp;
    int dol, szuk;
    int k;

    for (dol = 0; dol < num - 1; dol++)
        for (szuk = dol + 1; szuk < num; szuk++)
            if (strcmp(lancuchy[dol]->title, lancuchy[szuk]->title) > 0)
            {
                temp = lancuchy[dol];
                lancuchy[dol] = lancuchy[szuk];
                lancuchy[szuk] = temp;
            }

    // puts("Oto uporządkowana lista:\n");
    // for (k = 0; k < num; k++)
    //     puts(lancuchy[k]);
    //putchar('\n');
}