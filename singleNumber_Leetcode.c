#include <stdio.h>

int main(){

int nums[] = {1,2,2,4,5,4,5};
int num = 0;
int size = sizeof(nums) / sizeof(nums[0]);
    
    for (int i = 0; i < size; i++) {
        num ^= nums[i];
        }
    printf("%d é o single number", num);
    return 0;
    }



