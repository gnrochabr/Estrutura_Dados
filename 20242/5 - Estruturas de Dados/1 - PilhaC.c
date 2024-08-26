#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 10

// Definição da estrutura da pilha
typedef struct {
    int topo;
    int itens[TAM_MAX];
} Pilha;

// Função para inicializar a pilha
void stack(Pilha *p) {
    p->topo = -1;
}

// Função para verificar se a pilha está cheia
int isFull(Pilha *p) {
    return (p->topo == TAM_MAX - 1);
}

// Função para verificar se a pilha está vazia
int isEmpty(Pilha *p) {
    return (p->topo == -1);
}

// Função para empilhar um elemento
void push(Pilha *p, int valor) {
    if (isFull(p)) {
        printf("Erro: A pilha está cheia!\n\n");
    } else {
        p->itens[++(p->topo)] = valor;
    }
}

// Função para desempilhar um elemento
int pop(Pilha *p) {
    if (isEmpty(p)) {
        printf("Erro: A pilha está vazia!\n\n");
        return -1; // Retorna -1 para indicar erro
    } else {
        return p->itens[(p->topo)--];
    }
}

// Função para visualizar o elemento no topo da pilha
int peek(Pilha *p) {
    if (isEmpty(p)) {
        printf("A pilha está vazia.\n\n");
        return -1;
    } else {
        return p->itens[p->topo];
    }
}

// Função para imprimir a pilha atual
void printStack(Pilha *p){
  if(!isEmpty(p)){  
    printf("[");
    for(int i = 0; i<p->topo;i++){
        printf("%d, ",p->itens[i]);
    }
    printf("%d]\n",peek(p));}
}

// Função principal para testar a pilha
int main() {
    Pilha p; //Cria uma nova pilha
    stack(&p); //Inicializa a pilha com topo -1;

    //Basta usar as funções push, pop e printStack para se divertir
    return 0;
}
