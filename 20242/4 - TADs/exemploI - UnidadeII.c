#include<stdio.h>
#include<string.h>

struct tipo_endereco
{
    char rua [50];
    int numero;
    char bairro [20];
    char cidade [30];
    char sigla_estado [3];
    long int CEP;
};

struct ficha_pessoal
{
    char nome [50];
    long int telefone;
    struct tipo_endereco endereco;
};

void imprimirDados(struct ficha_pessoal ficha);

int main ()
{
    struct ficha_pessoal ficha;
    strcpy(ficha.nome,"Luiz Osvaldo Silva");

    ficha.telefone=2799921234;

    strcpy(ficha.endereco.rua,"Rua Júpiter");
    ficha.endereco.numero=610;
    strcpy(ficha.endereco.bairro,"Bela Vista II");
    strcpy(ficha.endereco.cidade,"Vila Velha");
    strcpy(ficha.endereco.sigla_estado,"ES");
    ficha.endereco.CEP= 29102612;
    imprimirDados(ficha);
    return 0;
}

void imprimirDados(struct ficha_pessoal ficha)
{
    printf("%s \n",ficha.nome);
    printf("%ld \n",ficha.telefone);
    printf("%s \n",ficha.endereco.rua);
    printf("%d \n",ficha.endereco.numero);
    printf("%s \n",ficha.endereco.bairro);
    printf("%s \n",ficha.endereco.cidade);
    printf("%s \n",ficha.endereco.sigla_estado);
    printf("%ld \n",ficha.endereco.CEP);

}
