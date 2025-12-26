#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 Estrutura que representa uma sala da mansão.

*/
typedef struct Sala {
    char nome[50];
    struct Sala* esquerda;
    struct Sala* direita;
} Sala;

/*
 Cria dinamicamente uma nova sala.
*/
Sala* criarSala(const char* nome) {
    Sala* nova = (Sala*) malloc(sizeof(Sala));

    if (nova == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;

    return nova;
}

/*
 Função explorarSalas
 Permite ao jogador navegar pela mansão a partir
 do Hall de Entrada, escolhendo esquerda ou direita.
*/
void explorarSalas(Sala* atual) {
    char escolha;

    while (atual != NULL) {
        printf("\nVocê está na sala: %s\n", atual->nome);

        
        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("Esta sala não possui mais caminhos.\n");
            printf("Fim da exploração.\n");
            return;
        }

        printf("Escolha um caminho:\n");
        if (atual->esquerda != NULL)
            printf("e - Ir para a esquerda\n");
        if (atual->direita != NULL)
            printf("d - Ir para a direita\n");

        printf("s - Sair do jogo\n");
        printf("Opção: ");
        scanf(" %c", &escolha);

        if (escolha == 'e' && atual->esquerda != NULL) {
            atual = atual->esquerda;
        } 
        else if (escolha == 'd' && atual->direita != NULL) {
            atual = atual->direita;
        } 
        else if (escolha == 's') {
            printf("Você decidiu sair da exploração.\n");
            return;
        } 
        else {
            printf("Opção inválida. Tente novamente.\n");
        }
    }
}

/*

 Libera toda a memória alocada da árvore binária.
*/
void liberarMemoria(Sala* raiz) {
    if (raiz != NULL) {
        liberarMemoria(raiz->esquerda);
        liberarMemoria(raiz->direita);
        free(raiz);
    }
}

/*
 Monta manualmente o mapa da mansão
 e inicia a exploração.
*/
int main() {
    // Criação do mapa da mansão
    Sala* hall = criarSala("Hall de Entrada");
    Sala* salaEstar = criarSala("Sala de Estar");
    Sala* biblioteca = criarSala("Biblioteca");
    Sala* cozinha = criarSala("Cozinha");
    Sala* jardim = criarSala("Jardim");

    // Ligação das salas (árvore binária)
    hall->esquerda = salaEstar;
    hall->direita = biblioteca;

    salaEstar->esquerda = cozinha;
    salaEstar->direita = jardim;

    // Início do jogo
    printf("=== Detective Quest ===\n");
    explorarSalas(hall);

    // Liberação de memória
    liberarMemoria(hall);

    return 0;
}
