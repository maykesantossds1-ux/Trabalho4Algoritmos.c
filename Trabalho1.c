#include <stdio.h>
#include <string.h>

/*
 Estrutura que representa um território do jogo WAR.
 Cada território possui:
 - nome
 - cor do exército
 - quantidade de tropas
*/
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

int main() {
    // Vetor para armazenar 5 territórios
    Territorio territorios[5];

    printf("=== Cadastro de Territórios - WAR ===\n\n");

    // Cadastro dos territórios
    for (int i = 0; i < 5; i++) {
        printf("Território %d\n", i + 1);

        printf("Nome do território: ");
        scanf(" %29[^\n]", territorios[i].nome);

        printf("Cor do exército: ");
        scanf(" %9s", territorios[i].cor);

        printf("Quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);

        printf("\n");
    }

    // Exibição dos territórios cadastrados
    printf("\n=== Territórios Cadastrados ===\n\n");

    for (int i = 0; i < 5; i++) {
        printf("Território %d\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do Exército: %s\n", territorios[i].cor);
        printf("Tropas: %d\n", territorios[i].tropas);
        printf("-----------------------------\n");
    }

    return 0;
}
