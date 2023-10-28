#include <stdio.h>

void imprimirMesEQuantidadeDias(int numero) {
    if (numero >= 1 && numero <= 12) {
        char *mes;
        int dias;

        switch (numero) {
            case 1:
                mes = "janeiro";
                dias = 31;
                break;
            case 2:
                mes = "fevereiro";
                dias = 28; // Considerando um ano comum
                break;
            case 3:
                mes = "março";
                dias = 31;
                break;
            case 4:
                mes = "abril";
                dias = 30;
                break;
            case 5:
                mes = "maio";
                dias = 31;
                break;
            case 6:
                mes = "junho";
                dias = 30;
                break;
            case 7:
                mes = "julho";
                dias = 31;
                break;
            case 8:
                mes = "agosto";
                dias = 31;
                break;
            case 9:
                mes = "setembro";
                dias = 30;
                break;
            case 10:
                mes = "outubro";
                dias = 31;
                break;
            case 11:
                mes = "novembro";
                dias = 30;
                break;
            case 12:
                mes = "dezembro";
                dias = 31;
                break;
            default:
                mes = "mês inválido";
                dias = 0;
                break;
        }

        printf("Mês: %s\n", mes);
        printf("Quantidade de dias: %d\n", dias);
    } else {
        printf("Número de mês fora do intervalo válido (1 a 12).\n");
    }
}

int main() {
    int numeroMes;

    printf("Digite um número de mês (1 a 12): ");
    scanf("%d", &numeroMes);

    imprimirMesEQuantidadeDias(numeroMes);

    return 0;
}
