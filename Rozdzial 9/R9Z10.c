// binar.c - wyswietla liczbe calkowita w postaci dwojkowej
#include <stdio.h>
void do_podst_n(unsigned long n, int system);

int main(void)
{
    unsigned long liczba;
    int notacja;
    printf("Podaj liczbe calkowita (q konczy program):\n");
    while (scanf("%ld", &liczba) == 1)
    {
        printf("Podaj system liczbowy (wartosc z przedzialu od 2 do 10):\n");
        scanf("%d", &notacja);
        while (notacja < 2 || notacja > 10)
        {
            printf("Podaj system liczbowy (wartosc z przedzialu od 2 do 10):\n");  
            scanf("%d", &notacja);
        }

        do_podst_n(liczba, notacja);
        putchar('\n');
        printf("Podaj liczbe calkowita (q konczy program):\n");
    }
    printf("Gotowe.\n");
    return 0;
}

void do_podst_n(unsigned long n, int system)
{
    int r;

    r = n % system;
    if (n >= system)
        do_podst_n(n/system, system);
    printf("%d",(r == 0 ? 0 : r));

}