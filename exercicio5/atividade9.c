#include <stdio.h>
#include <math.h>

int main() {

int salario , anos , reajuste , bonus , final;




  printf("Qual o seu salario atual:");
  scanf("%d" , &salario);

   printf("Quantos anos vc trabalha na empresa:");
  scanf("%d" , &anos);


  if(salario <= 500){

  reajuste = 0.25 * salario + salario;

  };

   if(salario <= 1000){

  reajuste = 0.20 * salario + salario;

  };
   if(salario <= 1500){

  reajuste = 0.15 * salario + salario;

  };
   if(salario <= 2000){

  reajuste = 0.10 * salario + salario;

  };

   if(salario > 2000){

  reajuste = salario;

  };

if(anos < 1){

bonus = 0;

}

if( anos >= 1 || anos <= 3 ){

bonus = 100;

}

if(anos >= 4 || anos <= 6){

bonus = 200;

}

if(anos >= 7 || anos <= 10){

bonus = 300;

}

if(anos > 10){

bonus = 500;

}

final = bonus + reajuste;




printf ("Seu salario novo e: R$%d,00 " , final);


     return 0;
}