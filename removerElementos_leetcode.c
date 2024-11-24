#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int nums[] = {3, 2, 2, 3};
    int vet = 3;
    int i, j = 0; 
    
    for (i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
        if (nums[i] != vet) { 
            nums[j] = nums[i]; 
            j++;               
        }
    }

    printf("Valores atualizados:\n");
    for (i = 0; i < j; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
