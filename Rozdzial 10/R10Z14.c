#include <stdio.h>

//prototyp funkcji pobierającej zbiór liczb
void pobierz_tab(int cl, double tab[]);
//prototyp funkcji pobierającej liczbe typu double
double pobierz_double(void);
//prototyp funkcji zapisującej tablice do tablicy głownej
double wpiszdotab(int cl, double tab[][cl],double tab1[], double tab2[], double tab3[]);
//prototyp funkcji wyswietlającej tabele
void wyswietl_tab(int rw, int cl, double tab1[rw][cl]);
//prototyp funkcji obnliczającej srednią z pojedynczego zbioru
double sredniazbr(int cl, double tab[]);
//prototyp funkcji obliczającej średnią ze wszystkich wartosci
double sredniatot(int rw, int cl, double tab[][cl]);
//funkcja obliczająca wartosc maksymalną
double maks_wart(int rw, int cl, double tab[][cl]);


int main(void)
{
    int rw = 3, cl = 5; // rozmiary tablicy
    double glowna[rw][cl];
    double tablica1[cl];
    double tablica2[cl];
    double tablica3[cl];
    int i;

    printf("Proszę podać trzy zbiory liczb - 5 liczb w każdym zbiorze\n");
    printf("Podaj pierwszy zbiór 5 liczb typu zmiennoprzecinkowego\n");
    pobierz_tab(cl, tablica1);
    printf("Podaj drugi zbiór 5 liczb typu zmiennoprzecinkowego\n");
    pobierz_tab(cl, tablica2);
    printf("Podaj trzeci zbiór 5 liczb typu zmiennoprzecinkowego\n");
    pobierz_tab(cl, tablica3);
    wpiszdotab(cl, glowna, tablica1, tablica2, tablica3);
    wyswietl_tab(rw,cl,glowna);

    for (i = 0; i < 3; i++)
    {
        printf("ZBIÓR ŚREDNIA\n");
        printf("%1d %15.1lf\n", 1 + i, sredniazbr(cl, glowna[i])/cl);
    }
    
    printf("Średnia dla wszystkich wartosci wynosi %.2lf\n", sredniatot(rw, cl, glowna)/(rw*cl));
    
    printf("Wartość maksymalna spośród wsystkich wartosci wynosi %.2lf\n", maks_wart(rw, cl, glowna));

    return 0;
}

/////////////
void pobierz_tab(int cl, double tab[])
{
    int i;

    for (i=0; i < cl; i++)
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


double wpiszdotab(int cl, double tab[][cl], double tab1[], double tab2[], double tab3[])
{
    int i;

    for (i=0; i < cl; i++)
    {
        tab[0][i] = tab1[i];
        tab[1][i] = tab2[i];
        tab[2][i] = tab3[i];
    }
}

void wyswietl_tab(int rw, int cl, double tab1[rw][cl])
{
    int i, j;

    for (i = 0; i < rw ; i++)
    {
        for (j = 0; j < cl; j++)
            printf("%10.2lf", tab1[i][j]);
        printf("\n");
    }
}
/////////////

double sredniazbr(int cl, double tab[])
{
    int i;
    double subtot, total;
    
    for (i = 0, subtot = 0; i < cl; i++)
        subtot += tab[i];
 
    return subtot;
}

double sredniatot(int rw, int cl, double tab[][cl])
{
    int i,j;
    double subtot, total;
    
    for (i = 0, total = 0; i < rw; i++)
    {
        for (j = 0, subtot = 0; j < cl; j++)
            subtot += tab[i][j];
        total += subtot; 
    }    

    return total;
}


double maks_wart(int rw, int cl, double tab1[][cl])
{
    int i,j;
    double maks = tab1[0][0];

    for (i = 0; i < rw; i++)
    {
        for (j = 0; j < cl; j++)
        {
            if (maks > tab1[i][j])
                continue;
            else
                maks = tab1[i][j];
    
        }
    }
    return maks;
}






