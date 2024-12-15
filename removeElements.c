#include <stdio.h>
int removeElement(int *nums, int numsSize, int val)
{
    int count = 0;

    // percorre o array
    for (int i = 0; i < numsSize; i++)
    {
        // verifica o elemento atual
        if (nums[i] != val)
        {
            // se for diferente = count++
            nums[count] = nums[i];
            count++;
        }
    }

    return count;
}

int main()
{
    int nums[] = {3, 2, 2, 3, 4, 2, 5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int val = 2;

    // Chama a função para remover o valor "val"
    int newSize = removeElement(nums, numsSize, val);

    // Imprime o novo tamanho do array e seus elementos
    printf("Novo tamanho: %d\n", newSize);
    printf("Array modificado: ");
    for (int i = 0; i < newSize; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
