#include <stdio.h>
int main(void)
{
    char ch;

    scanf("%c", &ch);
    while ( ch != 'k')
    {
        printf("%c", ch);
        scanf("%c",&ch);
    }
    return 0;
}