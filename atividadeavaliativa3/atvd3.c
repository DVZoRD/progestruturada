#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int codigo;
    char descricao[50];
    int quantidade;
    float valor;
} Produto;


typedef struct Node {
    Produto produto;
    struct Node* proximo;
} Node;


typedef struct {
    Node* inicio;
} ListaEstoque;


void inicializarLista(ListaEstoque* lista) {
    lista->inicio = NULL;
}

void adicionarProduto(ListaEstoque* lista) {
    Node* novoNode = (Node*)malloc(sizeof(Node));
    printf("Informe o codigo do produto: ");
    scanf("%d", &novoNode->produto.codigo);
    printf("Informe a descricao do produto: ");
    scanf(" %[^\n]s", novoNode->produto.descricao);
    printf("Informe a quantidade do produto: ");
    scanf("%d", &novoNode->produto.quantidade);
    printf("Informe o valor do produto: ");
    scanf("%f", &novoNode->produto.valor);
    novoNode->proximo = lista->inicio;
    lista->inicio = novoNode;
    printf("Produto adicionado com sucesso!\n");
}

void imprimirRelatorio(ListaEstoque* lista) {
    Node* atual = lista->inicio;
    printf("\nRelatorio de Produtos:\n");
    while (atual != NULL) {
        printf("Codigo: %d\nDescricao: %s\nQuantidade: %d\nValor: %.2f\n\n",
               atual->produto.codigo, atual->produto.descricao,
               atual->produto.quantidade, atual->produto.valor);
        atual = atual->proximo;
    }
}

void pesquisarProduto(ListaEstoque* lista) {
    int codigo;
    printf("Informe o codigo do produto a pesquisar: ");
    scanf("%d", &codigo);

    Node* atual = lista->inicio;
    while (atual != NULL) {
        if (atual->produto.codigo == codigo) {
            printf("Produto encontrado:\nCodigo: %d\nDescricao: %s\nQuantidade: %d\nValor: %.2f\n",
                   atual->produto.codigo, atual->produto.descricao,
                   atual->produto.quantidade, atual->produto.valor);
            return;
        }
        atual = atual->proximo;
    }
    printf("Produto nao encontrado.\n");
}

void removerProduto(ListaEstoque* lista) {
    int codigo;
    printf("Informe o codigo do produto a remover: ");
    scanf("%d", &codigo);

    Node* anterior = NULL;
    Node* atual = lista->inicio;

    while (atual != NULL) {
        if (atual->produto.codigo == codigo) {
            if (anterior == NULL) {
                lista->inicio = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            printf("Produto removido com sucesso.\n");
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    printf("Produto nao encontrado.\n");
}


int main() {
    ListaEstoque lista;
    inicializarLista(&lista);
    int opcao;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Adicionar Produto\n");
        printf("2. Consultar Produtos\n");
        printf("3. Pesquisar Produto por Codigo\n");
        printf("4. Remover Produto\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarProduto(&lista);
                break;
            case 2:
                imprimirRelatorio(&lista);
                break;
            case 3:
                pesquisarProduto(&lista);
                break;
            case 4:
                removerProduto(&lista);
                break;
            case 5:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida. Escolha novamente.\n");
                break;
        }
    } while (opcao != 5);

    return 0;
}
