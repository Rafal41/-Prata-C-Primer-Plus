#include <stdio.h>
void menu(void);
int pobierz_wybor(int dolna, int gorna);
int main(void)
{
    int odp;
    menu();
    while ((odp = pobierz_wybor(1,4)) != 4)
    {
        printf("Dobry wybor\n");
        menu();
    }

    return 0;
}
void menu(void)
{
    printf("Wybierz jedna z ponizszych mozliwosci:\n");
    printf("1. kopiowanie plikow            2. przenoszenie plikow\n");
    printf("3. usuwanie plikow              4. koniec\n");
    printf("Podaj numer wybranej opcji:\n");
}

int pobierz_wybor(int dolna, int gorna)
{
    int odp;
    int ok;

    ok = scanf("%d", &odp);
    while (ok == 1 && (odp < dolna || odp > gorna))
    {
        printf("%d nie jest poprawnym wyborem; sproboj jeszcze raz\n", odp);
        menu();
        ok = scanf("%d", &odp);
    }
    if (ok != 1)
    {
        printf("niepoprawna odpowiedz");
        odp = 4;
    }
    return odp;
}