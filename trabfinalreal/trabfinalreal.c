#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct carro{
    char dono [50];
    char combustivel [10];
    char modelo [20];
    char cor[20];
    char placaL [4];
    int chassi;
    int ano;
    int placaN;
    struct carro *prox;
}carro;

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

carro* criarListaVazia(){
    return NULL;
}

carro* criarCarro(){
    carro *novoCarro = (carro*)malloc(sizeof(carro));
    if(novoCarro == NULL){
        printf("Não foi possível alocar memória");
        exit(EXIT_FAILURE);
    }
    novoCarro->prox=NULL;
    return novoCarro;
}


//Registro//

carro* registrar(carro *lista){
    carro *novoCarro = criarCarro();

    printf("\n Digite o nome do Dono do carro: ");
    scanf("%s", novoCarro->dono); 
    limparBuffer();

    printf("\n Digite o combustivel utilizado no carro (Alcool, Gasolina ou Diesel): ");
    scanf(" %9s", novoCarro->combustivel);
   limparBuffer();

    printf("\n Digite a cor do carro: ");
    scanf(" %19s", novoCarro->cor);
    limparBuffer();

    printf("\n Digite o modelo do carro: ");
    scanf(" %19s", novoCarro->modelo);
  limparBuffer();
  
    printf("Qual o numero do chassi do carro? ");
    scanf("%d", &novoCarro->chassi);
    limparBuffer();

    printf("De que ano é o carro? ");
    scanf("%d", &novoCarro->ano);
   limparBuffer();

 printf("Digite os tres numeros da placa do veiculo: ");
    scanf(" %3s", novoCarro->placaN);
   limparBuffer();

    printf("Digite as tres primeiras letras da placa do veiculo (Maiusculas): ");
    scanf(" %3s", novoCarro->placaL);
   limparBuffer();

  


    if(lista == NULL){
        return novoCarro;
    }else{
        carro* atual = lista;
        while(atual->prox !=NULL){
            atual = atual->prox;
        }
        atual->prox = novoCarro;
        return lista;
    }
}

//Verificaçao do ANo e do Combustivel do carro// 

void verifAnoCombust(carro *lista){
    carro *atual = lista;
    if(atual == NULL){
        printf("Lista Vazia.\n");
        return;
    }else{
        while(atual !=NULL){
            if(atual->ano >=2010 && strncmp("Diesel" , atual->combustivel,6)==0){
                fflush(stdin);
                printf("Dono: %s" , atual->dono);
                printf("\n");
                atual = atual->prox;
            }else{
                atual = atual->prox;
            }
        }
    }
}

//Verificaçao das placas dos carros//

    void verifPlacas(carro *lista){
        carro *atual = lista;
        if(atual == NULL){
            printf("Lista vazia.\n");
            return;
        }else{
            while(atual != NULL){
                int sobra = atual -> placaN % 10;
                if (atual->placaL[0] == 'J' && (sobra == 0 || sobra == 2 || sobra == 4 || sobra == 7)){
                   fflush(stdin);
                   printf("Dono : %s" , atual->dono);
                   printf("Placa: %s%d" , atual->placaL , atual->placaN);
                   printf("\n");
                   atual = atual->prox; 
                }else{
                    atual = atual->prox;
                }
            }
        }
    }  

//Verificaçao de modelo e de cor dos carros//

void verifModCor(carro *lista){
    carro *atual = lista;
    if(atual == NULL){
        printf("Lista vazia \n");
        return;
    }else{
        while(atual !=NULL){
            if (atual->placaL[1] == 'A' || atual->placaL[1] == 'E' || atual->placaL[1] == 'I' ||  atual->placaL[1] == 'O' || atual->placaL[1] == 'U'){
                int soma = 0;
                while(atual->placaN > 0){
                    int digito = atual->placaN % 10;
                    soma += digito;
                    atual->placaN /= 10;
                 }
                 if(soma % 2 == 0 ){
                    printf("Modelo do carro: %s" , atual->modelo);
                    printf("Cor do carro: %s\n" , atual->cor);
                 }
                 atual = atual->prox;
            }else{
                atual = atual -> prox;
            }
        }
    }
}

//trocar o dono do carro//

void trocarDono(carro *lista, int chassiBusca){
    carro *atual = lista;
    if(atual == NULL){
     printf("Lista vazia.\n");
     return;
    }else{
        while(atual != NULL){
            int numZero = 0;
            if(atual->chassi == chassiBusca){
                int placa = atual->placaN;
                int primDigito = placa / 1000;
                do{
                    int digito = placa % 10;
                    if(digito == 0){
                        numZero++;
                    }
                    placa /= 10;
                }while(placa > 0);

                if(primDigito < 1 ){
                    numZero++;
                }
                
                if(numZero > 0){
                    fflush(stdin);
                    printf("Nao foi possivel trocar o Dono.\n");
                }else{
                    fflush(stdin);
                    printf("Alterar o Dono:");
                    fflush(stdin);
                    fgets(atual->dono, sizeof(atual->dono) , stdin);
                    printf("Dono alterado com sucesso!\n");
                    fflush(stdin);
                }
                return;
            }
            atual = atual->prox;
        }
    }
}

//lista//

 void main(){
    carro *lista = criarListaVazia();
    int opcao, chassiBusca;

    do{
        printf("\nEscolha uma das opcoes a seguir:");
        printf("\n1 - Registrar um carro.");
        printf("\n2 - Listar donos cujos carros sao do ano de 2010 ou posterior e movidos a diesel");
        printf("\n3 - Listar placas que comecem com 'J' e terminem com 0, 2, 4 ou 7.");
        printf("\n4 - Listar modelo e a cor dos carros cujas placas possuem como segunda letra uma vogal e cuja soma dos numeros seja par.");
        printf("\n5 - Trocar dono para carros com placa que nao possui digito 0");
        printf("\n0 - Sair");
        printf("\n\n");
        scanf("%d", &opcao);


        switch(opcao){
            case 1:
            lista = registrar(lista);
            limparBuffer();
            break;
            case 2:
            verifAnoCombust(lista);
            break;
            case 3:
            verifPlacas(lista);
            break;
            case 4:
            verifModCor(lista);
            break;
            case 5:
            printf("Digite o numero do chassi do carro para alterar o dono: ");
            scanf("%d" , &chassiBusca);
            limparBuffer;
            trocarDono(lista,chassiBusca);
            break;

        }
    }while(opcao !=0);
    carro *atual = lista;
    while (atual != NULL){
        carro *temp = atual;
        atual = atual->prox;
        free(temp);
    }
 }



