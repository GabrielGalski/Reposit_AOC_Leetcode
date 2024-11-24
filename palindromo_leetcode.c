#include <stdio.h>

int main() {
    int len, comp, x, y;
    int num = 1221; 
    int numOriginal[100], numContrario[100];

    
    len = 0;
    int temp = num;
    while (temp > 0) {
        numOriginal[len++] = temp % 10; 
        temp /= 10;                     
    }

    for (x = 0, y = len - 1; y >= 0; x++, y--) {
        numContrario[x] = numOriginal[y];
    }

    comp = 0;
    for (x = 0; x < len; x++) {
        if (numOriginal[x] != numContrario[x]) {
            comp = 1; 
            break;
        }
    }

    if (comp == 0) {
        printf("O numero %d eh um palindromo\n", num);
    } else {
        printf("O numero %d não eh um palindromo\n", num);
    }

    return 0;
}
