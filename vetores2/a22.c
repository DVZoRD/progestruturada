#include <stdio.h>

int main() {
    int vetor1[10];
    int vetor2[10];
    int vetor3[20];  // Vetor resultante terá 20 posições

    // Lê os valores para o primeiro vetor
    printf("Digite 10 valores inteiros para o primeiro vetor:\n");
    for (int i = 0; i < 10; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &vetor1[i]);
    }

    // Lê os valores para o segundo vetor
    printf("Digite 10 valores inteiros para o segundo vetor:\n");
    for (int i = 0; i < 10; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &vetor2[i]);
    }

    // Preenche o terceiro vetor intercalando os valores dos dois vetores
    for (int i = 0; i < 10; i++) {
        vetor3[2 * i] = vetor1[i];     // Posições pares
        vetor3[2 * i + 1] = vetor2[i]; // Posições ímpares
    }

    // Mostra os dados do terceiro vetor
    printf("Terceiro vetor com posições pares e ímpares:\n");
    for (int i = 0; i < 20; i++) {
        printf("%d ", vetor3[i]);
    }
    printf("\n");

    return 0;
}
