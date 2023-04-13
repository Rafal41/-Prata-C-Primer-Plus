//kompilowac z plikiem sir.c
#include <stdio.h>
extern int random(void);
extern void srandom(unsigned int ziarno);

int main(void)
{
    int liczba;
    unsigned int ziarno;
    printf("Podaj wartość ziarna\n");
    while (scanf("%d", &ziarno) == 1)
    {
        srandom(ziarno);
        for (liczba = 0; liczba < 5; liczba++)
            printf("%d\n", random());
        printf("Podaj następną wartość ziarna. k oznacza koniec\n");
    }

    return 0;
}