/*
um algoritmo que move os 0's para o fim mantendo a ordem restante

*/

#include <stdio.h>
void imprime(int nums[], int total);
void moveZeros(int nums[], int total);

int main()
{
    int nums[] = {0, 1, 0, 3, 12};
    int total = sizeof(nums) / sizeof(nums[0]);

    printf("sequencia original: ");
    imprime(nums, total);
    moveZeros(nums, total);

    printf("\nsequencia final: ");
    imprime(nums, total);
    return 0;
}

void moveZeros(int nums[], int total)
{
    int j = 0;
    for (int i = 0; i < total; i++)
    {
        if (nums[i] != 0)
        {
            nums[j++] = nums[i];
        }
    }

    while (j < total)
    {
        nums[j++] = 0;
    }
}
void imprime(int nums[], int total)
{
    for (int i = 0; i < total; i++)
    {
        printf("%d ", nums[i]);
    }
}
