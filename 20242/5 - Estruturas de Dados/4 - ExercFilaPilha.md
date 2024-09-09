## CORREÇÃO DOS EXERCÍCIOS - 04/09 ##
### 1. Operações com Pilhas (P1 e P2)

#### a) Testar Igualdade
A função vai comparar as pilhas P1 e P2, verificando se têm os mesmos elementos e tamanhos.

```c
int testarIgualdade(Pilha *p1, Pilha *p2) {
    if (p1->topo != p2->topo) {
        return 0;  // Pilhas têm tamanhos diferentes
    }
    for (int i = 0; i <= p1->topo; i++) {
        if (p1->itens[i] != p2->itens[i]) {
            return 0;  // Elementos diferentes
        }
    }
    return 1;  // Pilhas são iguais
}
```

#### b) Estatísticas (maior, menor, média)
Essa função retorna o maior, menor e a média dos elementos de uma pilha.

```c
void estatisticas(Pilha *p, int *maior, int *menor, float *media) {
    int soma = 0;
    *maior = *menor = p->itens[0];
    for (int i = 0; i <= p->topo; i++) {
        if (p->itens[i] > *maior) {
            *maior = p->itens[i];
        }
        if (p->itens[i] < *menor) {
            *menor = p->itens[i];
        }
        soma += p->itens[i];
    }
    *media = (float)soma / (p->topo + 1);
}
```

#### c) Transferir elementos de P1 para P2 (Cópia)

```c
void transferirPilha(Pilha *p1, Pilha *p2) {
    for (int i = 0; i <= p1->topo; i++) {
        push(p2, p1->itens[i]);
    }
}
```

#### d) Contar Ímpares

```c
int contarImpares(Pilha *p) {
    int count = 0;
    for (int i = 0; i <= p->topo; i++) {
        if (p->itens[i] % 2 != 0) {
            count++;
        }
    }
    return count;
}
```

#### e) Contar Pares

```c
int contarPares(Pilha *p) {
    int count = 0;
    for (int i = 0; i <= p->topo; i++) {
        if (p->itens[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}
```

### 2. Operações com Filas (F1 e F2)

#### a) Testar Igualdade

```c
int testarIgualdadeFila(struct Fila *f1, struct Fila *f2) {
    if (f1->nItens != f2->nItens) {
        return 0;  // Filas têm tamanhos diferentes
    }
    for (int i = 0; i < f1->nItens; i++) {
        if (f1->dados[(f1->primeiro + i) % f1->capacidade] != f2->dados[(f2->primeiro + i) % f2->capacidade]) {
            return 0;  // Elementos diferentes
        }
    }
    return 1;  // Filas são iguais
}
```

#### b) Estatísticas (maior, menor, média)

```c
void estatisticasFila(struct Fila *f, int *maior, int *menor, float *media) {
    int soma = 0;
    *maior = *menor = f->dados[f->primeiro];
    for (int i = 0; i < f->nItens; i++) {
        int valor = f->dados[(f->primeiro + i) % f->capacidade];
        if (valor > *maior) {
            *maior = valor;
        }
        if (valor < *menor) {
            *menor = valor;
        }
        soma += valor;
    }
    *media = (float)soma / f->nItens;
}
```

#### c) Transferir elementos de F1 para F2 (Cópia)

```c
void transferirFila(struct Fila *f1, struct Fila *f2) {
    for (int i = 0; i < f1->nItens; i++) {
        int valor = f1->dados[(f1->primeiro + i) % f1->capacidade];
        inserir(f2, valor);
    }
}
```

#### d) Contar Ímpares

```c
int contarImparesFila(struct Fila *f) {
    int count = 0;
    for (int i = 0; i < f->nItens; i++) {
        if (f->dados[(f->primeiro + i) % f->capacidade] % 2 != 0) {
            count++;
        }
    }
    return count;
}
```

#### e) Contar Pares

```c
int contarParesFila(struct Fila *f) {
    int count = 0;
    for (int i = 0; i < f->nItens; i++) {
        if (f->dados[(f->primeiro + i) % f->capacidade] % 2 == 0) {
            count++;
        }
    }
    return count;
}
```

Essas funções fornecem a lógica necessária para operar com pilhas e filas nas condições especificadas.
