#include <stdio.h>
#include <stdlib.h>

// Definicao de uma estrutura para representar um no de uma lista duplamente encadeada
typedef struct doubleList {
    int dado; // Valor armazenado no no
    struct doubleList *anterior; // Ponteiro para o no anterior
    struct doubleList *posterior; // Ponteiro para o proximo no
} Lista;

// Funcao para inicializar um novo no da lista duplamente encadeada
Lista* inicializar(int valor) {
    Lista *no = (Lista*) malloc(sizeof(Lista)); // Aloca memoria para um novo no
    if (no == NULL) { // Verifica se a alocacao de memoria falhou
        printf("Erro ao alocar memoria\n");
        exit(1); // Encerra o programa se ocorrer falha
    }
    no->dado = valor; // Define o valor do no
    no->anterior = NULL; // O ponteiro anterior e nulo, pois e um novo no
    no->posterior = NULL; // O ponteiro posterior tambem e nulo
    return no; // Retorna o ponteiro para o novo no
}

// Funcao para inserir um novo valor no final da lista
Lista* inserir(Lista *inicio, int valor) {
    Lista *novo_no = inicializar(valor); // Cria um novo no

    if (inicio == NULL) {
        // Se a lista esta vazia, o novo no se torna o primeiro
        return novo_no;
    } else {
        // Percorre a lista ate o ultimo no
        Lista *atual = inicio;
        while (atual->posterior != NULL) {
            atual = atual->posterior;
        }

        // Insere o novo no no final
        atual->posterior = novo_no;
        novo_no->anterior = atual;
    }
    return inicio; // Retorna o inicio da lista
}

// Funcao para buscar um valor na lista
Lista* buscar(Lista *inicio, int valor) {
    Lista *atual = inicio;
    // Percorre a lista procurando o valor
    while (atual != NULL) {
        if (atual->dado == valor) {
            return atual; // Retorna o ponteiro para o no encontrado
        }
        atual = atual->posterior; // Avanca para o proximo no
    }
    return NULL; // Se nao encontrar, retorna NULL
}

// Funcao para remover um no da lista
Lista* remover(Lista *inicio, int valor) {
    Lista *no_remover = buscar(inicio, valor); // Busca o no a ser removido
    
    if (no_remover == NULL) { // Se o valor nao foi encontrado
        printf("Valor %d nao encontrado na lista.\n", valor);
        return inicio; // Retorna a lista inalterada
    }
    
    // Se for o primeiro no
    if (no_remover->anterior == NULL) {
        inicio = no_remover->posterior; // Atualiza o inicio
        if (inicio != NULL) {
            inicio->anterior = NULL; // Define o novo inicio
        }
    }
    // Se for um no do meio ou o ultimo
    else {
        no_remover->anterior->posterior = no_remover->posterior;
        if (no_remover->posterior != NULL) {
            no_remover->posterior->anterior = no_remover->anterior;
        }
    }
    
    free(no_remover); // Libera a memoria do no removido
    printf("Valor %d removido da lista.\n", valor);
    
    return inicio; // Retorna o inicio atualizado
}

// Funcao para exibir os elementos da lista
void exibir_lista(Lista *inicio) {
    Lista *atual = inicio;
    // Percorre a lista imprimindo os valores
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->posterior;
    }
    printf("\n"); // Quebra de linha apos exibir todos os valores
}

int main() {
    // Inicializando a lista como vazia
    Lista* lista = NULL;

    // Inserindo valores na lista
    lista = inserir(lista, 10);
    lista = inserir(lista, 20);
    lista = inserir(lista, 30);

    // Exibindo a lista
    printf("Lista apos insercoes: ");
    exibir_lista(lista);

    // Testando a busca
    int valor_busca = 20;
    Lista* resultado_busca = buscar(lista, valor_busca);
    if (resultado_busca != NULL) {
        printf("Valor %d encontrado na lista.\n", resultado_busca->dado);
    } else {
        printf("Valor %d nao encontrado na lista.\n", valor_busca);
    }

    // Testando a remocao
    int valor_remover = 20;
    lista = remover(lista, valor_remover);

    // Exibindo a lista apos a remocao
    printf("Lista apos remocao: ");
    exibir_lista(lista);

    // Tentando buscar o valor removido
    int valor = 20;
    resultado_busca = buscar(lista, valor);
    if (resultado_busca != NULL) {
        printf("Valor %d ainda esta na lista.\n", resultado_busca->dado);
    } else {
        printf("Valor %d nao esta mais na lista.\n", valor);
    }

    // Liberando a memoria da lista restante
    while (lista != NULL) {
        Lista *prox = lista->posterior;
        free(lista);
        lista = prox;
    }

    return 0; // Fim do programa
}
