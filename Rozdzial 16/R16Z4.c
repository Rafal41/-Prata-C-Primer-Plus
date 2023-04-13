#include <stdio.h>
#include <math.h>
#include <time.h>

void opoznij(double);

int main (void)
{
    clock_t start, end, mid;
    double opoznienie;

    puts("Podaj czas opoznienia w sekundach");
    scanf("%lf", &opoznienie);

    start = clock();
    opoznij(opoznienie);
    end = clock();

    printf("start = %ld, end = %ld, mid= %ld\n",  start, end, mid);
    printf("start w s= %lf, end w s = %lf\n",(double) start/CLOCKS_PER_SEC, (double) end/CLOCKS_PER_SEC);

    printf("(end-start)/cps = %lf\n",  (double)(end - start)/CLOCKS_PER_SEC);  
    double time_elapsed = (double) (end - start)/CLOCKS_PER_SEC;
    printf("%lf\n",  time_elapsed);  

    return 0;
}

void opoznij(double t)
{
    clock_t start, end;

    start = clock();

    do
    {
        end = clock();
    } while ( (double) (end - start)/CLOCKS_PER_SEC < t);
    // for (int i = 0; i < t; i++)
    //     printf("i= %d\n", i);
 }