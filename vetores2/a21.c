#include <stdio.h>

int main() {
    int A[10];
    int B[10];
    int C[10];

    // Lê os valores para o vetor A
    printf("Digite 10 números inteiros para o vetor A:\n");
    for (int i = 0; i < 10; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &A[i]);
    }

    // Lê os valores para o vetor B
    printf("Digite 10 números inteiros para o vetor B:\n");
    for (int i = 0; i < 10; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &B[i]);
    }

    // Calcula o vetor C como a diferença entre A e B
    for (int i = 0; i < 10; i++) {
        C[i] = A[i] - B[i];
    }

    // Mostra os dados do vetor C
    printf("Vetor C (A - B):\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", C[i]);
    }
    printf("\n");

    return 0;
}
