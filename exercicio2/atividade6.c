#include<stdio.h>
main(){

float num1 , num2 , num3 , num4 , soma , sub , lucro;

printf("Digite o custa da mercadoria: ");
        scanf("%f" , &num1 );

printf("Digite o custo do frete:");
scanf("%f" , &num2);
printf("Digite o custo de despesas eventuais caso haja:");
scanf("%f" , &num3);

printf("Digite o valor de venda:");
scanf("%f" , &num4);

soma = num1 + num2 +num3;
sub = num4 - soma;
lucro = sub * 100 / soma;
printf("O valor de lucro foi: R$%0.2f" , sub );
printf(" Ou %0.f%%", lucro);




}