#include <stdio.h>
#include <conio.h>
int main (void)
{
  int pedido , quant , final , preco;
  
  printf ("Digite um um pedido \n 100 - Cachorro quente | R$ 10,10 \n 101 - Bauru simples | R$ 8,30\n 102 - Bauru c/ovo | R$ 8,50 \n 103 - Hamburger | R$ 12,50 \n 104 - Cheeseburger | R$ 13,25 \n");
  scanf("%d", &pedido);
  
  switch (pedido)
  {
    case 100 :
    printf ("Cachorro quente\n");
    preco = 10.10;
    break;
    
    case 101 :
    printf ("Bauru simples\n");
     preco = 8.30;
    break;
    
    case 102 :
    printf ("Bauru c/ovo\n");
     preco = 8.50;
    break;
    
    case 103 :
    printf ("Hamburger\n");
     preco = 12.50;
    break;
    
     case 104 :
    printf ("Cheeseburger \n");
     preco = 13.25;
    break;
    
    default :
    printf ("Sem identificação!\n");
  }

  printf("Quantos?");
  scanf("%d" , &quant);


  final = preco * quant;

   printf("O valor sera: R$ %d,00" , final);
  
  return 0;
}