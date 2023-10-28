#include <stdio.h>

int main() {
    int vetor[20];
    int novoVetor[20];
    int i, j, tamanhoNovoVetor = 0;

    // Lê os valores para o vetor
    printf("Digite 20 valores inteiros:\n");
    for (i = 0; i < 20; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    // Elimina elementos repetidos
    for (i = 0; i < 20; i++) {
        int repetido = 0;
        for (j = 0; j < tamanhoNovoVetor; j++) {
            if (vetor[i] == novoVetor[j]) {
                repetido = 1;
                break;
            }
        }
        if (!repetido) {
            novoVetor[tamanhoNovoVetor] = vetor[i];
            tamanhoNovoVetor++;
        }
    }

    // Exibe o novo vetor sem elementos repetidos
    printf("Novo vetor sem elementos repetidos:\n");
    for (i = 0; i < tamanhoNovoVetor; i++) {
        printf("%d ", novoVetor[i]);
    }
    printf("\n");

    return 0;
}
