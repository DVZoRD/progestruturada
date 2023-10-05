#include<stdio.h>
main(){

float num1 , num2 = 4.97  , mult  ;
 printf("Digite qual valor voce quer converter: ");
        scanf("%f" , &num1 );


mult = (float) num1 * num2;

 printf("Essa quantia em dolares e: %0.2f$" , mult);

}