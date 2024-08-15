#include <stdio.h>
void dobra(int *p);
void metade(float *p);
void troca(int *a, int *b);

int main(){
int a = 5;
int b = 20;
float c = 30.6;

int *pa = &a;
int *pb = &b;
float *pc = &c;

dobra(pa);
printf("Exercicio 1: %d\n",*pa);

metade(pc);
printf("Exercicio 2: %.2f\n",*pc);

printf("Exercicio 3 - A = %d e B = %d\n",a,b);
troca(pa,pb);
printf("Pós troca - A = %d e B = %d",a,b);


return 0;
}

//Escreva uma função em C que receba um ponteiro para um inteiro e atualize o valor desse inteiro para seu dobro. Em seguida, crie um programa que leia um valor inteiro, chame a função e imprima o valor atualizado.
void dobra(int *p){
    (*p)*=2;
}
//Desenvolva uma função em C que receba um ponteiro para um float e atualize o valor para a metade. Em seguida, crie um programa que leia um valor float, chame a função e imprima o valor atualizado.
void metade(float *p){
    *p = *p/2; 
}
//Crie uma função em C que receba dois ponteiros para inteiros e troque os valores apontados por esses ponteiros. Em seguida, crie um programa que leia dois valores inteiros, chame a função e imprima os valores após a troca.
void troca(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
