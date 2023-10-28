#include <stdio.h>

int main() {
    int vetor[50];

    // Preenche o vetor com os valores calculados
    for (int i = 0; i < 50; i++) {
        vetor[i] = (14 + 5 * i) * (1 + 1);
    }

    // Imprime o vetor na tela
    printf("Vetor preenchido com os valores calculados:\n");
    for (int i = 0; i < 50; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
