#include<stdio.h>
main(){

int ano , mes , dia , diano , diames , total , subano , submes , subdia , diahj , meshj , anohj;

printf ("Digite o dia que vc nasceu com dia , mes e ano: ");
        scanf("%d %d %d" , &dia , &mes , &ano); 
printf ("Digite o dia de hoje com dia , mes e ano: ");
scanf("%d %d %d" , &diahj , &meshj , &anohj); 


subano = anohj - ano;
submes = meshj - mes;
subdia = diahj - dia;

diano = subano * 365;
diames = submes * 30;
total = subdia + diano + diames;

printf("sua idade em dias e: %d dias" , total);


}