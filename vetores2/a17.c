#include <stdio.h>

int main() {
    int vetor[10];

    // Lê os valores para o vetor
    printf("Digite 10 valores inteiros:\n");
    for (int i = 0; i < 10; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    // Atribui valor 0 a elementos negativos
    for (int i = 0; i < 10; i++) {
        if (vetor[i] < 0) {
            vetor[i] = 0;
        }
    }

    // Exibe o vetor modificado
    printf("Vetor com valores negativos substituídos por 0:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
