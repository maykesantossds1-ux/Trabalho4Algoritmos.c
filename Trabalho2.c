#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

/* ================= ESTRUTURAS ================= */

typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

typedef struct No {
    Item dados;
    struct No* proximo;
} No;

/* ================= VARIÁVEIS GLOBAIS ================= */

int comparacoesSequencial = 0;
int comparacoesBinaria = 0;

/* ================= VETOR ================= */

void inserirItemVetor(Item mochila[], int* total) {
    if (*total >= MAX) {
        printf("Mochila cheia!\n");
        return;
    }

    printf("Nome: ");
    scanf(" %29[^\n]", mochila[*total].nome);

    printf("Tipo: ");
    scanf(" %19[^\n]", mochila[*total].tipo);

    printf("Quantidade: ");
    scanf("%d", &mochila[*total].quantidade);

    (*total)++;
}

void listarVetor(Item mochila[], int total) {
    for (int i = 0; i < total; i++) {
        printf("%s - %s - %d\n",
               mochila[i].nome,
               mochila[i].tipo,
               mochila[i].quantidade);
    }
}

int buscarSequencialVetor(Item mochila[], int total, char nome[]) {
    comparacoesSequencial = 0;
    for (int i = 0; i < total; i++) {
        comparacoesSequencial++;
        if (strcmp(mochila[i].nome, nome) == 0)
            return i;
    }
    return -1;
}

void ordenarVetor(Item mochila[], int total) {
    Item temp;
    for (int i = 0; i < total - 1; i++) {
        for (int j = i + 1; j < total; j++) {
            if (strcmp(mochila[i].nome, mochila[j].nome) > 0) {
                temp = mochila[i];
                mochila[i] = mochila[j];
                mochila[j] = temp;
            }
        }
    }
}

int buscaBinaria(Item mochila[], int total, char nome[]) {
    int inicio = 0, fim = total - 1;
    comparacoesBinaria = 0;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        comparacoesBinaria++;

        int cmp = strcmp(mochila[meio].nome, nome);
        if (cmp == 0) return meio;
        if (cmp < 0) inicio = meio + 1;
        else fim = meio - 1;
    }
    return -1;
}

void removerVetor(Item mochila[], int* total, char nome[]) {
    int pos = buscarSequencialVetor(mochila, *total, nome);
    if (pos == -1) return;

    for (int i = pos; i < *total - 1; i++)
        mochila[i] = mochila[i + 1];

    (*total)--;
}

/* ================= LISTA ENCADEADA ================= */

void inserirLista(No** inicio) {
    No* novo = (No*)malloc(sizeof(No));

    printf("Nome: ");
    scanf(" %29[^\n]", novo->dados.nome);

    printf("Tipo: ");
    scanf(" %19[^\n]", novo->dados.tipo);

    printf("Quantidade: ");
    scanf("%d", &novo->dados.quantidade);

    novo->proximo = *inicio;
    *inicio = novo;
}

void listarLista(No* inicio) {
    while (inicio) {
        printf("%s - %s - %d\n",
               inicio->dados.nome,
               inicio->dados.tipo,
               inicio->dados.quantidade);
        inicio = inicio->proximo;
    }
}

No* buscarLista(No* inicio, char nome[]) {
    comparacoesSequencial = 0;
    while (inicio) {
        comparacoesSequencial++;
        if (strcmp(inicio->dados.nome, nome) == 0)
            return inicio;
        inicio = inicio->proximo;
    }
    return NULL;
}

void removerLista(No** inicio, char nome[]) {
    No *atual = *inicio, *anterior = NULL;

    while (atual && strcmp(atual->dados.nome, nome) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (!atual) return;

    if (!anterior)
        *inicio = atual->proximo;
    else
        anterior->proximo = atual->proximo;

    free(atual);
}

/* ================= MAIN ================= */

int main() {
    Item mochila[MAX];
    int total = 0;
    No* lista = NULL;
    int opcao;
    char nomeBusca[30];

    do {
        printf("\n1-Vetor  2-Lista  0-Sair\n");
        scanf("%d", &opcao);

        if (opcao == 1) {
            inserirItemVetor(mochila, &total);
            ordenarVetor(mochila, total);
            listarVetor(mochila, total);
        }
        else if (opcao == 2) {
            inserirLista(&lista);
            listarLista(lista);
        }
    } while (opcao != 0);

    return 0;
}
