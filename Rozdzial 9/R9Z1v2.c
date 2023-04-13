#include <stdio.h>
// funkcja zwracająca minimum z dwóch wartosci
void min(double * x, double * y); 

int main(void)
{
    double n, m, minimum;
    printf("Podaj dwie wartości liczbowe zmiennoprzecinowe (q kończy)\n");
    while (scanf("%lf %lf", &n, &m) == 2)
    {
        printf("%lf %lf  \n", n,m);
        min(&n,&m);
        
        printf("Podaj dwie wartości liczbowe zmiennoprzecinowe (q kończy)\n");
    }
    return 0;
}
void min(double * x, double * y)
{
    printf("Mniejszą wartością jest liczba: %lf \n", *x < *y ? *x : *y);

}