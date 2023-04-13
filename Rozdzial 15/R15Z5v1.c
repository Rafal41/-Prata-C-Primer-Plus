#include <stdio.h>
#include <limits.h>

void obroc(int num, int przesuniecie);
char * do_binar2(int, char*);
void pokaz_binar(const char *);

int main(void)
{
    unsigned int liczba, shift;

    puts("Podaj liczbę całkowitą");
    scanf("%u", &liczba);
    puts("O ile chcesz przesunać ?");
    scanf("%u", &shift);
    
    obroc(liczba, shift);

    return 0;

}

void obroc(int num, int przesuniecie)
{
    unsigned int maska = 0;
    unsigned int temp;
    unsigned int wartbit = 1;
    unsigned int wynik;
    char bin_lan[CHAR_BIT * sizeof(unsigned int) + 1];
    do_binar2(num, bin_lan);
    pokaz_binar(bin_lan);

    temp = num;
    temp >>= (sizeof(unsigned int)*8 - przesuniecie);
    
    num <<= przesuniecie;

    while (przesuniecie-- > 0)
    {
        maska |= wartbit;
        wartbit <<= 1;
    }   
    maska = maska & temp;

    wynik = num | maska;

    do_binar2(wynik, bin_lan);
    pokaz_binar(bin_lan);

}

char * do_binar2(int n , char * wsk)
{
    int i;
    static int liczba = CHAR_BIT * sizeof(unsigned int);
    for (i = liczba - 1; i >= 0; i--, n >>= 1)
        wsk[i] = (01 & n) + '0';
        wsk[liczba] = '\0';
    return wsk;
}

void pokaz_binar(const char * lan)
{
    int i = 0;
    while (lan[i])
    {
        putchar(lan[i]);
        if (++i % 4 == 0 && lan[i])
            putchar(' ');
    }
    putchar('\n');
}
