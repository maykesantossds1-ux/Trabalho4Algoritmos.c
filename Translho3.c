#include <stdio.h>
#include <string.h>

#define MAX 10

/*
 Estrutura que representa uma ação do sistema
 (ex: comando, evento, histórico)
*/
typedef struct {
    char descricao[50];
} Acao;

/*
 Estrutura da Pilha
*/
typedef struct {
    Acao itens[MAX];
    int topo;
} Pilha;

/* ================= FUNÇÕES ================= */

void inicializarPilha(Pilha* p) {
    p->topo = -1;
}

int pilhaCheia(Pilha* p) {
    return p->topo == MAX - 1;
}

int pilhaVazia(Pilha* p) {
    return p->topo == -1;
}

void empilhar(Pilha* p) {
    if (pilhaCheia(p)) {
        printf("Pilha cheia! Não é possível empilhar.\n");
        return;
    }

    p->topo++;
    printf("Descrição da ação: ");
    scanf(" %49[^\n]", p->itens[p->topo].descricao);

    printf("Ação empilhada com sucesso.\n");
}

void desempilhar(Pilha* p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia! Nada para remover.\n");
        return;
    }

    printf("Ação removida: %s\n", p->itens[p->topo].descricao);
    p->topo--;
}

void mostrarTopo(Pilha* p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia.\n");
        return;
    }

    printf("Topo da pilha: %s\n", p->itens[p->topo].descricao);
}

void listarPilha(Pilha* p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia.\n");
        return;
    }

    printf("\n--- Conteúdo da Pilha ---\n");
    for (int i = p->topo; i >= 0; i--) {
        printf("%s\n", p->itens[i].descricao);
    }
}

/* ================= MAIN ================= */

int main() {
    Pilha p;
    int opcao;

    inicializarPilha(&p);

    do {
        printf("\n1 - Empilhar\n");
        printf("2 - Desempilhar\n");
        printf("3 - Mostrar topo\n");
        printf("4 - Listar pilha\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                empilhar(&p);
                break;
            case 2:
                desempilhar(&p);
                break;
            case 3:
                mostrarTopo(&p);
                break;
            case 4:
                listarPilha(&p);
                break;
            case 0:
                printf("Encerrando programa.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}
