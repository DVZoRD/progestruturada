#include <stdio.h>

int main() {
    int vetor1[10];
    int vetor2[10];
    int count = 0;

    // Lê os números inteiros no intervalo [0, 50] e os armazena no vetor1
    printf("Digite 10 números inteiros no intervalo [0, 50]:\n");
    for (int i = 0; i < 10; i++) {
        int num;
        do {
            printf("Digite o valor %d: ", i + 1);
            scanf("%d", &num);
        } while (num < 0 || num > 50);
        vetor1[i] = num;
    }

    // Preenche o vetor2 com os números ímpares do vetor1
    for (int i = 0; i < 10; i++) {
        if (vetor1[i] % 2 != 0) {
            vetor2[count] = vetor1[i];
            count++;
        }
    }

    // Imprime os dois vetores, 2 elementos por linha
    printf("Vetor1:\tVetor2:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\t\t", vetor1[i]);
        if (i < count) {
            printf("%d", vetor2[i]);
        }
        printf("\n");
    }

    return 0;
}
