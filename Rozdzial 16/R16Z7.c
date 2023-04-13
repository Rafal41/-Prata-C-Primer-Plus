#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void pokaz_tablice (const double tab[], int n);
double * nowa_tablica(int n, ...);

int main(void)
{
    double *w1;
    double *w2;
    w1 = nowa_tablica(5, 1.2, 2.3, 3.4, 4.5, 5.6);
    w2 = nowa_tablica(4, 100.0, 20.0, 8.08, -1890.0);

    pokaz_tablice(w1,5);
    pokaz_tablice(w2,4);

    free(w1);
    free(w2);
    return 0;
}

void pokaz_tablice (const double tab[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%10.2lf ", tab[i]);

    putchar('\n');

}

double * nowa_tablica(int n, ...)
{
    double * wsk;
    va_list dane;
    va_start(dane, n);

    wsk = (double *) malloc(n * sizeof(double));

    for (int i = 0; i < n; i++)
        wsk[i] = va_arg(dane, double);

    va_end(dane);

    return wsk;
}