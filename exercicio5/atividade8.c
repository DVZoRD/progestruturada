int main() {
    int idade, anosdeservico;

    printf("Qual a sua idade: ");
    scanf("%d", &idade);

    printf("Quantos anos de servico: ");
    scanf("%d", &anosdeservico);

    // Check retirement conditions
    if (idade >= 65 || anosdeservico >= 30 || (idade >= 60 && anosdeservico >= 25)) {
        printf("Pode aposentar.\n");
    } else {
        printf("Nao pode aposentar.\n");
    }

    return 0;
}