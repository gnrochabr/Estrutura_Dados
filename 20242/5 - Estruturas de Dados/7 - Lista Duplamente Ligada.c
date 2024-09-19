#include <stdlib.h>
#include <stdio.h>

// Lista duplamente ligada
typedef struct no{
    int dado;
    struct no *anterior;
    struct no *proximo;
} No;

No* criaNo(int valor){
    No *novono = (No*)malloc(sizeof(No));
    if(novono == NULL){
        printf("Falha na memória");
        exit(1);
    }
    novono->dado = valor;
    novono->anterior = NULL;
    novono -> proximo = NULL;
    return novono;
}

No* InsereListaDupla(No* lista, int valor){
    No* no = criaNo(valor);
    if(lista == NULL){
        return no;
    }
    else{
        No* atual = lista;
        //Percorre até encontrar o último elemento da lista
        while(atual->proximo!=NULL){
            atual = atual->proximo;
        }

        //O último elemento passa a ter o novo nó criado como próximo
        atual->proximo = no;
        //O novo nó criado passa a ter o nó que era último como anterior
        no->anterior = atual;
    }
    return lista;
}

No* buscaNo(No* no, int valor){
    while(no->dado != valor && no!=NULL){
        no = no->proximo;
    }
    if(no==NULL){
        return NULL;
    }else{
        return no;
    }
}

No* excluir(No* lista, int valor){
    No* alvo = buscaNo(lista,valor);
    if(alvo==NULL){
        printf("Valor não encontrado");
        return lista;
    }
    if(alvo->anterior==NULL){
        lista = alvo->proximo;
            if(lista==NULL){
                lista->anterior = NULL;
            }
    }
    else{
        alvo->anterior->proximo = alvo->proximo;
        if(alvo->proximo != NULL){
            alvo->proximo->anterior = alvo->anterior;
        }
    }
    printf("Valor %d excluído da lista",alvo->dado);
    free(alvo);
    return lista;
}

void imprimeLista(No* no){
    printf("\nLista ordenada - crescente: ");
    if(no == NULL){
        printf("Não foi encontrado nó");
    }
    while(no!=NULL){
        printf("%d ",(no->dado));
        no = no->proximo;
    }
    
}

void imprimeListaReversa(No* no){
    printf("\nLista ordenada - Decrescente: ");
    No* ultimo;
    while(no!=NULL){
        ultimo = no;
        no = no->proximo;
    }
    while(ultimo!=NULL){
        printf("%d ",(ultimo->dado));
        ultimo = ultimo->anterior;
    }
}
int main(){
    No* no = NULL;
    no = InsereListaDupla(no,4);
    no = InsereListaDupla(no,5);
    no = InsereListaDupla(no,6);
    no = InsereListaDupla(no,7);
    no = InsereListaDupla(no,8);
    no = InsereListaDupla(no,9);
    no = excluir(no,10);
    imprimeLista(no);
    
}
