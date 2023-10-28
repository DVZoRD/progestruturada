#include <stdio.h>

int main() {
    int v[10];
    int v1[10]; // Vetor para armazenar ímpares
    int v2[10]; // Vetor para armazenar pares
    int cont_v1 = 0; // Contador de elementos em v1
    int cont_v2 = 0; // Contador de elementos em v2

    // Lê os valores para o vetor v
    printf("Digite 10 números inteiros:\n");
    for (int i = 0; i < 10; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &v[i]);

        if (v[i] % 2 == 0) {
            // É par, copie para v2
            v2[cont_v2] = v[i];
            cont_v2++;
        } else {
            // É ímpar, copie para v1
            v1[cont_v1] = v[i];
            cont_v1++;
        }
    }

    // Exibe os elementos UTILIZADOS de v1
    printf("Elementos ímpares em v1:\n");
    for (int i = 0; i < cont_v1; i++) {
        printf("%d ", v1[i]);
    }
    printf("\n");

    // Exibe os elementos UTILIZADOS de v2
    printf("Elementos pares em v2:\n");
    for (int i = 0; i < cont_v2; i++) {
        printf("%d ", v2[i]);
    }
    printf("\n");

    return 0;
}
