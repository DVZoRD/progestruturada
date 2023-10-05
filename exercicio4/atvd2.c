#include<stdio.h>
#include<math.h>

int main(void){

 int num , maior=0 , menor=0;

 for (int i=1; i <=4; i++){

printf("\nDigite o %d numero:" , i);
scanf("%i" , &num);

if(1 == i) {
maior = num;
menor = num;
}
else if (num > maior){
  maior=num;
}
else if(num < menor){
  menor = num;
}
 }

 printf("\nO maior numero e: %i" , maior);
 printf("\nO menor numero e: %i" , menor);
return 0;
}
