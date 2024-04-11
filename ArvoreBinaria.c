#include <stdio.h>
#include <stdlib.h>

struct NoArvore
{
    int dado;
    struct NoArvore *esquerda;
    struct NoArvore *direita;
};

struct NoArvore *criarNo(int dado)
{
    struct NoArvore *novoNo = (struct NoArvore *)malloc(sizeof(struct NoArvore));
    if (novoNo == NULL)
    {
        printf("Erro: Falha ao alocar memória para o novo nó.\n");
        exit(-1);
    }
    novoNo->dado = dado;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

struct NoArvore *inserir(struct NoArvore *raiz, int dado)
{
    if (raiz == NULL)
    {
        raiz = criarNo(dado);
    }
    else
    {
        if (dado <= raiz->dado)
        {
            raiz->esquerda = inserir(raiz->esquerda, dado);
        }
        else
        {
            raiz->direita = inserir(raiz->direita, dado);
        }
    }
    return raiz;
}

struct NoArvore *encontrarMinimo(struct NoArvore *raiz)
{
    struct NoArvore *atual = raiz;
    while (atual->esquerda != NULL)
    {
        atual = atual->esquerda;
    }
    return atual;
}

struct NoArvore *excluir(struct NoArvore *raiz, int valor)
{
    if (raiz == NULL)
    {
        return raiz;
    }

    if (valor < raiz->dado)
    {
        raiz->esquerda = excluir(raiz->esquerda, valor);
    }
    else if (valor > raiz->dado)
    {
        raiz->direita = excluir(raiz->direita, valor);
    }
    else
    {
        // Caso 1: Nó folha ou nó com apenas um filho
        if (raiz->esquerda == NULL)
        {
            struct NoArvore *temp = raiz->direita;
            free(raiz);
            return temp;
        }
        else if (raiz->direita == NULL)
        {
            struct NoArvore *temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        // Caso 2: Nó com dois filhos, encontra o sucessor in-order (menor valor na subárvore direita)
        struct NoArvore *temp = encontrarMinimo(raiz->direita);
        raiz->dado = temp->dado;
        raiz->direita = excluir(raiz->direita, temp->dado);
    }
    return raiz;
}

void percorrerEmOrdem(struct NoArvore *raiz)
{
    if (raiz != NULL)
    {
        percorrerEmOrdem(raiz->esquerda);
        printf("%d ", raiz->dado);
        percorrerEmOrdem(raiz->direita);
    }
}

void percorrerPreOrdem(struct NoArvore *raiz)
{
    if (raiz != NULL)
    {
        printf("%d ", raiz->dado);
        percorrerEmOrdem(raiz->esquerda);
        percorrerEmOrdem(raiz->direita);
    }
}

void percorrerPosOrdem(struct NoArvore *raiz)
{
    if (raiz != NULL)
    {
        percorrerEmOrdem(raiz->esquerda);
        percorrerEmOrdem(raiz->direita);
        printf("%d ", raiz->dado);
    }
}

// Função auxiliar para imprimir um caractere precedido por uma quantidade específica de espaços
void imprimeNo(int c, int b)
{
    int i;
    for (i = 0; i < b; i++)
        printf("   ");
    printf("%i\n", c);
}

// Função para exibir a árvore no formato esquerda-raiz-direita segundo Sedgewick
void mostraArvore(struct NoArvore *a, int b)
{
    if (a == NULL)
    {
        return;
    }
    mostraArvore(a->direita, b + 1);
    imprimeNo(a->dado, b); // Convertendo para caractere para imprimir
    mostraArvore(a->esquerda, b + 1);
}

int main()
{
    struct NoArvore *raiz = NULL;

    // Inserindo elementos na árvore
    raiz = inserir(raiz, 1);
    raiz = inserir(raiz, 2);
    raiz = inserir(raiz, 3);
    raiz = inserir(raiz, 4);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 6);
    raiz = inserir(raiz, 7);
    raiz = inserir(raiz, 8);
    raiz = inserir(raiz, 9);
    raiz = inserir(raiz, 10);

    mostraArvore(raiz, 3);
    excluir(raiz,5);
    mostraArvore(raiz,3);
    /* Imprimindo a árvore em ordem
    printf("\nÁrvore em pré-ordem: ");
    percorrerPreOrdem(raiz);
    printf("\n");

    printf("Árvore em ordem: ");
    percorrerEmOrdem(raiz);
    printf("\n");

    printf("Árvore em pós-ordem: ");
    percorrerPosOrdem(raiz);
    printf("\n");*/

    return 0;
}
