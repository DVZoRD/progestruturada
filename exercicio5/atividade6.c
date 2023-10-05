#include <stdio.h>

int main() {
    int num;

    printf("Digite um numero: ");
    if (scanf("%d", &num) != 1) {
        return 1;
    }

    if (num % 2 == 0) {
        printf("O numero e par.\n");
    }

    return 0;
}
