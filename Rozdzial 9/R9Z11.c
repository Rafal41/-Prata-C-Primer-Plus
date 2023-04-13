#include <stdio.h>
// funkcja wyswietlajaca wartosci wyrazow ciagu Fibonacciego
void Fibonacci(int liczba); 
// funkcja pobierająca liczby całkowite
int pobierz_int(void);

int main(void)
{
    int num;
    
    printf("Podaj wyraz ciągu Fibonacciego którego wartosc chcesz sprawdzic\n");
    num = pobierz_int();
    while (num <= 0)
    {
        printf("Podaj poprawny wyraz ciągu Fibonacciego którego wartosc chcesz sprawdzic\n");
        num = pobierz_int(); 
    }
    Fibonacci(num);

    return 0;
}

void Fibonacci(int liczba)
{
    int temp;
    int n = 1, m = 1; // pierwsze dwa wyrazy ciagu
    int licznik = 3;

    if (liczba == 1 || liczba == 2)
        m = 1;
    else
        while (licznik <= liczba)
        {
            temp = m;
            m = m + n;
            n = temp;
            licznik++;
        }

    printf("Wartosc ciagu Fibonacciego dla wybranego przez Ciebie wyrazu to %d\n", m);

}

int pobierz_int(void)
{
    int we;
    char ch;

    while (scanf("%d", &we) != 1)
    {
        while ((ch = getchar()) != '\n')
            putchar(ch);  //pomija błędne dane wejściowe
        printf(" nie jest liczbą całkowitą. \nProszę podać wartość całkowitą: ");
    }
    return we;
}