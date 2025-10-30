#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogo.h"

int main() {
    int altura, largura;
    int* tabuleiro = NULL;
    int* proximoTabuleiro = NULL;
    char tituloGeracao[100];
    char numStr[12];
    int celulasVivas = 0;
    int numeroGeracoes = 100;

    int opcaoMenu;
    printf("=== Jogo da Vida de Conway ===\n");
    printf("1 - Novo Jogo\n");
    printf("2 - Carregar Jogo de Arquivo\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcaoMenu);
    while (getchar() != '\n'); 

    if (opcaoMenu == 2) {
        tabuleiro = carregarTabuleiro(&altura, &largura, &proximoTabuleiro);
        if (tabuleiro == NULL) {
            printf("Nao foi possivel carregar o jogo. Saindo.\n");
            return 1; 
        }
    } else {
        printf("Digite a altura e largura do tabuleiro (ex: 20 40): ");
        scanf("%d %d", &altura, &largura);
        while (getchar() != '\n');

        if (altura <= 0 || largura <= 0) {
            printf("Dimensoes invalidas!\n");
            return 1;
        }

        tabuleiro = (int*) malloc(altura * largura * sizeof(int));
        proximoTabuleiro = (int*) malloc(altura * largura * sizeof(int));

        if (tabuleiro == NULL || proximoTabuleiro == NULL) {
            printf("Erro fatal: Nao foi possivel alocar memoria para o tabuleiro!\n");
            free(tabuleiro);
            free(proximoTabuleiro);
            return 1;
        }

        inicializarTabuleiro(tabuleiro, altura, largura);
    }


    for (int i = 0; i <= numeroGeracoes; i++) {
        strcpy(tituloGeracao, "Geracao: ");
        sprintf(numStr, "%d", i);
        strcat(tituloGeracao, numStr);

        imprimirTabuleiro(tabuleiro, altura, largura, tituloGeracao, &celulasVivas);
        
        printf("Celulas Vivas: %d\n", celulasVivas);

        calcularProximaGeracao(tabuleiro, proximoTabuleiro, altura, largura);
        copiarTabuleiro(tabuleiro, proximoTabuleiro, altura, largura);
        
        if (i < numeroGeracoes) {
            int input = esperarEnter();
            if (input == 's' || input == 'S') {
                salvarTabuleiro(tabuleiro, altura, largura);
            }
        }
    }

    free(tabuleiro);
    free(proximoTabuleiro);
    printf("Simulacao concluida.\n");
    return 0;
}

