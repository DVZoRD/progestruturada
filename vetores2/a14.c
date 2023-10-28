#include <stdio.h>

int main() {
    int vetor[10];
    int i, j;

    // Lê os valores para o vetor
    printf("Digite 10 valores inteiros:\n");
    for (i = 0; i < 10; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    // Verifica se existem valores iguais
    int encontrouIgual = 0;
    for (i = 0; i < 10; i++) {
        for (j = i + 1; j < 10; j++) {
            if (vetor[i] == vetor[j]) {
                printf("Valores iguais encontrados: %d\n", vetor[i]);
                encontrouIgual = 1;
            }
        }
    }

    if (!encontrouIgual) {
        printf("Não foram encontrados valores iguais no vetor.\n");
    }

    return 0;
}
