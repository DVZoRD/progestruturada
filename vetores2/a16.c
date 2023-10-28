#include <stdio.h>

int main() {
    float vetor[5];
    int codigo;

    // Lê os valores para o vetor
    printf("Digite 5 valores reais:\n");
    for (int i = 0; i < 5; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%f", &vetor[i]);
    }

    printf("Digite o código (0 para sair, 1 para mostrar na ordem direta, 2 para mostrar na ordem inversa): ");
    scanf("%d", &codigo);

    if (codigo == 0) {
        printf("Programa finalizado.\n");
    } else if (codigo == 1) {
        printf("Vetor na ordem direta:\n");
        for (int i = 0; i < 5; i++) {
            printf("%.2f ", vetor[i]);
        }
        printf("\n");
    } else if (codigo == 2) {
        printf("Vetor na ordem inversa:\n");
        for (int i = 4; i >= 0; i--) {
            printf("%.2f ", vetor[i]);
        }
        printf("\n");
    } else {
        printf("Código inválido. Por favor, insira 0, 1 ou 2.\n");
    }

    return 0;
}
