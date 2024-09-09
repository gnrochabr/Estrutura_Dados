#include<stdio.h>
#include<stdlib.h>

// Definição de um nó na lista encadeada
typedef struct no {
  int valor;          // Valor armazenado no nó
  struct no* prox;    // Ponteiro para o próximo nó da lista
} No;

// Função para imprimir todos os elementos da lista
void imprime_lista(No *lista) {
  while (lista != NULL) {  // Enquanto a lista não estiver vazia
    printf("%d ", lista->valor);  // Imprime o valor do nó atual
    lista = lista->prox;  // Avança para o próximo nó
  }
  printf("\n\n");  // Quebra de linha após imprimir todos os valores
}

// Função para inserir um novo nó no início da lista
void insere_comeco(No **lista, int valor){
  No* no;  // Declaração de um ponteiro para o novo nó
  no = (No*)malloc(sizeof(No));  // Aloca memória para o novo nó
  no->valor = valor;  // Define o valor do novo nó
  no->prox = *lista;  // Faz o novo nó apontar para o início da lista
  *lista = no;  // Atualiza o início da lista para o novo nó
  printf("Valor %d inserido no comeco.\n", valor);  // Informa que o valor foi inserido no começo
  imprime_lista(*lista);  // Imprime a lista atualizada
}

// Função para inserir um novo nó no final da lista
void insere_final(No **lista, int v) {
  No *n, *aux;  // Declara dois ponteiros: um para o novo nó e outro auxiliar para percorrer a lista
  n = (No*)malloc(sizeof(No));  // Aloca memória para o novo nó
  n->valor = v;  // Define o valor do novo nó
  n->prox = NULL;  // Define o próximo nó como NULL, pois este será o último nó

  if (*lista == NULL) {  // Se a lista estiver vazia
    *lista = n;  // O novo nó será o primeiro e único nó
  } else {
    aux = *lista;  // Usa o ponteiro auxiliar para percorrer a lista
    while (aux->prox != NULL) {  // Encontra o último nó da lista
      aux = aux->prox;  // Avança para o próximo nó
    }
    aux->prox = n;  // Faz o último nó atual apontar para o novo nó
  }
  printf("Valor %d inserido no final.\n", v);  // Informa que o valor foi inserido no final
  imprime_lista(*lista);  // Imprime a lista atualizada
}

// Função para remover o nó do início da lista
int remove_inicio(No **lista) {
  No* n;  // Ponteiro para o nó que será removido
  int v;  // Variável para armazenar o valor removido
  if (*lista == NULL) return -1;  // Se a lista estiver vazia, retorna -1

  n = *lista;  // Aponta para o primeiro nó da lista
  printf("Valor %d removido no comeco.\n", n->valor);  // Informa o valor que será removido
  *lista = n->prox;  // Atualiza o início da lista para o próximo nó
  v = n->valor;  // Armazena o valor do nó removido
  free(n);  // Libera a memória do nó removido
  imprime_lista(*lista);  // Imprime a lista atualizada
  return v;  // Retorna o valor removido
}

// Função para remover o nó do final da lista
int remove_final(No **lista) {
  No *n, *aux;  // Ponteiros para o nó que será removido e um auxiliar para percorrer a lista
  int v;  // Variável para armazenar o valor removido
  if (*lista == NULL)  // Se a lista estiver vazia
    return -1;  // Retorna -1

  if ((*lista)->prox == NULL) {  // Se a lista tiver apenas um nó
    n = *lista;  // Aponta para o único nó da lista
    *lista = NULL;  // A lista ficará vazia após a remoção
  } else {
    aux = *lista;  // Usa o ponteiro auxiliar para percorrer a lista
    while (aux->prox->prox != NULL)  // Encontra o penúltimo nó
      aux = aux->prox;  // Avança para o próximo nó

    n = aux->prox;  // O último nó será removido
    aux->prox = NULL;  // O penúltimo nó agora será o último, então seu próximo será NULL
  }
  printf("Valor %d removido no final.\n", n->valor);  // Informa o valor removido
  v = n->valor;  // Armazena o valor do nó removido
  free(n);  // Libera a memória do nó removido
  imprime_lista(*lista);  // Imprime a lista atualizada
  return v;  // Retorna o valor removido
}

// Função principal
int main() {
  No *lista;  // Declaração de um ponteiro para a lista encadeada
  lista = NULL;  // Inicializa a lista como vazia (NULL)

  insere_comeco(&lista, 3);  // Insere o valor 3 no início da lista
  insere_comeco(&lista, 8);  // Insere o valor 8 no início da lista
  insere_comeco(&lista, 6);  // Insere o valor 6 no início da lista
  insere_comeco(&lista, 9);  // Insere o valor 9 no início da lista

  insere_final(&lista, 10);  // Insere o valor 10 no final da lista
  insere_final(&lista, 13);  // Insere o valor 13 no final da lista
  insere_final(&lista, 15);  // Insere o valor 15 no final da lista
  insere_final(&lista, 17);  // Insere o valor 17 no final da lista

  remove_inicio(&lista);  // Remove o primeiro nó da lista
  remove_inicio(&lista);  // Remove o primeiro nó da lista novamente
  remove_final(&lista);   // Remove o último nó da lista

  return 0;  // Retorna 0 para indicar que o programa terminou com sucesso
}
