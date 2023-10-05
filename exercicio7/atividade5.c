#include <stdio.h>

int main() {
    int soma = 0;
    int contador = 0;
    int numero = 2; // Começamos com o primeiro número par, que é 2.

    while (contador < 50) {
        soma += numero;
        numero += 2; // Avançamos para o próximo número par.
        contador++;
    }

    printf("A soma dos 50 primeiros números pares é: %d\n", soma);

    return 0;
}
