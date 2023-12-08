#include <stdio.h>
#include <time.h>

void calcular_idade(char data_nascimento[11]) {
    struct tm data_nasc = {0};
    struct tm hoje = {0};

    time_t t = time(NULL);
    hoje = *localtime(&t);

    sscanf(data_nascimento, "%d/%d/%d", &data_nasc.tm_mday, &data_nasc.tm_mon, &data_nasc.tm_year);

    data_nasc.tm_mon--; // Ajuste para o formato esperado pela struct tm (0 a 11 para os meses)
    data_nasc.tm_year -= 1900; // Ano começa em 1900 na struct tm

    time_t data_nasc_sec = mktime(&data_nasc);
    time_t hoje_sec = mktime(&hoje);

    double diferenca = difftime(hoje_sec, data_nasc_sec);

    int dias = diferenca / (60 * 60 * 24); // Quantidade de dias
    int anos = dias / 365; // Quantidade de anos
    int meses = ((dias % 365) / 30); // Quantidade de meses (aproximadamente)

    printf("Idade: %d anos, %d meses, %d dias\n", anos, meses, dias % 30);
}

int main() {
    char data[11];
    printf("Digite a data de nascimento (DD/MM/AAAA): ");
    scanf("%s", data);

    calcular_idade(data);

    return 0;
}
