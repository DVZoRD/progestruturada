#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    double delta, raiz1, raiz2;

    printf("Digite o coeficiente a (nao pode ser zero): ");
    scanf("%lf", &a);

    if (a == 0) {
        printf("Nao e equação de segundo grau.\n");
        return 1;
    }

    printf("Digite o coeficiente b: ");
    scanf("%lf", &b);

    printf("Digite o coeficiente c: ");
    scanf("%lf", &c);

    delta = (b * b) - (4 * a * c);

    if (delta < 0) {
        printf("Nao existe raiz.\n");
    } else if (delta == 0) {
        raiz1 = -b / (2 * a);
        printf("Raiz  unica: %lf\n", raiz1);
    } else {
        raiz1 = (-b + sqrt(delta)) / (2 * a);
        raiz2 = (-b - sqrt(delta)) / (2 * a);
        printf("Duas raizes reais: %lf e %lf\n", raiz1, raiz2);
    }

    return 0;
}
