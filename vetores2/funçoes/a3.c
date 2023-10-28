#include <stdio.h>

double fahrenheitParaCelsius(double temperaturaFahrenheit) {
    double temperaturaCelsius = (temperaturaFahrenheit - 32.0) * (5.0 / 9.0);
    return temperaturaCelsius;
}

int main() {
    double temperaturaF, temperaturaC;

    printf("Digite a temperatura em graus Fahrenheit: ");
    scanf("%lf", &temperaturaF);

    temperaturaC = fahrenheitParaCelsius(temperaturaF);

    printf("A temperatura %.2lf graus Fahrenheit é equivalente a %.2lf graus Celsius.\n", temperaturaF, temperaturaC);

    return 0;
}
