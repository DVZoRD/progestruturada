#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

typedef struct Carro
{
    char proprietario[50];
    int combustivel;
    char modelo[50];
    char cor[20];
    int chassi;
    int ano;
    char placa[8];

    struct Carro *prox;
} Carro;

Carro *criarListaVazia()
{
    return NULL;
}

Carro *criarCarro()
{
    Carro *novoCarro = (Carro *)malloc(sizeof(Carro));
    if (novoCarro == NULL)
    {
        printf("    !!! ERRO (alocacao de memoria) !!!");
        exit(EXIT_FAILURE);
    }

    novoCarro->prox = NULL;

    return novoCarro;
}

int validarPlaca(const char placa[])
{

    if (strlen(placa) != 7)
    {
        printf("     ERRO (placa deve ter exatamente 7 caracteres)\n");
        return 0;
    }

    for (int i = 0; i < 3; i++)
    {
        if (!isalpha(placa[i]))
        {
            printf("     ERRO (3 primeiros caracteres devem ser letras)\n");
            return 0;
        }
    }

    for (int i = 3; i < 7; i++)
    {
        if (!isdigit(placa[i]))
        {
            printf("     ERRO (4 ultimos caracteres devem ser numeros)\n");
            return 0;
        }
    }

    return 1;
}

Carro *cadastrar(Carro *lista)
{
    Carro *novoCarro = criarCarro();
    srand(time(NULL));
    novoCarro->chassi = rand() % 1000;

    printf("Proprietario do carro --> ");
    fflush(stdin);
    fgets(novoCarro->proprietario, sizeof(novoCarro->proprietario), stdin);
    fflush(stdin);

    do
    {
        printf("Combustivel (1-alcool, 2-diesel, 3-gasolina) --> ");
        scanf("%d", &novoCarro->combustivel);
        fflush(stdin);
    } while ((novoCarro->combustivel != 1) && (novoCarro->combustivel != 2) && (novoCarro->combustivel != 3));

    printf("Modelo do carro --> ");
    fflush(stdin);
    fgets(novoCarro->modelo, sizeof(novoCarro->modelo), stdin);
    fflush(stdin);

    printf("Cor do carro --> ");
    fflush(stdin);
    fgets(novoCarro->cor, sizeof(novoCarro->cor), stdin);
    fflush(stdin);

    do
    {
        printf("Ano de fabricacao (1950 a 2024) --> ");
        scanf("%d", &novoCarro->ano);
    } while ((novoCarro->ano < 1950) || (novoCarro->ano > 2024));

    do
    {
        printf("Placa do carro (ABC1234) --> ");
        fflush(stdin);

        scanf("%7s", novoCarro->placa);
        fflush(stdin);

    } while (!validarPlaca(novoCarro->placa));

    if (lista == NULL)
    {
        return novoCarro;
    }
    else
    {
        Carro *atual = lista;

        while (atual->prox != NULL)
        {
            atual = atual->prox;
        }
        atual->prox = novoCarro;

        return lista;
    }
}

void imprimirLista(Carro *lista)
{
    Carro *atual = lista;

    if (atual == NULL)
    {
        printf("\n   --- LISTA VAZIA ---\n");
        return;
    }
    else
    {

        while (atual != NULL)
        {
            printf("       Chassi: %d\n", atual->chassi);
            printf(" Proprietario: %s", atual->proprietario);
            if (atual->combustivel == 1)
            {
                printf("  Combustivel: alcool\n");
            }
            else if (atual->combustivel == 2)
            {
                printf("  Combustivel: diesel\n");
            }
            else if (atual->combustivel == 3)
            {
                printf("  Combustivel: gasolina\n");
            }
            printf("       Modelo: %s", atual->modelo);
            printf("          Cor: %s", atual->cor);
            printf("          Ano: %d\n", atual->ano);
            printf("        Placa: %s\n", atual->placa);
            printf("---------------------------------\n");

            atual = atual->prox;
        }
    }
}

Carro *pesquisar(Carro *lista, int chassiPesquisa)
{
    Carro *atual = lista;

    if (atual == NULL)
    {
        printf("\n   --- LISTA VAZIA ---\n");

        return NULL;
    }
    else
    {
        while (atual != NULL)
        {
            if (atual->chassi == chassiPesquisa)
            {
                printf("\n--------   CHASSI %d   --------\n", atual->chassi);
                printf(" Proprietario: %s", atual->proprietario);
                if (atual->combustivel == 1)
                {
                    printf("  Combustivel: alcool\n");
                }
                else if (atual->combustivel == 2)
                {
                    printf("  Combustivel: diesel\n");
                }
                else if (atual->combustivel == 3)
                {
                    printf("  Combustivel: gasolina\n");
                }
                printf("       Modelo: %s", atual->modelo);
                printf("          Cor: %s", atual->cor);
                printf("          Ano: %d\n", atual->ano);
                printf("        Placa: %s\n", atual->placa);

                return atual;
            }

            atual = atual->prox;
        }

        printf("\n   !!! CARRO NAO ENCONTRADO !!!\n");

        return NULL;
    }
}

void alterar(Carro *encontrado)
{
    printf("\n-----------------------------------------------------------------\n");
    printf("   Novo proprietario --> ");
    fflush(stdin);
    fgets(encontrado->proprietario, sizeof(encontrado->proprietario), stdin);
    fflush(stdin);

    printf("   Novo combustivel (1-alcool, 2-diesel, 3-gasolina) --> ");
    scanf("%d", &encontrado->combustivel);

    printf("   Novo modelo --> ");
    fflush(stdin);
    fgets(encontrado->modelo, sizeof(encontrado->modelo), stdin);
    fflush(stdin);

    printf("   Nova cor --> ");
    fflush(stdin);
    fgets(encontrado->cor, sizeof(encontrado->cor), stdin);
    fflush(stdin);

    printf("   Novo ano de fabricacao (1950 a 2024) --> ");
    scanf("%d", &encontrado->ano);

    printf("   Nova placa (ABC1234) --> ");
    fflush(stdin);
    fgets(encontrado->placa, sizeof(encontrado->placa), stdin);
    fflush(stdin);

    printf("\n");
}

Carro *excluir(Carro *lista, int chassiPesquisa)
{
    Carro *atual = lista;
    Carro *anterior = NULL;

    while ((atual != NULL) && (atual->chassi != chassiPesquisa))
    {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL)
    {
        if (anterior != NULL)
        {
            anterior->prox = atual->prox;
        }
        else
        {
            lista = atual->prox;
        }

        free(atual);

        printf("\n   ### CARRO EXCLUIDO COM SUCESSO ###\n\n");
    }
    else
    {
        printf("\n   !!! CARRO NAO ENCONTRADO !!!\n");
    }

    return lista;
}

void liberarLista(Carro *lista)
{
    Carro *atual = lista;
    Carro *proximaCarro;

    while (atual != NULL)
    {
        proximaCarro = atual->prox;
        free(atual);
        atual = proximaCarro;
    }
}

void carro2010Diesel(Carro *lista)
{
    int condicao = 0;

    Carro *atual = lista;

    if (atual == NULL)
    {
        printf("\n   --- LISTA VAZIA ---\n");
        return;
    }
    else
    {
        printf("Proprietarios de carros do ano de 2010 ou posterior movidos a diesel:\n");
        while (atual != NULL)
        {
            if ((atual->ano > 2009) && (atual->combustivel == 2))
            {
                printf("     %s", atual->proprietario);
                condicao++;
            }
            atual = atual->prox;
        }

        if (condicao == 0)
        {
            printf("\n   !!! NENHUM CARRO ATINGE AS CONDICOES !!!\n");
        }
    }
}

void placaJ0247(Carro *lista)
{
    int condicao = 0;

    Carro *atual = lista;

    if (atual == NULL)
    {
        printf("\n   --- LISTA VAZIA ---\n");
        return;
    }
    else
    {
        printf("Proprietarios de carros com placas que comecam com 'J' e terminam com 0, 2, 4 ou 7:\n");
        while (atual != NULL)
        {
            if (((atual->placa[0] == 'J') || (atual->placa[0] == 'j')) && ((atual->placa[6] == '0') || (atual->placa[6] == '2') || (atual->placa[6] == '4') || (atual->placa[6] == '7')))
            {
                printf("    Proprietario: %s    Placa: %s\n\n", atual->proprietario, atual->placa);
                condicao++;
            }
            atual = atual->prox;
        }

        if (condicao == 0)
        {
            printf("\n   !!! NENHUM CARRO ATINGE AS CONDICOES !!!\n");
        }
    }
}

void placaVogalPar(Carro *lista)
{
    int condicao = 0;

    Carro *atual = lista;

    if (atual == NULL)
    {
        printf("\n   --- LISTA VAZIA ---\n");
        return;
    }
    else
    {
        printf("Modelo e cor de carros cujas placas possuem vogal na segunda letra e a soma dos numeros seja par:\n");
        while (atual != NULL)
        {
            if (strchr("aeiouAEIOU", atual->placa[1]) != NULL)
            {
                int somaNumeros = 0;

                for (int i = 3; i < 7; i++)
                {
                    somaNumeros += atual->placa[i];
                }
                if (somaNumeros % 2 == 0)
                {
                    printf("    Modelo: %s    Cor: %s    Placa: %s\n\n", atual->modelo, atual->cor, atual->placa);
                }

                condicao++;
            }
            atual = atual->prox;
        }

        if (condicao == 0)
        {
            printf("\n   !!! NENHUM CARRO ATINGE AS CONDICOES !!!\n");
        }
    }
}

void placaSemZero(Carro *lista)
{
    int condicao = 0, chassiTroca;

    Carro *atual = lista;

    if (atual == NULL)
    {
        printf("\n   --- LISTA VAZIA ---\n");
        return;
    }
    else
    {
        printf("\nDigite o chassi do carro que tera o proprietario trocado --> ");
        scanf("%d", &chassiTroca);

        while (atual != NULL)
        {
            if (chassiTroca == atual->chassi)
            {

                if ((atual->placa[3] != '0') && (atual->placa[4] != '0') && (atual->placa[5] != '0') && (atual->placa[6] != '0'))
                {
                    printf("\n--------   CHASSI %d   --------\n", atual->chassi);
                    printf(" Proprietario: %s", atual->proprietario);
                    if (atual->combustivel == 1)
                    {
                        printf("  Combustivel: alcool\n");
                    }
                    else if (atual->combustivel == 2)
                    {
                        printf("  Combustivel: diesel\n");
                    }
                    else if (atual->combustivel == 3)
                    {
                        printf("  Combustivel: gasolina\n");
                    }
                    printf("       Modelo: %s", atual->modelo);
                    printf("          Cor: %s", atual->cor);
                    printf("          Ano: %d\n", atual->ano);
                    printf("        Placa: %s\n\n", atual->placa);

                    printf("** Novo proprietario --> ");
                    fflush(stdin);
                    fgets(atual->proprietario, sizeof(atual->proprietario), stdin);
                    fflush(stdin);

                    return;
                }
                else
                {
                    printf("\n     ERRO (placa possui zero)\n");
                    return;
                }

                condicao++;
            }
            atual = atual->prox;
        }

        if (condicao == 0)
        {
            printf("\n   !!! NENHUM CARRO ATINGE AS CONDICOES !!!\n");
        }
    }
}

int main()
{
    Carro *lista = criarListaVazia();

    Carro *encontrado;

    int opcao, chassiPesquisa;

    do
    {
        printf("\n\n---------------------------------------------------------------------\n");
        printf("|                        CADASTRO DE VEICULO                        |\n");
        printf("---------------------------------------------------------------------\n");
        printf("|  1 - CADASTRAR VEICULO                                            |\n");
        printf("|  2 - MOSTRAR VEICULOS                                             |\n");
        printf("|  3 - PESQUISAR VEICULO                                            |\n");
        printf("|  4 - ALTERAR VEICULO                                              |\n");
        printf("|  5 - EXCLUIR VEICULO                                              |\n");
        printf("|  6 - VEICULOS FABRICADOS APOS 2009 E MOVIDOS A DIESEL             |\n");
        printf("|  7 - PLACAS INICIADAS COM 'J' E TERMIDANAS COM 0, 2, 4 OU 7       |\n");
        printf("|  8 - PLACAS CUJA SEGUNDA LETRA EH VOGAL E SOMA DOS NUMEROS EH PAR |\n");
        printf("|  9 - TROCAR PROPRIETARIO PARA CARRO COM PLACA SEM O NUMERO 0      |\n");
        printf("|  0 - SAIR                                                         |\n");
        printf("---------------------------------------------------------------------\n");
        printf("                        opcao escolhida --> ");
        scanf("%d", &opcao);
        printf("---------------------------------------------------------------------\n");

        switch (opcao)
        {
        case 1:
            lista = cadastrar(lista);
            break;

        case 2:
            imprimirLista(lista);
            break;

        case 3:
            printf("Chassi do carro a ser BUSCADO --> ");
            scanf("%d", &chassiPesquisa);
            encontrado = pesquisar(lista, chassiPesquisa);
            break;

        case 4:
            printf("Chassi do carro a ser ALTERADO --> ");
            scanf("%d", &chassiPesquisa);
            encontrado = pesquisar(lista, chassiPesquisa);

            if (encontrado != NULL)
            {
                alterar(encontrado);
            }
            break;

        case 5:
            printf("Chassi do carro a ser EXCLUIDO --> ");
            scanf("%d", &chassiPesquisa);
            lista = excluir(lista, chassiPesquisa);
            break;

        case 6:
            carro2010Diesel(lista);
            break;

        case 7:
            placaJ0247(lista);
            break;

        case 8:
            placaVogalPar(lista);
            break;

        case 9:
            placaSemZero(lista);
            break;

        default:
            break;
        }

    } while (opcao != 0);

    liberarLista(lista);

    return 0;
}