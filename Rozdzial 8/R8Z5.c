#include <stdio.h>
#define MINTOSEK 60.00 // minuta to 60 s
int main(void)
{
    const int DOLNA = 1;
    const int GORNA = 100;
    int proba = GORNA/2;
    int dolna, gorna;
    char odpowiedz;
    dolna = DOLNA;
    gorna = GORNA;

    printf("Wybierz liczbe od 1 do 100. Spróbuję ją odgadnać.\nWpisz t jeśli moja próba jest udana lub \nn jeśli nie trafiłem.\n");
    printf("Czy twoja liczba jest wieksza (<), mniejsza (>), czy równa (=) liczbie %d?", proba);

    while ((odpowiedz = getchar()) != '=')
    {
        if (odpowiedz == '>')
        {
            dolna = proba;
            gorna = gorna;
            proba = dolna + (gorna - dolna)/2 ;
            printf("Czy twoja liczba jest wieksza (<), mniejsza (>), czy równa (=) liczbie %d?", proba);
        }
        else  
        {
            dolna = dolna;
            gorna = proba;
            proba = dolna + (gorna - dolna)/2 ;
            printf("Czy twoja liczba jest wieksza (<), mniejsza (>), czy równa (=) liczbie %d?", proba);
        }

        while (getchar() != '\n')
            continue;   //pomija reszte wiersza
    }
    printf("Brawo! Twoja liczba to %d", proba);
    return 0;
}