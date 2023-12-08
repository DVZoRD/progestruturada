#include <stdio.h>

void calcular_locacoes_gratuitas(int filmes_retirados[], int locacoes_gratuitas[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        locacoes_gratuitas[i] = filmes_retirados[i] / 15;
    }
}

int main() {
    int filmes_retirados[5];
    int locacoes_gratuitas[5];


  filmes_retirados[0] = 30; 
  filmes_retirados[1] = 45; 
    filmes_retirados[2] = 20; 
  filmes_retirados[3] = 5; 
    filmes_retirados[4] = 10; 



    int tamanho = 5;


    calcular_locacoes_gratuitas(filmes_retirados, locacoes_gratuitas, tamanho);

    printf("Quantidade de locações gratuitas por cliente:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Cliente %d: %d locacoes gratuitas\n", i, locacoes_gratuitas[i]);
    }

    return 0;
}
