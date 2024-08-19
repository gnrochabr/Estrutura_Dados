#include <stdio.h>   // Biblioteca para funções de entrada e saída padrão
#include <stdlib.h>  // Biblioteca para funções de alocação e liberação de memória
#include <string.h>  // Biblioteca para manipulação de strings

// Estrutura para armazenar o endereço
struct tipo_end {
    char *rua;   // Ponteiro para uma string que representa o nome da rua
    int numero;  // Número da rua
};

// Função para copiar um endereço de uma estrutura para outra
void copiar_end(struct tipo_end *destino, const struct tipo_end *origem) {
    // Aloca memória para o campo rua em destino, com tamanho suficiente para armazenar a string
    destino->rua = (char *)malloc((strlen(origem->rua) + 1) * sizeof(char));
    if (destino->rua == NULL) {  // Verifica se a alocação de memória foi bem-sucedida
        fprintf(stderr, "Falha na alocação de memória\n"); // Exibe uma mensagem de erro se falhar
        exit(1);  // Encerra o programa com código de erro 1
    }
    // Copia o conteúdo da string rua de origem para destino
    strcpy(destino->rua, origem->rua);
    destino->numero = origem->numero;  // Copia o número da rua
}

int main() {
    struct tipo_end end1, end2;  // Declara duas variáveis do tipo tipo_end
    char buffer[50];  // Buffer para armazenar a entrada do usuário

    // Solicita ao usuário o nome da rua
    printf("\nEntre o nome da rua: ");
    fgets(buffer, sizeof(buffer), stdin);  // Lê uma linha da entrada padrão (stdin) para o buffer
    buffer[strcspn(buffer, "\n")] = '\0';  // Remove a nova linha no final da string, se presente

    // Aloca memória para end1.rua e copia o nome da rua do buffer para end1.rua
    end1.rua = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
    if (end1.rua == NULL) {  // Verifica se a alocação de memória foi bem-sucedida
        fprintf(stderr, "Falha na alocação de memória\n"); // Exibe uma mensagem de erro se falhar
        return 1;  // Encerra o programa com código de erro 1
    }
    strcpy(end1.rua, buffer);  // Copia o nome da rua para end1.rua

    // Solicita ao usuário o número da rua
    printf("\nEntre o número: ");
    scanf("%d", &end1.numero);  // Lê um número inteiro da entrada padrão e armazena em end1.numero

    // Copia os dados de end1 para end2 usando a função copiar_end
    copiar_end(&end2, &end1);

    // Exibe os dados dos endereços em end1 e end2
    printf("Dados 1:\n Endereço em end1: %s %d\n Endereço em end2: %s %d\n",
           end1.rua, end1.numero, end2.rua, end2.numero);

    // Modifica os dados em end2
    free(end2.rua);  // Libera a memória antiga que end2.rua apontava
    end2.rua = (char *)malloc((strlen("Rua Mesquita") + 1) * sizeof(char));  // Aloca nova memória para end2.rua
    if (end2.rua == NULL) {  // Verifica se a alocação de memória foi bem-sucedida
        fprintf(stderr, "Falha na alocação de memória\n"); // Exibe uma mensagem de erro se falhar
        free(end1.rua);  // Libera a memória alocada para end1.rua antes de encerrar
        return 1;  // Encerra o programa com código de erro 1
    }
    strcpy(end2.rua, "Rua Mesquita");  // Copia a nova string "Rua Mesquita" para end2.rua
    end2.numero = 1100;  // Atualiza o número da rua em end2

    // Exibe os dados atualizados dos endereços em end1 e end2
    printf("\n\nDados 2:\n Endereço em end1: %s %d\n Endereço em end2: %s %d\n",
           end1.rua, end1.numero, end2.rua, end2.numero);

    // Libera a memória alocada para end1.rua e end2.rua
    free(end1.rua);  
    free(end2.rua);

    return 0;  // Encerra o programa com sucesso
}
