#include<stdio.h>
main(){

float salario , aumento , porcentagem , total , mult; 


printf("Digite seu salario: ");
scanf("%f" , &salario);
printf("Quanto porcento seu salario vai aumentar? ");
scanf("%f" , &aumento);

porcentagem = aumento / 100;
mult = salario * porcentagem;
total = salario + mult;

printf("Seu salario apos o aumento sera de: R$%0.2f" , total );



}