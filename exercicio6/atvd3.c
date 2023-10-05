#include <stdio.h>
#include <conio.h>
int main (void)
{
  int prato , sobremesa , bebida , quant , final , cal1 , cal2 , cal3;
  
  printf ("Digite um prato \n 1 - Vegetariano | 180 cal\n 2 - Peixe | 180 cal\n 3 - Frango | 180 cal \n 4 - Carne | 180 cal \n");
  scanf("%d", &prato);
  
  switch (prato)
  {
    case 1 :
    printf ("Vegetariano\n");
    cal1 = 180;
    break;
    
    case 2 :
    printf (" Peixe\n");
    cal1 = 230;
    break;
    
    case 3 :
    printf ("Frango \n");
     cal1= 250;
    break;
    
    case 4 :
    printf ("Carne\n");
     cal1 = 350;
    break;
    
    default :
    printf ("Sem identificação!\n");
  }

    printf ("Digite uma sobremesa \n 1 - Abacaxi | 75 cal\n 2 - Sorvete Diet | 110 cal\n 3 - Mouse Diet | 170 cal \n 4 - Mouse Chocolate | 200 cal \n");
  scanf("%d", &sobremesa);
  
  switch (sobremesa)
  {
    case 1 :
    printf ("Abacaxi\n");
    cal2 = 75;
    break;
    
    case 2 :
    printf (" Sorvete Diet\n");
    cal2 = 110;
    break;
    
    case 3 :
    printf ("Mouse Diet \n");
     cal2= 170;
    break;
    
    case 4 :
    printf ("Mouse Chocolate\n");
     cal2 = 200;
    break;
    
    default :
    printf ("Sem identificação!\n");
  }

   printf ("Digite uma bebida \n 1 - Cha | 20 cal\n 2 - Suco Laranja | 70 cal\n 3 - Suco Melao | 100 cal \n 4 - Refrigerante Diet | 65 cal \n");
  scanf("%d", &bebida);
  
  switch (bebida)
  {
    case 1 :
    printf ("Cha\n");
    cal3 = 20 ;
    break;
    
    case 2 :
    printf (" Suco Laranja\n");
    cal3 = 70;
    break;
    
    case 3 :
    printf ("Suco Melao\n");
     cal3= 100;
    break;
    
    case 4 :
    printf ("Refrigerante Diet\n");
     cal3 = 65;
    break;
    
    default :
    printf ("Sem identificação!\n");
  }


  final = cal1 + cal2 + cal3;
  

   printf("O valor calorico de pedir %d , %d e %d sera: %d cal" , prato , sobremesa , bebida , final);
  
  return 0;
}