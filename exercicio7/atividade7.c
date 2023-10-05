#include <stdio.h>

int main() {
    char sexo, olhos, cabelos;
    int idade;
    float salario;
    int total_habitantes = 0;
    int total_feminino_castanhos_castanhos = 0;

    printf("Digite os dados dos habitantes ou -1 para encerrar:\n");

    while (1) {
        printf("Sexo (m/f): ");
        scanf(" %c", &sexo);

        if (sexo == 'm' || sexo == 'f') {
            printf("Cor dos olhos (a/v/c/p): ");
            scanf(" %c", &olhos);

            printf("Cor dos cabelos (l/c/p/r): ");
            scanf(" %c", &cabelos);

            printf("Idade (entre 10 e 100 anos): ");
            scanf("%d", &idade);

            printf("Salário (não negativo): ");
            scanf("%f", &salario);

            if (idade == -1) {
                break;
            }

            if (sexo == 'f' && idade >= 18 && idade <= 35 && olhos == 'c' && cabelos == 'c' && salario >= 0) {
                total_feminino_castanhos_castanhos++;
            }

            total_habitantes++;
        } else {
            printf("Dados inválidos. Tente novamente.\n");
        }
    }

    if (total_habitantes > 0) {
        float porcentagem = (float)total_feminino_castanhos_castanhos / total_habitantes * 100.0;
        printf("\nPorcentagem de mulheres entre 18 e 35 anos com olhos e cabelos castanhos: %.2f%%\n", porcentagem);
    } else {
        printf("\nNenhum dado válido foi inserido.\n");
    }

    return 0;
}
