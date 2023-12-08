#include <stdio.h>

void imprimir_opcoes_pagamento() {
    printf("Opções de pagamento:\n");
    printf("a) À vista com 10%% de desconto\n");
    printf("b) Em duas vezes (preço da etiqueta)\n");
    printf("c) De 3 até 10 vezes com 3%% de juros ao mês (somente para compras acima de R$ 100,00)\n");
}

char solicitar_opcao() {
    char opcao;
    printf("Escolha uma opção de pagamento (a, b ou c): ");
    scanf(" %c", &opcao);
    return opcao;
}

void opcao_a_vista(float total_gasto) {
    float valor_desconto = total_gasto * 0.1;
    float valor_final = total_gasto - valor_desconto;
    printf("Valor total a vista com desconto: R$ %.2f\n", valor_final);
}

void opcao_duas_vezes(float total_gasto) {
    printf("Valor total em duas vezes: R$ %.2f\n", total_gasto);
}

void opcao_tres_a_dez_vezes(float total_gasto) {
    if (total_gasto > 100.00) {
        int parcelas;
        printf("Escolha a quantidade de parcelas (de 3 a 10): ");
        scanf("%d", &parcelas);

        if (parcelas >= 3 && parcelas <= 10) {
            float valor_juros = total_gasto * 0.03 * parcelas;
            float valor_final = total_gasto + valor_juros;
            printf("Valor total em %d vezes: R$ %.2f por parcela\n", parcelas, valor_final / parcelas);
        } else {
            printf("Opção inválida de parcelas.\n");
        }
    } else {
        printf("Esta opção é válida somente para compras acima de R$ 100,00.\n");
    }
}

int main() {
    float total_gasto;
    char opcao;

    printf("Digite o total gasto pelo cliente: R$ ");
    scanf("%f", &total_gasto);

    imprimir_opcoes_pagamento();
    opcao = solicitar_opcao();

    switch (opcao) {
        case 'a':
            opcao_a_vista(total_gasto);
            break;
        case 'b':
            opcao_duas_vezes(total_gasto);
            break;
        case 'c':
            opcao_tres_a_dez_vezes(total_gasto);
            break;
        default:
            printf("Opção inválida.\n");
            break;
    }

    return 0;
}
