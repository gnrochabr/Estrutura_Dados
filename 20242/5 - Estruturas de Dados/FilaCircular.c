#include <stdio.h>     // Biblioteca padrão de entrada e saída
#include <stdlib.h>    // Biblioteca padrão para alocação de memória
#include <stdbool.h>   // Biblioteca para uso de tipo booleano

// Estrutura que define uma Fila
struct Fila {
    int capacidade;    // Capacidade máxima da fila
    int *dados;      // Array para armazenar os elementos da fila
    int primeiro;      // Índice do primeiro elemento da fila
    int ultimo;        // Índice do último elemento da fila
    int nItens;        // Número atual de itens na fila
};

// Função para criar uma fila com capacidade especificada
void criarFila(struct Fila *f, int c) {
    f->capacidade = c;  // Define a capacidade da fila
    f->dados = (int*) malloc(f->capacidade * sizeof(int));  // Aloca memória para os dados da fila
    f->primeiro = 0;    // Inicializa o índice do primeiro elemento
    f->ultimo = -1;     // Inicializa o índice do último elemento
    f->nItens = 0;      // Inicializa o número de itens na fila como zero
}

// Função para inserir um elemento na fila
void inserir(struct Fila *f, int v) {
    if (f->ultimo == f->capacidade - 1)  // Se o último índice atingiu a capacidade máxima
        f->ultimo = -1;  // Reinicia o índice do último para -1

    f->ultimo++;  // Incrementa o índice do último
    f->dados[f->ultimo] = v;  // Insere o valor na posição do último índice
    f->nItens++;  // Incrementa o número de itens na fila
}

// Função para remover um elemento da fila
int remover(struct Fila *f) {
    int temp = f->dados[f->primeiro++];  // Armazena o valor do primeiro elemento e incrementa o índice

    if (f->primeiro == f->capacidade)  // Se o primeiro índice atinge a capacidade máxima
        f->primeiro = 0;  // Reinicia o índice do primeiro para 0

    f->nItens--;  // Decrementa o número de itens na fila
    return temp;  // Retorna o valor removido
}

// Função para verificar se a fila está vazia
int estaVazia(struct Fila *f) {
    return (f->nItens == 0);  // Retorna verdadeiro se o número de itens for zero
}

// Função para verificar se a fila está cheia
int estaCheia(struct Fila *f) {
    return (f->nItens == f->capacidade);  // Retorna verdadeiro se o número de itens for igual à capacidade
}

// Função para mostrar todos os elementos da fila
void mostrarFila(struct Fila *f) {
    int cont, i;

    for (cont = 0, i = f->primeiro; cont < f->nItens; cont++) {  // Percorre a fila a partir do primeiro elemento
        printf("%d ", f->dados[i++]);  // Imprime o elemento atual

        if (i == f->capacidade)  // Se o índice atual atinge a capacidade máxima
            i = 0;  // Reinicia o índice para 0
    }
    printf("\n\n");
}

// Função principal
int main() {
    int opcao, capa;
    int valor;
    struct Fila umaFila;

    // Cria a fila com capacidade especificada pelo usuário
    printf("\nCapacidade da fila? ");
    scanf("%d", &capa);
    criarFila(&umaFila, capa);

    // Apresenta o menu para o usuário
    while (true) {
        printf("\n1 - Inserir elemento\n2 - Remover elemento\n3 - Mostrar Fila\n0 - Sair\n\nOpcao? ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0: 
                exit(0);  // Sai do programa
                break;

            case 1:  // Insere um elemento na fila
                if (estaCheia(&umaFila)) {
                    printf("\nFila Cheia!!!\n\n");
                } else {
                    printf("\nValor do elemento a ser inserido? ");
                    scanf("%d", &valor);
                    inserir(&umaFila, valor);  // Insere o valor na fila
                }
                break;

            case 2:  // Remove um elemento da fila
                if (estaVazia(&umaFila)) {
                    printf("\nFila vazia!!!\n\n");
                } else {
                    valor = remover(&umaFila);  // Remove o valor da fila
                    printf("\n%d removido com sucesso\n\n", valor); 
                }
                break;

            case 3:  // Mostra todos os elementos da fila
                if (estaVazia(&umaFila)) {
                    printf("\nFila vazia!!!\n\n");
                } else {
                    printf("\nConteudo da fila => ");
                    mostrarFila(&umaFila);  // Mostra os valores da fila
                }
                break;

            default:
                printf("\nOpcao Invalida\n\n");  // Mensagem para opção inválida
        }
    }
    return 0;  // Retorna 0 para indicar que o programa terminou corretamente
}
