#include <stdio.h>

#define SIZE 10

void trocar_linhas(int matriz[SIZE][SIZE], int linha1, int linha2) {
    for (int i = 0; i < SIZE; i++) {
        int temp = matriz[linha1][i];
        matriz[linha1][i] = matriz[linha2][i];
        matriz[linha2][i] = temp;
    }
}

void trocar_colunas(int matriz[SIZE][SIZE], int coluna1, int coluna2) {
    for (int i = 0; i < SIZE; i++) {
        int temp = matriz[i][coluna1];
        matriz[i][coluna1] = matriz[i][coluna2];
        matriz[i][coluna2] = temp;
    }
}

void trocar_diagonais(int matriz[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        int temp = matriz[i][i];
        matriz[i][i] = matriz[i][SIZE - 1 - i];
        matriz[i][SIZE - 1 - i] = temp;
    }
}

void trocar_linha_coluna(int matriz[SIZE][SIZE], int linha, int coluna) {
    for (int i = 0; i < SIZE; i++) {
        int temp = matriz[linha][i];
        matriz[linha][i] = matriz[i][coluna];
        matriz[i][coluna] = temp;
    }
}

void mostrar_matriz(int matriz[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matriz[SIZE][SIZE];

for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
        matriz[i][j] = (i * SIZE) + j + 1;
    }
}

    printf("Matriz original:\n");
    mostrar_matriz(matriz);

    trocar_linhas(matriz, 1, 7);
    trocar_colunas(matriz, 3, 9);
    trocar_diagonais(matriz);
    trocar_linha_coluna(matriz, 4, 9);

    printf("\nMatriz apos as trocas:\n");
    mostrar_matriz(matriz);

    return 0;
}
