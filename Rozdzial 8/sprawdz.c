//sprawdz.c - - sprawdzanie poprawnosci danych wejściowych
#include <stdio.h>
#include <stdbool.h>
//sprawdź czy wejscie jest liczbą całkowitą
long pobierz_long(void);
//sprawdź prawidłowość podanych granic zakresu
bool zle_granice(long poczatek, long koniec, long dolna, long gorna);
// oblicz sume kwadratow liczb calkowitch z zakresu od a do b
double suma_kwadr(long a, long b);
int main(void)
{
    const long MIN = -10000000; //dolna granica zakresu
    const long MAX = +10000000; //górna granica zakresu
    long start;                 //początek przedziału
    long stop;                  //koniec przedziału
    double wynik;              

    printf("Program oblicza sumę kwadratow liczb całkowitych.\n"
           "Dolna granica przedzialu nie powinna byc "
           "mniejsza od -10000000.\n"
           "Górna granica przedziału nie powinna przekraczać +10000000. \n"
           "Podaj granice przedziału"
           " (podanie 0 dla obu oznacza koniec).\n"
           "Dolna granica: ");
    start = pobierz_long();
    printf("Górna granica: ");
    stop = pobierz_long();
    while (start != 0 || stop != 0)
    {
        if (zle_granice (start, stop, MIN, MAX))
            printf("spróbój ponownie \n");
        else
        {
            wynik = suma_kwadr(start, stop);
            printf("Suma kwadratow liczb całkwitych w przedziale od %ld do %ld wynosi %g\n", start, stop, wynik);
        }
        printf("Podaj granice przedzialu (podanie 0 dla obu oznacza koniec)\n");
        printf("Dolna granica: ");
        start = pobierz_long();
        printf("Górna granica: ");
        stop = pobierz_long();
    }
    printf("Koniec.\n");
    return 0;
}          

long pobierz_long(void)
{
    long we;
    char ch;

    while (scanf("%ld", &we) != 1)
    {
        while ((ch = getchar()) != '\n')
            putchar(ch);  //pomija błędne dane wejściowe
        printf(" nie jest liczbą całkowitą. \nProszę podać wartość całkowitą: ");
    }
    return we;
}

bool zle_granice (long poczatek, long koniec, long dolna, long gorna)
{
    bool zle = false;

    if (poczatek > koniec)
    {
        printf("%ld nie jest mniejsze od %ld.\n", poczatek, koniec);
        zle = true;
    }

    if (poczatek < dolna || koniec < dolna)
    {
        printf("Wartosci muszą mieć wartość co najmniej %ld\n", dolna);
        zle = true;
    }

      if (poczatek > gorna || koniec > gorna)
    {
        printf("Wartosci muszą mieć wartość co najwyzej %ld\n", koniec);
        zle = true;
    }

    return zle;
}

double suma_kwadr(long a, long b)
{
    double suma = 0;
    int i;

    for (i = a; i <= b; i++)
        suma +=i*i;

    return suma;
}