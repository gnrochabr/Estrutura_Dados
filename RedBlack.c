#include <stdio.h>
#include <stdlib.h>

// Definição dos possíveis valores de cor
#define VERMELHO 0
#define PRETO 1

// Definição da estrutura de um nó da árvore Red-Black
struct No
{
    int valor;
    int cor;
    struct No *esquerda, *direita, *pai;
};

typedef struct No No;

// Função para criar um novo nó
No *criarNo(int valor)
{
    No *novoNo = (No *)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->cor = VERMELHO;
    novoNo->esquerda = novoNo->direita = novoNo->pai = NULL;
    return novoNo;
}

// Função para fazer a rotação à esquerda
void rotacaoEsquerda(No **raiz, No *x)
{
    No *y = x->direita;
    x->direita = y->esquerda;
    if (y->esquerda != NULL)
        y->esquerda->pai = x;
    y->pai = x->pai;
    if (x->pai == NULL)
        *raiz = y;
    else if (x == x->pai->esquerda)
        x->pai->esquerda = y;
    else
        x->pai->direita = y;
    y->esquerda = x;
    x->pai = y;
}

// Função para fazer a rotação à direita
void rotacaoDireita(No **raiz, No *x)
{
    No *y = x->esquerda;
    x->esquerda = y->direita;
    if (y->direita != NULL)
        y->direita->pai = x;
    y->pai = x->pai;
    if (x->pai == NULL)
        *raiz = y;
    else if (x == x->pai->direita)
        x->pai->direita = y;
    else
        x->pai->esquerda = y;
    y->direita = x;
    x->pai = y;
}

// Função para balancear a árvore após a inserção de um nó
void corrigirViolacao(No **raiz, No *z)
{
    while (z != *raiz && z->pai->cor == VERMELHO)
    {
        if (z->pai == z->pai->pai->esquerda)
        {
            No *y = z->pai->pai->direita;
            if (y != NULL && y->cor == VERMELHO)
            {
                z->pai->cor = PRETO;
                y->cor = PRETO;
                z->pai->pai->cor = VERMELHO;
                z = z->pai->pai;
            }
            else
            {
                if (z == z->pai->direita)
                {
                    z = z->pai;
                    rotacaoEsquerda(raiz, z);
                }
                z->pai->cor = PRETO;
                z->pai->pai->cor = VERMELHO;
                rotacaoDireita(raiz, z->pai->pai);
            }
        }
        else
        {
            No *y = z->pai->pai->esquerda;
            if (y != NULL && y->cor == VERMELHO)
            {
                z->pai->cor = PRETO;
                y->cor = PRETO;
                z->pai->pai->cor = VERMELHO;
                z = z->pai->pai;
            }
            else
            {
                if (z == z->pai->esquerda)
                {
                    z = z->pai;
                    rotacaoDireita(raiz, z);
                }
                z->pai->cor = PRETO;
                z->pai->pai->cor = VERMELHO;
                rotacaoEsquerda(raiz, z->pai->pai);
            }
        }
    }
    (*raiz)->cor = PRETO;
}

// Função para inserir um novo nó na árvore Red-Black
void inserir(No **raiz, int valor)
{
    No *z = criarNo(valor);
    No *y = NULL;
    No *x = *raiz;

    while (x != NULL)
    {
        y = x;
        if (z->valor < x->valor)
            x = x->esquerda;
        else
            x = x->direita;
    }
    z->pai = y;
    if (y == NULL)
        *raiz = z;
    else if (z->valor < y->valor)
        y->esquerda = z;
    else
        y->direita = z;

    corrigirViolacao(raiz, z);
}

// Função para imprimir a árvore Red-Black em ordem
void emOrdem(No *raiz)
{
    if (raiz != NULL)
    {
        emOrdem(raiz->esquerda);
        if (raiz->cor == 0)
            printf("%d RED", raiz->valor);
        else
            printf("%d BLK", raiz->valor);
        emOrdem(raiz->direita);
    }
}

// Função para imprimir a árvore de acordo com o formato esquerda-raiz-direita segundo Sedgewick
void imprimeArvoreRB(No *raiz, int b)
{
    if (raiz != NULL)
    {
        // Chama a função recursivamente para percorrer a subárvore direita
        imprimeArvoreRB(raiz->direita, b + 1);

        // Imprime o valor do nó atual com um espaçamento proporcional à sua profundidade
        for (int i = 0; i < b; i++)
            printf("       "); // espaços por nível
        if (raiz->cor == 0)
            printf("\033[31m%d\033[0m\n\n", raiz->valor);
        else
            printf("%d\n\n", raiz->valor);

        // Chama a função recursivamente para percorrer a subárvore esquerda
        imprimeArvoreRB(raiz->esquerda, b + 1);
    }
}

int main()
{
    struct No *raiz = NULL;
    // Exemplo de inserção de valores na árvore Red-Black
    int vetor[] = {12, 31, 20, 17, 11, 8, 3, 24, 15, 33};
    int i, tam = sizeof(vetor) / sizeof(vetor[0]);
    for (i = 0; i < tam; i++)
        inserir(&raiz, vetor[i]);
    printf("Árvore Red-Black: \n");
    imprimeArvoreRB(raiz, 3);
    printf("\n");

    return 0;
}
