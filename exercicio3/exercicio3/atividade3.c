#include<stdio.h>
#include<math.h>

main(){

float x , y = 1.80;

printf("Qual e a sua altura?");
scanf("%f" , &x);

if(x > y){

    printf("Vc tem mais que 1.80m");}
else{
    printf("Vc tem menos de 1.80m");
}
}
