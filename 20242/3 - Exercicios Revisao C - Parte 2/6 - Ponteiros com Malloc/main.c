#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int exercicio1();
int exercicio2();
int exercicio3();

int main()
{
    exercicio3();
    return 0;
}

//Escreva um programa em C que use malloc para alocar memória para um vetor de 10 inteiros, leia os valores do usuário e imprima-os.
int exercicio1(){
    int tamanho = 10;
    int numero;
    int *vetor = (int *)malloc(tamanho*sizeof(int));
    for (int i = 0; i<tamanho; i++){
        printf("Digite o %do numero: ", i+1);
        scanf("%i",&numero);
        vetor[i]=numero;
    }
    for (int i = 0; i<tamanho; i++){
        printf("O %do numero - %d\n",i+1, vetor[i]);
    }
    free(vetor);
    return 0;
}

//Desenvolva um programa em C que use malloc para alocar memória para uma string de 50 caracteres, leia uma string do usuário e imprima-a.
int exercicio2(){
    int tamanho = 50;
    char *palavra = (char *)malloc(tamanho*sizeof(char));
    printf("Digite ai:");
    scanf("%s",palavra); //%[^\n] = frase || %s = palavra
    printf("VocÊ digitou: %s",palavra);
    free(palavra);
    return 0;
}

//Escreva um programa em C que use malloc para alocar memória para um vetor de estruturas que representam alunos (nome, idade, nota). Leia os dados de 3 alunos e imprima-os.
int exercicio3(){

typedef struct aluno
{
    char nome[20];
    int idade;
    float nota;
} Aluno;

int tamanho = 3;
Aluno *alunos = (Aluno *)malloc(tamanho*sizeof(Aluno));
for(int i=0; i<tamanho; i++){
    printf("\nDigite os dados do aluno %d\n",i+1);
    printf("Nome do aluno:");
    scanf(" %[^\n]",alunos[i].nome);
    printf("Idade do aluno:");
    scanf("%i",&alunos[i].idade);
    printf("Nota do aluno:");
    scanf("%f",&alunos[i].nota);
}
printf("\nLista de alunos:\n");
for(int i=0; i<tamanho; i++){
    printf("Nome:%s Idade:%i Nota:%.1f\n",alunos[i].nome,alunos[i].idade,alunos[i].nota);
}
return 0;
}