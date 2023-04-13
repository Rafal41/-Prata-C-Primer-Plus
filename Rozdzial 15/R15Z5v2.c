#include <stdio.h>
#include <limits.h>

void obroc(int num, int przesuniecie);
void do_binar(unsigned int n);
char * do_binar2(int, char*);
void pokaz_binar(const char *);

int main(void)
{
    unsigned int liczba, shift;

    puts("Podaj liczbę całkowitą");
    scanf("%u", &liczba);
    puts("O ile chcesz przesunać ?");
    scanf("%u", &shift);

    do_binar(liczba);
    putchar('\n');
    obroc(liczba, shift);

    return 0;

}

void obroc(int num, int przesuniecie)
{
    unsigned int maska = 0, maska2 = 0;
    unsigned int temp = num;
    unsigned int wartbit = 1;
    int stopien = num;
    int licznik = 0;
    // okreslenie wielkosci przesuniecia
    while (stopien >= 1)
    {
        stopien /= 2;
        licznik++;
    }

    temp >>= (licznik - przesuniecie);
    //przesuniecie bitow w zadanej wartosci
    num <<= przesuniecie;
    // stworzenie masek
    while (przesuniecie-- > 0)
    {
        maska |= wartbit;
        wartbit <<= 1;
    } 

    wartbit = 1;    
    while (licznik-- > 0)       
    {
        maska2 |= wartbit;      // maska przyslaniajaca początek
        wartbit <<= 1;
    }     

    // obracanie wartosci
    num &= maska2;
    maska = maska & temp;
    do_binar(num | maska);
    putchar('\n');
}


void do_binar(unsigned int n)
{
    int r;

    r = n % 2;
    if (n >= 2)
        do_binar(n/2);
    putchar(r == 0 ? '0': '1');
    
    return;

}