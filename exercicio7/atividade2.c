#include <stdio.h>

int main() {
    int N;
    
    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &N);
    
    if (N < 0) {
        printf("Por favor, digite um numero inteiro positivo.\n");
    } else {
        printf("Numeros naturais de 0 ate %d em ordem decrescente:\n", N);
        
        for (int i = N; i >= 0; i--) {
            printf("%d ", i);
        }
        
        printf("\n");
    }
    
    return 0;
}
