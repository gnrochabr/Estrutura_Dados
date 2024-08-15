#include<stdio.h>
int main()
{
    //Escreva um programa em C que declare um ponteiro para um inteiro, atribua um valor a esse inteiro e, em seguida, imprima o valor do inteiro utilizando o ponteiro.
    int num = 10;
    int *p = &num;
    printf("Exercicio 1: %d",*p);

    //Desenvolva um programa em C que use um ponteiro para alterar o valor de uma variável inteira.
    *p = 90;
    printf("\nExercicio 2: %d",*p);
    //Crie um programa em C que leia um número inteiro e armazene-o em uma variável. Use um ponteiro para imprimir o valor armazenado.
    int numero;
    printf("\nDigite um numero inteiro: ");
    scanf("%d",&numero);
    int *pnt = &numero;
    printf("Exercicio 3: %d",*pnt);

    return 0;
}


