#include <stdio.h>

int main() {
    float a, b, c, peso;
    const float media = 7.0;

    // Read the scores from the user
    printf("Quanto vc tirou na primeira prova:");
    scanf("%f", &a);

    printf("Quanto vc tirou na segunda prova:");
    scanf("%f", &b);

    printf("Quanto vc tirou na terceiro prova:");
    scanf("%f", &c);


    peso = (a + b + (c * 2.0)) / 4.0;

    if (peso >= media) {
        printf("Media: %.2f\n", peso);
        printf("Resultado: passou\n");
    } else {
        printf("Media: %.2f\n", peso);
        printf("Resultado: reprovado\n");
    }

    return 0;
}