#include <stdio.h>
#include <math.h>
#define ROZMIAR 10

void przeksztalc(double sourcetab[], double targettab[], int num, double (*fnc)(double x, double y));
void przeksztalc2(double sourcetab[], double targettab[], int num, double (*fnc)(double x));
double dodaj(double x, double y);
double odejmij(double x, double y);
//void przeksztalc2(double sourcetab[], double targettab[], int num, double power(double x, double y));
int main(void)
{
    double tab1[ROZMIAR] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    double tab2[ROZMIAR];


    przeksztalc(tab1, tab2, ROZMIAR, pow);  // potegowanie
    for (int i = 0; i < ROZMIAR; i++)
        printf("liczba = %lf, liczbadokw = %lf\n", tab1[i], tab2[i]);

    przeksztalc2(tab1, tab2, ROZMIAR, sin);  //sinus
    for (int i = 0; i < ROZMIAR; i++)
        printf("liczba = %lf, liczbasin = %lf\n", tab1[i], tab2[i]);

    przeksztalc(tab1, tab2, ROZMIAR, dodaj);  // dodawanie
    for (int i = 0; i < ROZMIAR; i++)
        printf("liczba = %lf, liczba+2 = %lf\n", tab1[i], tab2[i]);

    przeksztalc(tab1, tab2, ROZMIAR, odejmij);  // dodawanie
    for (int i = 0; i < ROZMIAR; i++)
        printf("liczba = %lf, liczba-2 = %lf\n", tab1[i], tab2[i]);
    return 0;
}

void przeksztalc(double sourcetab[], double targettab[], int num, double (*fnc)(double x, double y))
{
    for (int i = 0; i < num; i++)
        targettab[i] = (*fnc)(sourcetab[i],2);

}
void przeksztalc2(double sourcetab[], double targettab[], int num, double (*fnc)(double x))
{
    for (int i = 0; i < num; i++)
        targettab[i] = (*fnc)(sourcetab[i]);
}



double dodaj(double x, double y)
{
    return x + y;
}

double odejmij(double x, double y)
{
    return x - y;
}