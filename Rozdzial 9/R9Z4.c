#include <stdio.h>
// funkcja obliczajaca srednia harmoniczna z liczb double
double obl_srharm(double liczba1, double liczba2); 
// funkcja pobierająca liczby double
double pobierz_double(void);


int main(void)
{
    double x1, x2;
    double sr_harm;

    printf("Ten program oblicza srednia harmoniczna z dwoch liczb zmiennoprzecinkowych.\n");
    printf("Podaj pierwszą liczbę:\n");
    x1 = pobierz_double();
    printf("Teraz podaj drugą liczbę:\n");
    x2 = pobierz_double();
    
    sr_harm = obl_srharm(x1, x2);
    return 0;
}
double obl_srharm(double liczba1, double liczba2)
{
    double srarytm, srharm;

    srarytm = (1/liczba1 + 1/liczba2)/2;
    srharm = 1/srarytm;
    printf("Srednia harmoniczna liczb %.4lf i %.4lf wynosi %.4lf\n", liczba1, liczba2, srharm);

    return srharm;
}



double pobierz_double(void)
{
    double we;
    char ch;

    while (scanf("%lf", &we) != 1)
    {
        while ((ch = getchar()) != '\n')
            putchar(ch);  //pomija błędne dane wejściowe
        printf(" nie jest liczbą całkowitą. \nProszę podać wartość całkowitą: ");
    }
    return we;
}