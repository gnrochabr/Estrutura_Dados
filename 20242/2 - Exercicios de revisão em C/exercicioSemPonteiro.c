#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void contaPares(int numero[10]);
void contaPrimos(int numero[10]);
int main()
{
    int numero[10]; //inicializa o vetor de inteiros
    
    for(int i = 0; i<10; i++){
        numero[i] = 3*i; //Insere os multiplos de 3 no vetor (exemplo)
        printf("%i ",numero[i]); //imprime para conferir os números
    }
    contaPares(numero);
    contaPrimos(numero);
    return 0;
}

void contaPares(int numero[10]){
    int cont = 0; // Inicia o contador de pares
    for(int j = 0; j<10;j++){ //verifico o vetor
        if(numero[j]%2==0){ //Verifica se o elemento é par
            cont++; //Se for par, soma mais um ao contador
        }
    }
    printf("\nO vetor possui %d numeros pares!\n",cont);
}

void contaPrimos(int numero[10]){
    int cont = 0; //Inicializa o contador
    for(int i = 0; i<10;i++){ //percorre o vetor
        for(int j = 1;j<numero[i];j++){ //Divide o valor por todos os valores de 1 até ele
            if(numero[i]%j==0){
                cont++; //Aumenta +1 se for divisivel
            }
        }
        if(cont<=1){ //Se for primo imprime
            printf("%d ",numero[i]);
        }
        cont = 0; //Zera o contador para o próximo elemento do vetor
    }
    printf("são primos!");
}

//1 - 