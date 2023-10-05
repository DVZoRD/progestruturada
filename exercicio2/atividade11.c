#include<stdio.h>
main(){
    float salario , comissao , totalcomissao , valordoscarros , total , porcentagem , carros;

printf("Digite o valor do seu salario:");
scanf("%f" , &salario);

printf("Quantos carros voce vendeu?");
scanf("%f" , &carros);

printf("Digite o valor da sua comissao por cada carro:");
scanf("%f" , &comissao);

printf("Digite o valor total dos carros que vc vendeu:");
scanf("%f" , &valordoscarros);

porcentagem = valordoscarros * 0.05;
totalcomissao = carros * comissao;
total = salario + totalcomissao + porcentagem;

printf("O seu salario final e:R$%0.2f" , total);



}