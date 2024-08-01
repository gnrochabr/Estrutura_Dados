#include<stdio.h>
#include<string.h>

const int TAMANHO = 10;

//Definição da estrutura para o tipo aluno
typedef struct{
int matricula;
char nome[50];
char endereco[200];
char data_nasc[10];
} aluno;

//prototipos de funções
aluno inserirAlunos(aluno novoAluno, int matricula);
void PesquisaMatricula(aluno alunos[TAMANHO]);

int main()
{
    aluno alunos[TAMANHO]; //Vetor que vai armazenar meus alunos
    aluno novoAluno; //Instancia de um novo aluno
    int matricula = 1; //Cria a matricula inicial
    int tam; //Cria o indice para auxiliar na inserção de alunos
    int operador = -1; //Inicializa o operador do menu
    
    //Crie os testes de alunos - Total de 10 alunos genéricos
    for(tam = 0; tam < 10; tam++){
        //Cria um aluno e insere no vetor de alunos
        novoAluno.matricula = matricula;
        alunos[tam] = inserirAlunos(novoAluno,matricula);
        //Incrementa a matrícula
        matricula++;
        //Imprime o aluno inserido
        printf("%i - %s \n",alunos[tam].matricula,alunos[tam].nome);
    }

    while(operador!=0){
        printf("-- Sistema de Alunos --\n 1 - Pesquisa alunos pela matrícula\n 2 - Ordena os nomes dos alunos e exibe\n 3 - Excluir aluno\n 0 - Sair\n Escolha sua opcao:");
        scanf("%i",&operador);
        switch(operador){
            case 1: PesquisaMatricula(alunos); break;
            case 2: break;
            case 3: break;
            case 0: operador = 0; break;
            default: printf("Opção Inválida"); break;
        }

    }
    return 0;
}

aluno inserirAlunos(aluno novoAluno, int matricula){
    strcpy(novoAluno.nome,"Fulano");
    strcpy(novoAluno.data_nasc,"01-01-1900");
    strcpy(novoAluno.endereco,"Rua dos bobos, No. 0");
    return novoAluno;
}

void PesquisaMatricula(aluno alunos[TAMANHO]){
int matr; //Cria uma variavel local para matricula buscada
aluno encontrado; //Armazena o aluno encontrado
printf("Digite a matricula que busca: ");
scanf("%d",&matr);
//Percorre o vetor de alunos em busca do resultado compatível
for(int i = 0; i< TAMANHO; i++){
    //Se encontrar armazena temporariamente uma cópia
    if(alunos[i].matricula == matr){
        encontrado = alunos[i];
    }
}

//Se tem algum valor encontrado imprime o aluno 
if(encontrado.matricula!=NULL){
     printf("%i - %s",encontrado.matricula,encontrado.nome);}
 else{ //Imprime que não foi encontrado nenhum aluno
        printf("Aluno não encontrado");} 
}
