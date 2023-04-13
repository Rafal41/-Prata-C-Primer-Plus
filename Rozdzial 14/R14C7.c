#include <stdio.h>
#include "pozaziem.h"

void wyswietldane(const struct bem *dane)
{
    printf("%s %s jest %sem o %d konczynach\n",dane->tytul.imie,dane->tytul.naziwsko, dane->typ, dane->konczyny);
}