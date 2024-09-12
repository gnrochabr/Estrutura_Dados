#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Definição de um nó na lista encadeada
typedef struct no {
  char nome[10];          // nome armazenado no nó
  struct no* prox;    // Ponteiro para o próximo nó da lista
} No;

// Função para imprimir todos os elementos da lista
void imprime_lista(No *lista) {
  while (lista != NULL) {  // Enquanto a lista não estiver vazia
    if(lista->prox!=NULL){
    printf("%s que amava %s, ", lista->nome, lista->prox->nome);  // Imprime o nome do nó atual
    lista = lista->prox;}
    else{
     printf("%s que não amava ninguém!", lista->nome);
     lista = lista->prox;
    }  
    // Avança para o próximo nó
  }
  printf("\n\n");  // Quebra de linha após imprimir todos os nomees
}

// Função para inserir um novo nó no início da lista
void insere_comeco(No **lista, char pessoa[]){
  No* no;  // Declaração de um ponteiro para o novo nó
  no = (No*)malloc(sizeof(No));  // Aloca memória para o novo nó
  strcpy(no->nome,pessoa);  // Define o nome do novo nó
  no->prox = *lista;  // Faz o novo nó apontar para o início da lista
  *lista = no;  // Atualiza o início da lista para o novo nó
  printf("nome %s inserido no comeco.\n", pessoa);  // Informa que o nome foi inserido no começo
  imprime_lista(*lista);  // Imprime a lista atualizada
}

// Função para inserir um novo nó no final da lista
void insere_final(No **lista, char pessoa[]) {
  No *n, *aux;  // Declara dois ponteiros: um para o novo nó e outro auxiliar para percorrer a lista
  n = (No*)malloc(sizeof(No));  // Aloca memória para o novo nó
  strcpy(n->nome,pessoa);  // Define o nome do novo nó
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
  printf("nome %s inserido no final.\n", pessoa);  // Informa que o nome foi inserido no final
  imprime_lista(*lista);  // Imprime a lista atualizada
}

// Função para remover o nó do início da lista
char* remove_inicio(No **lista) {
  No* n;  // Ponteiro para o nó que será removido
  char *v[10];  // Variável para armazenar o nome removido
  if (*lista == NULL) return "erro";  // Se a lista estiver vazia, retorna um erro

  n = *lista;  // Aponta para o primeiro nó da lista
  printf("nome %s removido no comeco.\n", n->nome);  // Informa o nome que será removido
  *lista = n->prox;  // Atualiza o início da lista para o próximo nó
  strcpy(*v,n->nome);  // Armazena o nome do nó removido
  free(n);  // Libera a memória do nó removido
  imprime_lista(*lista);  // Imprime a lista atualizada
  return *v;  // Retorna o nome removido
}

// Função para remover o nó do final da lista
 char* remove_final(No **lista) {
  No *n, *aux;  // Ponteiros para o nó que será removido e um auxiliar para percorrer a lista
  char *v[10];  // Variável para armazenar o nome removido
  if (*lista == NULL)  // Se a lista estiver vazia
    return "Erro";  // Retorna um erro

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
  printf("nome %s removido no final.\n", n->nome);  // Informa o nome removido
  strcpy(*v,n->nome);  // Armazena o nome do nó removido
  free(n);  // Libera a memória do nó removido
  imprime_lista(*lista);  // Imprime a lista atualizada
  return *v;  // Retorna o nome removido
}

// Função principal
int main() {
  No *lista;  // Declaração de um ponteiro para a lista encadeada
  lista = NULL;  // Inicializa a lista como vazia (NULL)

  insere_final(&lista, "João");  // Insere o nome João no início da lista
  insere_final(&lista, "Teresa");  // Insere o nome Teresa no início da lista
  insere_final(&lista, "Raimundo");  // Insere o nome Raimundo no início da lista
  insere_final(&lista, "Maria"); // Insere o nome Maria no início da lista
  insere_final(&lista, "Joaquim"); //Insere o nome Joaquim no início da lista
  insere_final(&lista, "Lili");  // Insere o nome Lili no início da lista
  imprime_lista(lista);

  return 0;  // Retorna 0 para indicar que o programa terminou com sucesso
}
