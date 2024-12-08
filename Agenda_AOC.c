/*
faça uma agenda capaz de incluir, apagar, buscar e listar quantas pessoas o usuario desejar, porem,
toda informação incluida na agenda deve ficar num único lugar chamado: "void *pBuffer".
não pergutem para o usuario quantas pessoas ele vai incluir. não pode alocar espaço para mais pessoas que necessario.
cada pessoa tem nome[10], idade e telefone.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char nome[10];
    int idade;
    int telefone;
} Pessoa;

void incluir(void *pBuffer, int *qtd);
void listar(void *pBuffer, int qtd);
void buscar(void *pBuffer, int qtd);
void apagar(void *pBuffer, int *qtd);

int main()
{
    void *pBuffer = NULL;
    int op, qtd = 0;
    int tamanhoAtual = 1;

    pBuffer = malloc(sizeof(Pessoa) * tamanhoAtual);

    while (1)
    {
        printf("\n1-Incluir\n2-Listar\n3-Buscar\n4-Apagar\n0-Sair\nOpcao: ");
        scanf("%d", &op);

        if (op == 0 || op > 4)
            break;

        switch (op)
        {
        case 1:
            if (qtd == tamanhoAtual)
            {
                tamanhoAtual *= 2;
                pBuffer = realloc(pBuffer, sizeof(Pessoa) * tamanhoAtual);
            }
            incluir(pBuffer, &qtd);
            break;
        case 2:
            listar(pBuffer, qtd);
            break;
        case 3:
            buscar(pBuffer, qtd);
            break;
        case 4:
            apagar(pBuffer, &qtd);
            break;
        }
    }

    free(pBuffer);
    return 0;
}

void incluir(void *pBuffer, int *qtd)
{
    Pessoa *agenda = (Pessoa *)pBuffer;
    Pessoa novaPessoa;

    printf("Nome: ");
    scanf("%s", novaPessoa.nome);
    printf("Idade: ");
    scanf("%d", &novaPessoa.idade);
    printf("Telefone: ");
    scanf("%d", &novaPessoa.telefone);

    agenda[*qtd] = novaPessoa;
    (*qtd)++;
}

void listar(void *pBuffer, int qtd)
{
    Pessoa *agenda = (Pessoa *)pBuffer;

    for (int i = 0; i < qtd; i++)
    {
        printf("|%s|%d|%d|", agenda[i].nome, agenda[i].idade, agenda[i].telefone);
    }
}

void buscar(void *pBuffer, int qtd)
{
    Pessoa *agenda = (Pessoa *)pBuffer;
    char nome[10];

    printf("digite o nome: ");
    scanf("%s", nome);

    for (int i = 0; i < qtd; i++)
    {
        if (strcmp(agenda[i].nome, nome) == 0)
        {
            printf("\nNome: %s", agenda[i].nome);
            printf("\nIdade: %d", agenda[i].idade);
            printf("\nTelefone: %d\n", agenda[i].telefone);
            return;
        }
    }
    printf("pessoa nao encontrada\n");
}

void apagar(void *pBuffer, int *qtd)
{
    Pessoa *agenda = (Pessoa *)pBuffer;
    char nome[10];

    printf("digite o nome para apagar: ");
    scanf("%s", nome);

    for (int i = 0; i < *qtd; i++)
    {
        if (strcmp(agenda[i].nome, nome) == 0)
        {
            for (int j = i; j < *qtd - 1; j++)
            {
                agenda[j] = agenda[j + 1];
            }
            (*qtd)--;
            return;
        }
    }
    printf("pessoa nao encontrada\n");
}