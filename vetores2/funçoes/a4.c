#include <stdio.h>
#include <math.h>

double calcularVolumeCilindro(double raio, double altura) {
    const double pi = 3.141592;
    double volume = pi * pow(raio, 2) * altura;
    return volume;
}

int main() {
    double raio, altura, volume;

    printf("Digite o raio do cilindro: ");
    scanf("%lf", &raio);

    printf("Digite a altura do cilindro: ");
    scanf("%lf", &altura);

    volume = calcularVolumeCilindro(raio, altura);

    printf("O volume do cilindro é: %.2lf\n", volume);

    return 0;
}
