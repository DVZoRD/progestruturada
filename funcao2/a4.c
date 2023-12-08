#include <stdio.h>

#define LINHAS 61
#define COLUNAS 10

void somar_colunas(int matriz[LINHAS][COLUNAS]) {
    for (int j = 0; j < COLUNAS; j++) {
        int soma = 0;
        for (int i = 0; i < LINHAS - 1; i++) {
            soma += matriz[i][j];
        }
        matriz[LINHAS - 1][j] = soma;
    }
}

void mostrar_matriz(int matriz[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

void preencher_matriz(int matriz[LINHAS][COLUNAS]) {
    srand(time(NULL)); // Inicializa a semente para números aleatórios

    for (int i = 0; i < LINHAS - 1; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            matriz[i][j] = rand() % 10 + 1; // Gera números aleatórios entre 1 e 10
        }
    }
}
int main() {
    int matriz[LINHAS][COLUNAS];

     preencher_matriz(matriz);

    printf("Matriz original:\n");
    mostrar_matriz(matriz);

    somar_colunas(matriz);

    printf("\nMatriz apos a soma das colunas:\n");
    mostrar_matriz(matriz);

    return 0;
}
