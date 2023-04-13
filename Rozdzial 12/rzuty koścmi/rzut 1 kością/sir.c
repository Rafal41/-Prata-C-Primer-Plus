// kompilowac z plikiem rantest.c
#include <stdio.h>
static unsigned long int nast = 1;

int random(void)
{
    nast = nast * 330133043 + 33164;
    return (unsigned long) (nast/65536) % 32768;
}

void srandom(unsigned int ziarno)
{
    nast = ziarno;
}
