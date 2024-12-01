/*
algoritimo para reverter um int

Gabriel galski Machado, 28 Nov, 2024
*/

#include <stdio.h>

int main()
{
    int num = 12132;
    int rev = 0;

    while (num != 0)
    {
        rev = rev * 10 + num % 10;
        num /= 10;
    }

    printf("número invertido: %d", rev);
    return 0;
}
