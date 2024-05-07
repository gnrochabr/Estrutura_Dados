#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da árvore AVL
// São utilizados três parâmetros: dado, esquerda e direita, além da altura para balanceamento
struct NoAVL
{
    int dado;
    struct NoAVL *esquerda;
    struct NoAVL *direita;
    int altura;
};

// Função para criar um novo nó na árvore
// Recebe um valor inteiro como parâmetro e retorna um ponteiro para o novo nó
struct NoAVL *criarNo(int dado)
{
    // Aloca memória para um novo nó da árvore AVL
    struct NoAVL *novoNo = (struct NoAVL *)malloc(sizeof(struct NoAVL));
    // Verifica se a alocação de memória foi bem-sucedida
    if (novoNo == NULL)
    {
        // Imprime uma mensagem de erro e encerra o programa caso a alocação falhe
        printf("Erro: Falha ao alocar memória para o novo nó.\n");
        exit(-1);
    }
    novoNo->dado = dado;     // Armazena o valor fornecido dentro do nó
    novoNo->esquerda = NULL; // Inicializa o ponteiro para o filho esquerdo como nulo
    novoNo->direita = NULL;  // Inicializa o ponteiro para o filho direito como nulo
    novoNo->altura = 1;      // Inicializa a altura do nó como 1
    return novoNo;           // Retorna o ponteiro para o novo nó criado
}

// Função para calcular a altura de um nó
// Recebe um ponteiro para o nó como parâmetro e retorna um inteiro representando a altura do nó
int altura(struct NoAVL *no)
{
    // Verifica se o nó é nulo
    if (no == NULL)
        return 0;      // Se for nulo, retorna 0
    return no->altura; // Retorna a altura armazenada no nó
}

// Função para calcular o fator de balanceamento de um nó
// Recebe um ponteiro para o nó como parâmetro e retorna um inteiro representando o fator de balanceamento
int fatorBalanceamento(struct NoAVL *no)
{
    // Verifica se o nó é nulo
    if (no == NULL)
        return 0; // Se for nulo, retorna 0
    // Calcula o fator de balanceamento subtraindo a altura da subárvore direita pela altura da subárvore esquerda
    return altura(no->esquerda) - altura(no->direita);
}
// Caso esteja desbalanceado e precise rotacionar à direita em torno do nó
struct NoAVL *rotacaoDireita(struct NoAVL *no)
{
    struct NoAVL *novaRaiz = no->esquerda;       // Define a nova raiz como o nó à esquerda
    struct NoAVL *subArvore = novaRaiz->direita; // Define a subárvore como a subárvore direita da nova raiz

    // Realiza a rotação
    novaRaiz->direita = no;   // Define o nó como filho direito da nova raiz
    no->esquerda = subArvore; // Define a subárvore direita da nova raiz como filho esquerdo do nó

    // Atualiza as alturas
    if (altura(no->esquerda) > altura(no->direita)) // Verifica a altura da subárvore esquerda
        no->altura = 1 + altura(no->esquerda);      // Atualiza a altura do nó
    else
        no->altura = 1 + altura(no->direita); // Atualiza a altura do nó

    if (altura(novaRaiz->esquerda) > altura(novaRaiz->direita)) // Verifica a altura da subárvore esquerda da nova raiz
        novaRaiz->altura = 1 + altura(novaRaiz->esquerda);      // Atualiza a altura da nova raiz
    else
        novaRaiz->altura = 1 + altura(novaRaiz->direita); // Atualiza a altura da nova raiz

    return novaRaiz; // Retorna a nova raiz após a rotação
}

// Caso esteja desbalanceado e precise rotacionar à direita em torno de nó
struct NoAVL *rotacaoEsquerda(struct NoAVL *no)
{
    struct NoAVL *novaRaiz = no->direita;         // Define a nova raiz como o nó à direita
    struct NoAVL *subArvore = novaRaiz->esquerda; // Define a subárvore como a subárvore esquerda da nova raiz

    // Realiza a rotação
    novaRaiz->esquerda = no; // Define o nó como filho esquerdo da nova raiz
    no->direita = subArvore; // Define a subárvore esquerda da nova raiz como filho direito do nó

    // Atualiza as alturas
    if (altura(no->esquerda) > altura(no->direita)) // Verifica a altura da subárvore esquerda
        no->altura = 1 + altura(no->esquerda);      // Atualiza a altura do nó
    else
        no->altura = 1 + altura(no->direita); // Atualiza a altura do nó

    if (altura(novaRaiz->esquerda) > altura(novaRaiz->direita)) // Verifica a altura da subárvore esquerda da nova raiz
        novaRaiz->altura = 1 + altura(novaRaiz->esquerda);      // Atualiza a altura da nova raiz
    else
        novaRaiz->altura = 1 + altura(novaRaiz->direita); // Atualiza a altura da nova raiz

    return novaRaiz; // Retorna a nova raiz após a rotação
}

// Função que vai realizar o balanceamento da árvore
// Utiliza as funções anteriores para analisar cada caso
struct NoAVL *balanceamento(struct NoAVL *raiz, int dado)
{
    // Atualiza a altura do nó atual
    if (raiz == NULL) // Se a raiz for nula, retorna a raiz
    {
        return raiz;
    }
    if (altura(raiz->esquerda) > altura(raiz->direita)) // Verifica a altura da subárvore esquerda
    {
        raiz->altura = 1 + altura(raiz->esquerda); // Atualiza a altura da raiz
    }
    else
    {
        raiz->altura = 1 + altura(raiz->direita); // Atualiza a altura da raiz
    }

    // Calcula o fator de balanceamento deste nó para verificar se ele se tornou desbalanceado
    int balanceamento = fatorBalanceamento(raiz); // Calcula o fator de balanceamento da raiz

    // Caso de desbalanceamento à esquerda-esquerda
    if (balanceamento > 1 && dado < raiz->esquerda->dado) // Se o fator de balanceamento for maior que 1 e o dado for menor que o dado da subárvore esquerda
        return rotacaoDireita(raiz);                      // Realiza rotação à direita

    // Caso de desbalanceamento à direita-direita
    if (balanceamento < -1 && dado > raiz->direita->dado) // Se o fator de balanceamento for menor que -1 e o dado for maior que o dado da subárvore direita
        return rotacaoEsquerda(raiz);                     // Realiza rotação à esquerda

    // Caso de desbalanceamento à esquerda-direita
    if (balanceamento > 1 && dado > raiz->esquerda->dado) // Se o fator de balanceamento for maior que 1 e o dado for maior que o dado da subárvore esquerda
    {
        raiz->esquerda = rotacaoEsquerda(raiz->esquerda); // Realiza rotação à esquerda na subárvore esquerda da raiz
        return rotacaoDireita(raiz);                      // Realiza rotação à direita na raiz
    }

    // Caso de desbalanceamento à direita-esquerda
    if (balanceamento < -1 && dado < raiz->direita->dado) // Se o fator de balanceamento for menor que -1 e o dado for menor que o dado da subárvore direita
    {
        raiz->direita = rotacaoDireita(raiz->direita); // Realiza rotação à direita na subárvore direita da raiz
        return rotacaoEsquerda(raiz);                  // Realiza rotação à esquerda na raiz
    }

    // Retorna a raiz inalterada
    return raiz; // Retorna a raiz após o balanceamento
}

// Função para inserir um novo nó na árvore AVL
struct NoAVL *inserir(struct NoAVL *raiz, int dado)
{
    // Verifica se a raiz é nula, indicando que estamos em uma folha da árvore ou que a árvore está vazia
    if (raiz == NULL)
    {
        // Se a raiz for nula, cria um novo nó com o dado fornecido e o retorna como a nova raiz da árvore
        return criarNo(dado);
    }

    // Se o dado a ser inserido for menor que o valor da raiz atual, insere recursivamente na subárvore esquerda
    if (dado < raiz->dado)
    {
        raiz->esquerda = inserir(raiz->esquerda, dado);
    }
    // Se o dado for maior que o valor da raiz atual, insere recursivamente na subárvore direita
    else if (dado > raiz->dado)
    {
        raiz->direita = inserir(raiz->direita, dado);
    }
    else
    {
        // Se o dado for igual ao valor da raiz atual, não faz nada (dados iguais não são permitidos na árvore AVL)
        return raiz;
    }

    // Após a inserção, chama a função de balanceamento para garantir que a árvore permaneça balanceada
    return balanceamento(raiz, dado);
}

// Encontra o menor valor na árvore AVL
struct NoAVL *encontrarMinimo(struct NoAVL *no)
{
    struct NoAVL *atual = no;

    // Percorre a subárvore esquerda até encontrar o nó mais à esquerda
    while (atual && atual->esquerda != NULL)
        atual = atual->esquerda;

    return atual;
}

struct NoAVL* encontrarMaximo(struct NoAVL* no) {
    // Verifica se o nó fornecido é válido
    if (no == NULL)
        return NULL;

    // Percorre a subárvore à esquerda até encontrar o nó mais à direita
    while (no->direita != NULL) {
        no = no->direita;
    }

    // Retorna o nó mais à direita da subárvore esquerda
    return no;
}


// Função para excluir um nó na árvore AVL
struct NoAVL *excluir(struct NoAVL *raiz, int valor) {
    if (raiz == NULL) // Verifica se o nó a ser excluído existe ou é nulo
    {
        return raiz;
    }

    if (valor < raiz->dado) // Verifica se o dado está à esquerda
    {
        raiz->esquerda = excluir(raiz->esquerda, valor); // Chama a função recursivamente até encontrar o nó a ser excluído
    }
    else if (valor > raiz->dado) // Verifica se o dado está à direita
    {
        raiz->direita = excluir(raiz->direita, valor); // Chama a função recursivamente até encontrar o nó a ser excluído
    }
    else // Se o nó atual for igual ao valor a ser excluído
    {
        // Caso 1: Nó folha ou nó com apenas um filho
        if (raiz->esquerda == NULL) // Se tiver apenas filhos à direita
        {
            struct NoAVL *temp = raiz->direita; // Define qual nó filho irá substituir o pai, nesse caso, o nó à direita.
            free(raiz);                         // Libera o valor do nó da memória
            return temp;                        // Retorna o nó que irá substituir o nó pai
        }
        else if (raiz->direita == NULL) // Se tiver apenas filhos à esquerda
        {
            struct NoAVL *temp = raiz->esquerda; // Define qual nó filho irá substituir o pai, nesse caso, o nó à esquerda.
            free(raiz);                         // Libera o valor do nó da memória
            return temp;                        // Retorna o nó que irá substituir o nó pai
        }

        // Caso 2: Nó com dois filhos
        // Verifica o balanceamento antes de decidir entre o valor maior à direita da subárvore esquerda ou o menor valor à esquerda da subárvore direita
        if (altura(raiz->esquerda) >= altura(raiz->direita)) {
            // Se a altura da subárvore esquerda for maior, escolhe o maior valor à direita da subárvore esquerda
            struct NoAVL *temp = encontrarMaximo(raiz->esquerda); // Encontra o maior valor na subárvore esquerda
            raiz->dado = temp->dado;                              // Copia o valor do sucessor in-order (maior valor na subárvore esquerda) para a raiz atual
            raiz->esquerda = excluir(raiz->esquerda, temp->dado); // Remove o nó com o valor copiado da subárvore esquerda
        } else {
            // Caso contrário, escolhe o menor valor à esquerda da subárvore direita
            struct NoAVL *temp = encontrarMinimo(raiz->direita); // Encontra o menor valor na subárvore direita
            raiz->dado = temp->dado;                              // Copia o valor do sucessor in-order (menor valor na subárvore direita) para a raiz atual
            raiz->direita = excluir(raiz->direita, temp->dado);   // Remove o nó com o valor copiado da subárvore direita
        }
    }

    // Após a exclusão, chama a função de balanceamento para garantir que a árvore permaneça balanceada
    return balanceamento(raiz, valor);
}


// Função para percorrer a árvore em ordem
void percorrerEmOrdem(struct NoAVL *raiz)
{
    if (raiz != NULL) // Verifica se o nó atual não é nulo
    {
        percorrerEmOrdem(raiz->esquerda); // Percorre a subárvore esquerda
        printf("%d ", raiz->dado);        // Imprime o valor do nó atual
        percorrerEmOrdem(raiz->direita);  // Percorre a subárvore direita
    }
}

// Função para percorrer a árvore em pré-ordem
void percorrerPreOrdem(struct NoAVL *raiz)
{
    if (raiz != NULL) // Verifica se o nó atual não é nulo
    {
        printf("%d ", raiz->dado);        // Imprime o valor do nó atual
        percorrerEmOrdem(raiz->esquerda); // Percorre a subárvore esquerda
        percorrerEmOrdem(raiz->direita);  // Percorre a subárvore direita
    }
}

// Função para percorrer a árvore em pós-ordem
void percorrerPosOrdem(struct NoAVL *raiz)
{
    if (raiz != NULL) // Verifica se o nó atual não é nulo
    {
        percorrerEmOrdem(raiz->esquerda); // Percorre a subárvore esquerda
        percorrerEmOrdem(raiz->direita);  // Percorre a subárvore direita
        printf("%d ", raiz->dado);        // Imprime o valor do nó atual
    }
}

// Função auxiliar para imprimir um caractere precedido por uma quantidade específica de espaços
void imprimeNo(int c, int b)
{
    int i;
    for (i = 0; i < b; i++) // Loop para imprimir espaços proporcionais à profundidade
        printf("   ");
    printf("%i\n", c); // Imprime o valor do nó com a devida indentação
}

// Função para exibir a árvore no formato esquerda-raiz-direita segundo Sedgewick
void mostraArvore(struct NoAVL *a, int b)
{
    if (a != NULL) // Verifica se o nó atual não é nulo
    {
        // Chama a função recursivamente para percorrer a subárvore direita
        mostraArvore(a->direita, b + 1);
        // Imprime o nó atual com um espaçamento proporcional à sua profundidade
        imprimeNo(a->dado, b);
        // Chama a função recursivamente para percorrer a subárvore esquerda
        mostraArvore(a->esquerda, b + 1);
    }
}
/*
3 - Escreva uma função para calcular a altura de uma árvore AVL.
Peça ao usuário para inserir elementos em uma árvore AVL e, em seguida,
exiba a altura da árvore resultante.*/
// Função para calcular a altura de uma árvore AVL
int alturaTree(struct NoAVL *no)
{
    if (no == NULL)
    { // Se o nó for nulo, a altura é 0
        return 0;
    }

    // Calcula a altura da subárvore esquerda e direita
    int altura_esquerda = alturaTree(no->esquerda) + 1;
    int altura_direita = alturaTree(no->direita) + 1;

    // Retorna a maior altura entre a subárvore esquerda e direita, somada à altura do nó atual
    if (1 + ((altura_esquerda > altura_direita)))
    {
        return altura_esquerda;
    }
    else
    {
        return altura_direita;
    }
}

/*4 - Escreva uma função para verificar se uma árvore é uma árvore AVL válida,
ou seja, se ela satisfaz todas as propriedades de uma árvore AVL.
 Teste sua função em diferentes árvores AVL, incluindo árvores corretas
 e incorretas, e verifique se a função retorna os resultados esperados.
*/
int main()
{
    struct NoAVL *raiz = NULL;

    // Inserindo elementos na árvore AVL
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 24);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 35);
    raiz = inserir(raiz, 27);
    raiz = inserir(raiz, 33);
    raiz = inserir(raiz, 38);
    raiz = inserir(raiz, 25);
    raiz = inserir(raiz, 22);
    raiz = inserir(raiz, 34);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 29);
    mostraArvore(raiz, 3);
   
    printf("\nLetra A - Insere 31 ---------------------------\n");
    raiz = inserir(raiz, 31);
    mostraArvore(raiz, 3);
   
    printf("\nLetra B - Insere 15 ---------------------------\n");
    raiz = inserir(raiz, 15);
    mostraArvore(raiz, 3);
   
    printf("\nLetra C - Insere 23 ----------------------------\n");
    raiz = inserir(raiz, 23);
    mostraArvore(raiz, 3);
   
    printf("\nLetra D - Exclui 24 ---------------------------\n");
    raiz = excluir(raiz, 24);
    mostraArvore(raiz, 3);
   
    printf("\nLetra E - Exclui 35 ---------------------------\n");
    raiz = excluir(raiz, 35);
    mostraArvore(raiz, 3);

     printf("\nLetra F - Inserir 24 ---------------------------\n");
    raiz = inserir(raiz, 24);
    mostraArvore(raiz, 3);

     printf("\nLetra G - Exclui 27 ---------------------------\n");
    raiz = excluir(raiz, 27);
    mostraArvore(raiz, 3);

     printf("\nLetra H - Inserir 32 ---------------------------\n");
    raiz = inserir(raiz, 32);
    mostraArvore(raiz, 3);

     printf("\nLetra I - Exclui 30 ---------------------------\n");
    raiz = excluir(raiz, 30);
    mostraArvore(raiz, 3);
    
    printf("\nLetra J - Inserir 21 ---------------------------\n");
    raiz = inserir(raiz, 21);
    mostraArvore(raiz, 3);



    return 0;
}
