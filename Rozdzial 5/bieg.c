//buty2.c -- oblicza dlugosc stopy dla kilku numerow buta
#include <stdio.h>

const int S_W_M = 60;   // liczba sekund w minucie
const int S_W_H = 3600; //liczba sekund w godzinie
int main(void)                     
{

       double dyst;
       double predkosc;
       int min, sek;
       int czas;
       double czas_km;
       int min_km, sek_km;

       printf("Ten program zmienia czas twojego biegu na dowolnym dystansie\n");
       printf("na czas przebiegniecia 1km oraz srednia predkosc w km/h\n");
       printf("Wpisz pokonany dystans w kilometrach\n");
       scanf("%lf", &dyst);
       printf("Wpisz czas w minutach i sekundach\n");
       printf("Najpierw podaj liczbe minut\n");
       scanf("%d", &min);
       printf("Teraz podaj liczbe sekund\n");
       scanf("%d", &sek);

       czas = S_W_M * min + sek; //konwertuje czas do sekund
       predkosc = dyst/czas * S_W_H; // oblicza średnią predkosc w km/h
       czas_km = (double) czas / dyst ; //czas na 1 km
       min_km = (int) czas_km / S_W_M; // oblicza liczbe pelnych minut
       sek_km = (int) czas_km % S_W_M; // oblicza liczbe pozosalych sekund

       printf("Przebiegles %1.2f km w czasie %d minut %d sekund. \n", dyst, min, sek);
       printf("Odpowiada to przebiegnieciu 1km w czasie %d minut %d sekund. \n", min_km, sek_km);
       printf("Twoja srednia predkosc to %1.1f km/h",predkosc);

       return 0;
}
