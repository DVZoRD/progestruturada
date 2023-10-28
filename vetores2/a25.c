#include <stdio.h>

int main() {
    int vetor[100];
    int numero = 1; // Inicia com o primeiro número natural

    int i = 0;
    while (i < 100) {
        if (numero % 7 != 0 && numero % 10 != 7) {
            vetor[i] = numero;
            i++;
        }
        numero++;
    }

    // Exibe o vetor preenchido
    printf("Vetor com os 100 primeiros naturais que não são múltiplos de 7 ou que não terminam com 7:\n");
    for (i = 0; i < 100; i++) {
        printf("%d ", vetor[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n"); // Quebra a linha a cada 10 elementos
        }
    }

    return 0;
}
