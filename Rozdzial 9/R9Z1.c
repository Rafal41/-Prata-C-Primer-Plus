#include <stdio.h>
// funkcja zwracająca minimum z dwóch wartosci
double min(double x, double y); 

int main(void)
{
    double n, m, minimum;
    printf("Podaj dwie wartości liczbowe zmiennoprzecinowe (q kończy)\n");
    while (scanf("%lf %lf", &n, &m) == 2)
    {
        printf("%lf %lf  \n", n,m);
        minimum = min(n,m);
        printf("%lf \n", minimum);
        printf("Podaj dwie wartości liczbowe zmiennoprzecinowe (q kończy)\n");
    }
    return 0;
}
double min(double x, double y)
{
    printf("Mniejszą wartością jest liczba: \n");
    return (x < y ? x : y);
}