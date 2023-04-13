/* petclub.c -- use a binary search tree */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "drzewo.h"
#define SLEN 20

char menu(void);
void addpet(Tree * pt, char item[]);
void droppet(Tree * pt);
void showpets(const Tree * pt);
void findpet(const Tree * pt);
void printitem(Item item);
void uppercase(char * str);

void interp(char temporary[]);

int main(void)
{
    Tree pets;
    char choice;
    FILE * wp;
    char temp[SLEN];

    InitializeTree(&pets);

    if ((wp = fopen("pliktekstowy.txt", "r")) == NULL)
        {
            printf("Ne mozna otworzyc %s\n", "pliktekstowy.txt");
            exit(EXIT_FAILURE);
        }

    while (fscanf(wp,"%s", temp) != EOF)
    {
        interp(temp);
        addpet(&pets, temp);
    }
    

    while ((choice = menu()) != 'q')
    {
        switch (choice)
        {
            case 'a' : showpets(&pets);
                         break;
            case 'b' : findpet(&pets);
                        break;
            default : puts("Switching error");
        }
    }
    DeleteAll(&pets);
    puts("Bye.");
    return 0;
}
void interp(char temporary[])
{
    char * find;

    find = strpbrk(temporary, ",.()!?\"\'"); // look for newline
    if (find) // if the address is not NULL,
        *find = '\0'; // place a null character there
}

char menu(void)
{
    int ch;

    puts("Enter the letter corresponding to your choice:");
    puts("a) show all words ");
    puts("b) show a number of word occuring");
    puts("q) quit");
    while ((ch = getchar()) != EOF)
    {
        while (getchar() != '\n') /* discard rest of line */
            continue;
        ch = tolower(ch);
        if (strchr("abq",ch) == NULL)
            puts("Please enter an a, b, or q:");
        else
            break;
    }
    if (ch == EOF) /* make EOF cause program to quit */
        ch = 'q';
    return ch;
}

void addpet(Tree * pt, char item[])
{
    Item temp;
    if (TreeIsFull(pt))
        puts("No room in the club!");
    else
    {
        strcpy(temp.word,item);
        temp.count = 1;
        uppercase(temp.word);

        AddItem(&temp, pt);
    }
}

void showpets(const Tree * pt)
{
    if (TreeIsEmpty(pt))
        puts("No entries!");
    else
        Traverse(pt, printitem);
}

void printitem(Item item)
{
    printf("Word: %-19s Count: %-19u\n", item.word, item.count);
}

void findpet(const Tree * pt)
{
    Item temp;
    Item *wsk = &temp;
    Pair result;

    if (TreeIsEmpty(pt))
    {
        puts("No entries!");
        return; /* quit function if tree is empty */
    }
    puts("Please enter name of word you wish to find:");
    scanf("%s", temp.word);
    uppercase(temp.word);

    result = SeekItem(wsk, pt);
    if (result.child != NULL)
        printf("Word: %-19s Count: %-19u\n", result.child->item.word, result.child->item.count);
    else
        printf("Word: %-19s is not a member.\n",temp.word);


}



void uppercase(char * str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}

