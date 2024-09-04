/*
Construa um programa utilizando uma pilha que resolva o seguinte problema:
Armazene as placas dos carros (apenas os números) que estão estacionados numa rua sem saída estreita.
Dado uma placa verifique se o carro está estacionado na rua.
Caso esteja, informe a sequência de carros que deverá ser retirada para que o carro em questão consiga sair.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    int topo;
    int carros[MAX];
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int isEmpty(Pilha *p) {
    return p->topo == -1;
}

int isFull(Pilha *p) {
    return p->topo == MAX - 1;
}

void push(Pilha *p, int valor) {
    if (isFull(p)) {
        printf("Pilha cheia!\n");
    } else {
        p->carros[++(p->topo)] = valor;
    }
}

int pop(Pilha *p) {
    if (isEmpty(p)) {
        printf("Pilha vazia!\n");
        return -1;
    } else {
        return p->carros[(p->topo)--];
    }
}

int peek(Pilha *p) {
    if (isEmpty(p)) {
        printf("Pilha vazia!\n");
        return -1;
    } else {
        return p->carros[p->topo];
    }
}

bool carroNaRua(int placa, Pilha rua){
	int sequencia[100];
	int carro = pop(&rua);
    int cont = 0;
	if(carro==placa){
		printf("Nenhum carro precisará ser retirado para o carro de placa %i sair",placa);
		return true;
	}
    else{
        sequencia[cont] = carro;
            cont++;
    }
	while(!isEmpty(&rua)){
		carro = pop(&rua);
		if(carro!=placa){
			sequencia[cont] = carro;
            cont++;
		}else{
			printf("Sequência de carros a serem retirados:\n");
			for(int i = 0; i<cont; i++)
            {
                printf("%d ",sequencia[i]);
            }
			return true;
		}
	}
	return false;
}

int main(){
Pilha Carros;
inicializar(&Carros);
push(&Carros,1234);
push(&Carros,2341);
push(&Carros,3412);
push(&Carros,4123);
push(&Carros,4321);
push(&Carros,3214);
push(&Carros,2143);
push(&Carros,1432);
push(&Carros,1324);
push(&Carros,4231);
carroNaRua(1234,Carros);


}
