#include<stdio.h>
#include<math.h>

main(){

 int num , raiz , potencia;

   printf(" Digite um numero: ");
    scanf("%d" , &num );

 if (num >= 0)
 {
    raiz = sqrt(num);
    printf ("A raiz do seu numero e: %d" , raiz);

 };
 if (num < 0)
 {
    potencia = pow(num , 2);
    printf ("O quadrado do seu numero e: %d" , potencia);
 }
 
 




}