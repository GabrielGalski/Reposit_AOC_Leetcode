#include <stdio.h>

int searchInsert(int *nums, int numsSize, int target)
{

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == target)
        {
            return i;
        }
    }

    // procura onde o target deve ser inserido
    for (int j = 0; j < numsSize; j++)
    {
        if (nums[j] > target)
        {
            return j;
        }
    }

    // se o target é maior que todos os elementos = retorna o tamanho final
    return numsSize;
}

int main()
{
    int nums[] = {1, 3, 5, 6};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target;

    // pede ao usuário para inserir um número
    printf("digite um numero para procurar ou inserir: ");
    scanf("%d", &target);

    // chama a função e exibe o resultado
    int resultado = searchInsert(nums, numsSize, target);
    printf("o indice onde %d deve ser inserido ou encontrado e: %d\n", target, resultado);
    return 0;
}
