/* qsorter.c -- using qsort to sort groups of numbers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM 10
#define SIZE 40

struct person {
    char name[SIZE];
    char surname[SIZE];
};

void showarray(const struct person ar[], int n);
int mycomp(const void * p1, const void * p2);

int main(void)
{
    struct person vals[NUM] = {
        {"Rafal","Nowak"},
        {"Tomek","Nowak"},
        {"Krzys","Nowak"},
        {"Kamil","Laszcyk"},
        {"Michal","Laszczyk"},
        {"Tadeusz","Rydz"},
        {"Walerian","Kun"},
        {"Jan","Zab"},
        {"Marek","Tryc"},
        {"Michal","Wodz"},
    };

    puts("\nRandom list:");
    showarray(vals, NUM);
    qsort(vals, NUM, sizeof(struct person), mycomp);
    puts("\nSorted list:");
    showarray(vals, NUM);

    return 0;
}


void showarray(const struct person ar[], int n)
{
    int index;

    for( index = 0; index < n; index++)
        printf("%s %s\n", ar[index].name, ar[index].surname);
}

/* sort by increasing value */
int mycomp(const void * p1, const void * p2)
{
    /* need to use pointers to double to access values */
    const struct person * a1 = (const struct person *) p1;
    const struct person * a2 = (const struct person *) p2;
    int wyn;

    wyn = strcmp(a1->surname, a2->surname);
    if (wyn != 0)
        return wyn;
    else
        return strcmp(a1->name, a2->name);
  
}