#include <stdio.h>

int main() {
    int numeroAluno, numeroAlunoMaisBaixo, numeroAlunoMaisAlto;
    float altura, alturaMaisBaixa, alturaMaisAlta;

    // Inicialize as alturas máximas e mínimas com valores iniciais
    alturaMaisBaixa = 1000.0; // Altura máxima inicialmente muito alta
    alturaMaisAlta = 0.0;     // Altura mínima inicialmente muito baixa

    // Loop para ler os dados dos alunos
    for (int i = 1; i <= 10; i++) {
        printf("Digite o número do aluno %d: ", i);
        scanf("%d", &numeroAluno);
        printf("Digite a altura do aluno %d (em metros): ", i);
        scanf("%f", &altura);

        // Verifique se esta altura é a mais baixa até agora
        if (altura < alturaMaisBaixa) {
            alturaMaisBaixa = altura;
            numeroAlunoMaisBaixo = numeroAluno;
        }

        // Verifique se esta altura é a mais alta até agora
        if (altura > alturaMaisAlta) {
            alturaMaisAlta = altura;
            numeroAlunoMaisAlto = numeroAluno;
        }
    }

    // Mostre o aluno mais baixo
    printf("Aluno mais baixo:\n");
    printf("Número do aluno: %d\n", numeroAlunoMaisBaixo);
    printf("Altura: %.2f metros\n", alturaMaisBaixa);

    // Mostre o aluno mais alto
    printf("Aluno mais alto:\n");
    printf("Número do aluno: %d\n", numeroAlunoMaisAlto);
    printf("Altura: %.2f metros\n", alturaMaisAlta);

    return 0;
}
