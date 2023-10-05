#include<stdio.h>

main(){

    int num1 , num2 , soma ,  sub , mult  ;
    float div;

printf("Digite dois numeros inteiros: \n");
scanf("%d %d" , &num1 , &num2);

        sub= num1 - num2;
        mult = num1 * num2;
        div = (float) num1 / num2;
        soma = num1 + num2;

        printf("Resultado subtracao: %d \n" , sub);
        printf("Resultado multipicacao: %d\n" , mult);
        printf("Resultado divisao: %0.2f \n" , div);



}