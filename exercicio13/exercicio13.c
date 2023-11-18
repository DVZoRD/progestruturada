#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERS 1000
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_ADDRESS_LENGTH 100

typedef struct {
    int id;
    char nome[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char sexo[MAX_NAME_LENGTH];
    char endereco[MAX_ADDRESS_LENGTH];
    double altura;
    int vacina;
} Usuario;

Usuario usuarios[MAX_USERS];
int numUsuarios = 0;

int gerarId() {
    return rand() % 10000 + 1; // Gera um número aleatório de 1 a 10000
}

void adicionarUsuario() {
    if (numUsuarios < MAX_USERS) {
        Usuario novoUsuario;
        novoUsuario.id = gerarId();

        printf("Nome completo: ");
        getchar(); // Limpa o buffer do teclado
        fgets(novoUsuario.nome, sizeof(novoUsuario.nome), stdin);
        novoUsuario.nome[strcspn(novoUsuario.nome, "\n")] = '\0';

        printf("Email: ");
        fgets(novoUsuario.email, sizeof(novoUsuario.email), stdin);
        novoUsuario.email[strcspn(novoUsuario.email, "\n")] = '\0';

        printf("Sexo (Feminino, Masculino ou Indiferente): ");
        fgets(novoUsuario.sexo, sizeof(novoUsuario.sexo), stdin);
        novoUsuario.sexo[strcspn(novoUsuario.sexo, "\n")] = '\0';

        printf("Endereco: ");
        fgets(novoUsuario.endereco, sizeof(novoUsuario.endereco), stdin);
        novoUsuario.endereco[strcspn(novoUsuario.endereco, "\n")] = '\0';

        do {
            printf("Altura (entre 1 e 2 metros): ");
            scanf("%lf", &novoUsuario.altura);
        } while (novoUsuario.altura < 1 || novoUsuario.altura > 2);

        do {
            printf("Vacina (1 para sim, 0 para nao): ");
            scanf("%d", &novoUsuario.vacina);
        } while (novoUsuario.vacina != 0 && novoUsuario.vacina != 1);

        usuarios[numUsuarios++] = novoUsuario;
        printf("Usuario cadastrado com sucesso!\n");
    } else {
        printf("Limite de usuarios atingido!\n");
    }
}
void editarUsuario() {
    int id;
    printf("Digite o ID do usuario a ser editado: ");
    scanf("%d", &id);

    int encontrado = 0;
    for (int i = 0; i < numUsuarios; i++) {
        if (usuarios[i].id == id) {
            printf("Novo Nome completo: ");
            getchar();
            fgets(usuarios[i].nome, sizeof(usuarios[i].nome), stdin);
            usuarios[i].nome[strcspn(usuarios[i].nome, "\n")] = '\0';

            printf("Novo Email: ");
            fgets(usuarios[i].email, sizeof(usuarios[i].email), stdin);
            usuarios[i].email[strcspn(usuarios[i].email, "\n")] = '\0';

            printf("Novo Sexo (Feminino, Masculino ou Indiferente): ");
            fgets(usuarios[i].sexo, sizeof(usuarios[i].sexo), stdin);
            usuarios[i].sexo[strcspn(usuarios[i].sexo, "\n")] = '\0';

            printf("Novo Endereco: ");
            fgets(usuarios[i].endereco, sizeof(usuarios[i].endereco), stdin);
            usuarios[i].endereco[strcspn(usuarios[i].endereco, "\n")] = '\0';

            do {
                printf("Nova Altura (entre 1 e 2 metros): ");
                scanf("%lf", &usuarios[i].altura);
            } while (usuarios[i].altura < 1 || usuarios[i].altura > 2);

            do {
                printf("Vacina (1 para sim, 0 para nao): ");
                scanf("%d", &usuarios[i].vacina);
            } while (usuarios[i].vacina != 0 && usuarios[i].vacina != 1);

            printf("Usuario editado com sucesso!\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Usuario nao encontrado!\n");
    }
}

void excluirUsuario() {
    int id;
    printf("Digite o ID do usuario a ser excluido: ");
    scanf("%d", &id);

    int encontrado = 0;
    for (int i = 0; i < numUsuarios; i++) {
        if (usuarios[i].id == id) {
            for (int j = i; j < numUsuarios - 1; j++) {
                usuarios[j] = usuarios[j + 1];
            }
            numUsuarios--;
            printf("Usuario excluido com sucesso!\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Usuario nao encontrado!\n");
    }
}

void buscarPorEmail() {
    char email[MAX_EMAIL_LENGTH];
    printf("Digite o email do usuario a ser buscado: ");
    getchar(); // Limpa o buffer do teclado
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    int encontrado = 0;
    for (int i = 0; i < numUsuarios; i++) {
        if (strcmp(usuarios[i].email, email) == 0) {
            printf("Usuario encontrado:\n");
            printf("ID: %d\n", usuarios[i].id);
            printf("Nome: %s\n", usuarios[i].nome);
            printf("Email: %s\n", usuarios[i].email);
            printf("Sexo: %s\n", usuarios[i].sexo);
            printf("Endereco: %s\n", usuarios[i].endereco);
            printf("Altura: %.2lf\n", usuarios[i].altura);
            printf("Vacina: %d\n", usuarios[i].vacina);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Usuario nao encontrado!\n");
    }
}

void imprimirUsuarios() {
    printf("Usuarios cadastrados:\n");
    for (int i = 0; i < numUsuarios; i++) {
        printf("ID: %d\n", usuarios[i].id);
        printf("Nome: %s\n", usuarios[i].nome);
        printf("Email: %s\n", usuarios[i].email);
        printf("Sexo: %s\n", usuarios[i].sexo);
        printf("Endereco: %s\n", usuarios[i].endereco);
        printf("Altura: %.2lf\n", usuarios[i].altura);
        printf("Vacina: %d\n", usuarios[i].vacina);
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // Inicializa a semente para números aleatórios

    char opcao;
    do {
        printf("\nEscolha uma opcao:\n");
        printf("1 - Adicionar usuario\n");
        printf("2 - Editar usuario\n");
        printf("3 - Excluir usuario\n");
        printf("4 - Buscar usuario pelo email\n");
        printf("5 - Imprimir todos os usuarios\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                adicionarUsuario();
                break;
            case '2':
                editarUsuario();
                break;
            case '3':
                excluirUsuario();
                break;
            case '4':
                buscarPorEmail();
                break;
            case '5':
                imprimirUsuarios();
                break;
            case '0':
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != '0');

    return 0;
}
