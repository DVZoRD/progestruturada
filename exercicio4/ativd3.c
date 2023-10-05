#include<stdio.h>
#include<math.h>

main(){

int A , B  , C ;

printf("Digite 3 numeros:");
scanf("%d %d %d" , &A ,&B ,&C);

if(A < B && A < C){

printf("%d ", A);
if(B<C){
    printf("%d %d" , B , C);
}else{
    printf("%d %d" , C , B);
}

}

if(B < A && B < C){

printf("%d ", B);
if(A<C){
    printf("%d %d" , A , C);
}else{
    printf("%d %d" , C , A);
}

}

if(C < A && C < B){

printf("%d ", C);
if(B<A){
    printf("%d %d" , B , A);
}else{
    printf("%d %d" , A , B);
}

}







}