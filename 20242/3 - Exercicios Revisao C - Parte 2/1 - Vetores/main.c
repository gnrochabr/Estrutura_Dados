#include<stdio.h>
/* Atividade 1
int main(){
    int vetor[10]={4,3,2,6,7,8,9,1,0,5};
    int menor = vetor[0];
    int maior = vetor[0];

    for(int i = 1; i<10;i++){
        if(vetor[i]>maior){
            maior = vetor[i];
        }
         if(vetor[i]<menor){
            menor = vetor[i];
        }
    }
    printf("Maior numero: %d, Menor numero: %d ", maior, menor);
return 0;
}

int main(){
    float notas[5] = {9, 8.5, 10, 8, 7.5};
    float media, soma = 0;
    for(int i = 0; i<5; i++){
        soma+=notas[i];
    }
    media = soma/5;
    printf("A media de notas foi: %.2f", media);
}*/

int main(){
    int vetor[20] = {9,6,3,2,1,4,5,7,8,11,13,15,17,19,20,12,10,14,16,18};
    for(int i = 0; i<20; i++){
        if(vetor[i]%2==0){
            printf("%d ",vetor[i]);
        }
    }
return 0;
}
