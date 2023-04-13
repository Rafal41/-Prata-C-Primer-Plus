#include <stdio.h>
#define WIERSZE 3
#define KOLUMNY 5
//prototyp funkcji pobierającej zbiór liczb
void pobierz_tab(double tab[]);
//prototyp funkcji pobierającej liczbe typu double
double pobierz_double(void);
//prototyp funkcji zapisującej tablice do tablicy głownej
double wpiszdotab(double tab[][KOLUMNY],double tab1[], double tab2[], double tab3[]);
//prototyp funkcji wyswietlającej tabele
void wyswietl_tab(int wiersze, int kolumny, double tab1[][KOLUMNY]);
//prototyp funkcji obnliczającej srednią z pojedynczego zbioru
double sredniazbr(double tab[]);
//prototyp funkcji obliczającej średnią ze wszystkich wartosci
double sredniatot(double tab[][KOLUMNY]);
//funkcja obliczająca wartosc maksymalną
double maks_wart(double tab1[][KOLUMNY]);


int main(void)
{
    double glowna[WIERSZE][KOLUMNY];
    double tablica1[KOLUMNY];
    double tablica2[KOLUMNY];
    double tablica3[KOLUMNY];
    int i;

    printf("Proszę podać trzy zbiory liczb - 5 liczb w każdym zbiorze\n");
    printf("Podaj pierwszy zbiór 5 liczb typu zmiennoprzecinkowego\n");
    pobierz_tab(tablica1);
    printf("Podaj drugi zbiór 5 liczb typu zmiennoprzecinkowego\n");
    pobierz_tab(tablica2);
    printf("Podaj trzeci zbiór 5 liczb typu zmiennoprzecinkowego\n");
    pobierz_tab(tablica3);
    wpiszdotab(glowna, tablica1, tablica2, tablica3);
    wyswietl_tab(WIERSZE,KOLUMNY,glowna);

    for (i = 0; i < 3; i++)
    {
        printf("ZBIÓR ŚREDNIA\n");
        printf("%1d %15.1lf\n", 1 + i, sredniazbr(glowna[i])/KOLUMNY);
    }
    
    printf("Średnia dla wszystkich wartosci wynosi %.2lf\n", sredniatot(glowna)/(WIERSZE*KOLUMNY));
    
    printf("Wartość maksymalna spośród wsystkich wartosci wynosi %.2lf\n", maks_wart(glowna));

    return 0;
}

/////////////
void pobierz_tab(double tab[])
{
    int i;

    for (i=0; i < KOLUMNY; i++)
        tab[i] = pobierz_double();
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


double wpiszdotab(double tab[][KOLUMNY],double tab1[], double tab2[], double tab3[])
{
    int i;

    for (i=0; i < KOLUMNY; i++)
    {
        tab[0][i] = tab1[i];
        tab[1][i] = tab2[i];
        tab[2][i] = tab3[i];
    }
}

void wyswietl_tab(int wiersze, int kolumny, double tab1[][KOLUMNY])
{
    int i, j;

    for (i = 0; i < wiersze ; i++)
    {
        for (j = 0; j < kolumny; j++)
            printf("%10.2lf", tab1[i][j]);
        printf("\n");
    }
}
/////////////

double sredniazbr(double tab[])
{
    int i;
    double subtot, total;
    
    for (i = 0, subtot = 0; i < KOLUMNY; i++)
        subtot += tab[i];
 
    return subtot;
}

double sredniatot(double tab[][KOLUMNY])
{
    int i,j;
    double subtot, total;
    
    for (i = 0, total = 0; i < WIERSZE; i++)
    {
        for (j = 0, subtot = 0; j < KOLUMNY; j++)
            subtot += tab[i][j];
        total += subtot; 
    }    

    return total;
}


double maks_wart(double tab1[][KOLUMNY])
{
    int i,j;
    double maks = tab1[0][0];

    for (i = 0; i < WIERSZE; i++)
    {
        for (j = 0; j < KOLUMNY; j++)
        {
            if (maks > tab1[i][j])
                continue;
            else
                maks = tab1[i][j];
    
        }
    }
    return maks;
}






