#include <stdio.h>

int main() {
    // Defina um array para armazenar os nomes e os valores das frutas
    char frutas[3][20] = {"ABACAXI", "MAÇA", "PERA"};
    float valores[3] = {5.0, 1.0, 4.0};
    
    int opcao;
    float total = 0.0;
    
    printf("Bem-vindo à loja de frutas!\n");

    while (1) {
        printf("\nLista de frutas disponíveis:\n");
        printf("1 => ABACAXI - R$5.00 a unidade\n");
        printf("2 => MAÇA - R$1.00 a unidade\n");
        printf("3 => PERA - R$4.00 a unidade\n");
        printf("4 => Sair\n");
        
        printf("Escolha uma opção (1-4): ");
        scanf("%d", &opcao);

        if (opcao == 4) {
            break;
        }

        if (opcao < 1 || opcao > 3) {
            printf("Opção inválida. Escolha uma opção válida (1-3).\n");
            continue;
        }

        int quantidade;
        printf("Quantidade desejada: ");
        scanf("%d", &quantidade);

        if (quantidade <= 0) {
            printf("Quantidade inválida. Digite uma quantidade positiva.\n");
            continue;
        }

        float subtotal = valores[opcao - 1] * quantidade;
        total += subtotal;

        printf("%d %s(s) adicionado(s) ao carrinho. Subtotal: R$%.2f\n", quantidade, frutas[opcao - 1], subtotal);
    }

    printf("O valor total da compra é: R$%.2f\n", total);

    return 0;
}
