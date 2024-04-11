#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

// Estrutura para representar um nó na árvore de Huffman
typedef struct No
{
    char caractere;
    int frequencia;
    struct No *esquerda, *direita;
} No;

// Estrutura para representar uma fila de prioridade
typedef struct
{
    int tamanho;
    int capacidade;
    No **array;
} FilaPrioridade;

// Função para criar um novo nó
No *novoNo(char caractere, int frequencia)
{
    No *no = (No *)malloc(sizeof(No));
    no->caractere = caractere;
    no->frequencia = frequencia;
    no->esquerda = no->direita = NULL;
    return no;
}

// Função para criar uma fila de prioridade
FilaPrioridade *criarFilaPrioridade(int capacidade)
{
    FilaPrioridade *fila = (FilaPrioridade *)malloc(sizeof(FilaPrioridade));
    fila->tamanho = 0;
    fila->capacidade = capacidade;
    fila->array = (No **)malloc(capacidade * sizeof(No *));
    return fila;
}

// Função para trocar dois nós
void trocar(No **a, No **b)
{
    No *temp = *a;
    *a = *b;
    *b = temp;
}

// Função para fazer heapify de uma subárvore enraizada no índice i
void heapify(FilaPrioridade *fila, int indice)
{
    int menor = indice;
    int esquerda = 2 * indice + 1;
    int direita = 2 * indice + 2;

    if (esquerda < fila->tamanho && fila->array[esquerda]->frequencia < fila->array[menor]->frequencia)
        menor = esquerda;

    if (direita < fila->tamanho && fila->array[direita]->frequencia < fila->array[menor]->frequencia)
        menor = direita;

    if (menor != indice)
    {
        trocar(&fila->array[indice], &fila->array[menor]);
        heapify(fila, menor);
    }
}

// Função para verificar se a fila de prioridade tem tamanho 1
int tamanhoUm(FilaPrioridade *fila)
{
    return (fila->tamanho == 1);
}

// Função para extrair o nó mínimo (frequência mínima) da fila de prioridade
No *extrairMinimo(FilaPrioridade *fila)
{
    No *minimo = fila->array[0];
    fila->array[0] = fila->array[fila->tamanho - 1];
    --fila->tamanho;
    heapify(fila, 0);
    return minimo;
}

// Função para inserir um novo nó na fila de prioridade
void inserir(FilaPrioridade *fila, No *no)
{
    ++fila->tamanho;
    int i = fila->tamanho - 1;
    while (i && no->frequencia < fila->array[(i - 1) / 2]->frequencia)
    {
        fila->array[i] = fila->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    fila->array[i] = no;
}

// Função para construir a árvore de Huffman
No *construirArvoreHuffman(char caracteres[], int frequencias[], int tamanho)
{
    No *esquerda, *direita, *topo;
    FilaPrioridade *fila = criarFilaPrioridade(tamanho);

    for (int i = 0; i < tamanho; ++i)
        inserir(fila, novoNo(caracteres[i], frequencias[i]));

    while (!tamanhoUm(fila))
    {
        esquerda = extrairMinimo(fila);
        direita = extrairMinimo(fila);

        topo = novoNo('$', esquerda->frequencia + direita->frequencia);
        topo->esquerda = esquerda;
        topo->direita = direita;

        inserir(fila, topo);
    }

    return extrairMinimo(fila);
}

// Função para imprimir códigos Huffman a partir da árvore de Huffman
void imprimirCodigosHuffman(No *raiz, int codigo[], int indice)
{
    if (raiz->esquerda)
    {
        codigo[indice] = 0;
        imprimirCodigosHuffman(raiz->esquerda, codigo, indice + 1);
    }

    if (raiz->direita)
    {
        codigo[indice] = 1;
        imprimirCodigosHuffman(raiz->direita, codigo, indice + 1);
    }

    if (!raiz->esquerda && !raiz->direita)
    {
        printf("%c: ", raiz->caractere);
        for (int i = 0; i < indice; ++i)
            printf("%d", codigo[i]);
        printf("\n");
    }
}

// Função principal
int main()
{
    char caracteres[MAX_SIZE];
    int frequencias[MAX_SIZE] = {0};

    printf("Digite uma string: ");
    gets(caracteres);

    int tamanho = strlen(caracteres);

    for (int i = 0; i < tamanho; ++i)
        frequencias[caracteres[i]]++;

    No *raiz = construirArvoreHuffman(caracteres, frequencias, tamanho);

    int codigo[MAX_SIZE], indice = 0;
    printf("Codigos Huffman:\n");
    imprimirCodigosHuffman(raiz, codigo, indice);

    return 0;
}
