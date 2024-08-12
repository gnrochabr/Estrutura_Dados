#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// prototipos de função
void imprimirVetor(int vetor[], int tam); //imprime o vetor 
int somaVetor(int vetor[], int tam); //soma numeros do vetor
int paresVetor(int vetor[], int tam); //conta os pares do vetor

int main()
{
    int valores[5] = {16,8,7,4,2};
    //(sizeof(valores)/sizeof(int)) -> Tamanho do vetor
    imprimirVetor(valores,(sizeof(valores)/sizeof(int)));
    printf("\nSoma: %d",somaVetor(valores,(sizeof(valores)/sizeof(int))));
    printf("\nPares: %d",paresVetor(valores,(sizeof(valores)/sizeof(int))));
    return 0;
}

void imprimirVetor(int vetor[], int tam){
    for(int i = 0;i<tam; i++){
        printf("%d ",vetor[i]);
    }
} //Não tem retorno, apenas imprime 

int somaVetor(int vetor[], int tam){
    int soma = 0;
     for(int i = 0;i<tam; i++){
        soma+=vetor[i];
    }
    return soma;
} //retorna soma numeros inteiros do vetor

int paresVetor(int vetor[], int tam){
 int pares = 0;
 for(int i = 0;i<tam; i++){
        if(vetor[i]%2==0)
        pares++;
    }
return pares; 
}//retorna a quantidade de pares