#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
void strlan(int *tab, int num);
int rzucaj(void);
int liczba_rzutow = 0;

int main(void)
{

    int tablica[100];
    const int licz = 100;

    srand ((unsigned int) time(0));
    for (int rzuty = 0; rzuty < licz; rzuty++)
    {
        tablica[rzuty] = rzucaj();
    }

    puts("Oto nieuporządkowana lista:\n");
    for (int k = 0; k < licz; k++)
        printf("%d\n", tablica[k]);
    putchar('\n');

    strlan(tablica,licz);

    puts("Oto uporządkowana lista:\n");
    for (int k = 0; k < licz; k++)
        printf("%d\n", tablica[k]);
    putchar('\n');

    printf("Funkcja rzucaj() została wywołana %d razy\n", liczba_rzutow);
    
    return 0;
}

int rzucaj(void)
{
        ++liczba_rzutow;
        return rand() % 10 + 1;
}

void strlan(int *tab, int num)
{
    int temp;
    int dol, szuk;
    // int k;

    for (dol = 0; dol < num; dol++)
        for (szuk = dol + 1; szuk < num; szuk++)
            if (tab[dol] < tab[szuk])
            {
                temp = tab[dol];
                tab[dol] = tab[szuk];
                tab[szuk] = temp;
            }

    // puts("Oto uporządkowana lista:\n");
    // for (k = 0; k < num; k++)
    //     printf("%d\n", tab[k]);
    // putchar('\n');
}
