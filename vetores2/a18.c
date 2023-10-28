#include <stdio.h>

int main() {
    int vetor[10];
    int r;

    // Lê os valores para o vetor
    printf("Digite 10 valores inteiros:\n");
    for (int i = 0; i < 10; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    // Lê o número r
    printf("Digite um número inteiro r: ");
    scanf("%d", &r);

    // Conta os múltiplos de r no vetor e os mostra na tela
    printf("Múltiplos de %d no vetor:\n", r);
    for (int i = 0; i < 10; i++) {
        if (vetor[i] % r == 0) {
            printf("%d ", vetor[i]);
        }
    }
    printf("\n");

    return 0;
}
