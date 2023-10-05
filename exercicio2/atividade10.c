#include<stdio.h>
main(){

float custof , mult1 , mult2 , total;

printf ("Digite o custo de fabrica do carro: ");
        scanf("%f" , &custof);

mult1 = custof * 0.24;
mult2 = custof * 0.45;
total = mult1 + mult2 + custof;

printf ("O preco final desse carro e: R$%0.2f" , total);



}