#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// prototipos de função
int soma(int a, int b); //soma numeros inteiros 
int funcaoSinal(int a); // descobre o sinal do numero
int primo(int a); // Descobre se ele é primo
int main()
{
    int soma_res = soma(4,5);
    int numero = funcaoSinal(-3);
    int primonum = primo(17);
    printf("Soma: %d\nSinal: %d\nPrimo: %d",soma_res,numero,primonum);
    return 0;
}

int soma(int a, int b){
    return a + b;
}
int funcaoSinal(int a){
if(a > 0){
    return 1;
}
if(a < 0){
    return -1;
}
else
{
    return 0;
}
}
int primo(int a){
int cnt_div = 0;
for(int i = 1; i < a; i++)
{
    if(a%i==0){
        cnt_div++;
    }
}
if(cnt_div<=1){
    printf("PRIMO!\n");
    return 1;
}
else
{
    printf("NÃO PRIMO!\n");
    return 0;
}
}
