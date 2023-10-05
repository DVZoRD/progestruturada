
#include <stdio.h>

int main() {
    int N;

    printf("Digite um numero inteiro: ");
    scanf("%d", &N);

    printf("Os %d primeiros numeros naturais impares são:\n", N);

    for (int i = 1, count = 0; count < N; i += 2, count++) {
        printf("%d ", i);
    }

    printf("\n");

    return 0;
}