#include <stdio.h>

int maiorEntreDois(int num1, int num2) {
    if (num1 > num2) {
        return num1;
    } else {
        return num2;
    }
}

int main() {
    int a, b;

    printf("Digite dois números inteiros: ");
    scanf("%d %d", &a, &b);

    int maior = maiorEntreDois(a, b);

    printf("O maior número entre %d e %d é: %d\n", a, b, maior);

    return 0;
}
