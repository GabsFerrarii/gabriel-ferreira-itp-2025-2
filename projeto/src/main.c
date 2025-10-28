#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogo.h"

int main() {
    int altura, largura;
    printf("Digite a altura e largura do tabuleiro (ex: 20 40): ");
    scanf("%d %d", &altura, &largura);
    
    while (getchar() != '\n');

    if (altura <= 0 || largura <= 0) {
        printf("Dimensoes invalidas!\n");
        return 1;
    }

    int* tabuleiro = (int*) malloc(altura * largura * sizeof(int));
    int* proximoTabuleiro = (int*) malloc(altura * largura * sizeof(int));

    if (tabuleiro == NULL || proximoTabuleiro == NULL) {
        printf("Erro fatal: Nao foi possivel alocar memoria para o tabuleiro!\n");
        free(tabuleiro);
        free(proximoTabuleiro);
        return 1;
    }

    inicializarTabuleiro(tabuleiro, altura, largura);

    int numeroGeracoes = 100;
    char tituloGeracao[100];
    char numStr[12];
    int celulasVivas = 0;

    for (int i = 0; i <= numeroGeracoes; i++) {
        strcpy(tituloGeracao, "Geracao: ");
        sprintf(numStr, "%d", i);
        strcat(tituloGeracao, numStr);

        imprimirTabuleiro(tabuleiro, altura, largura, tituloGeracao, &celulasVivas);
        
        printf("Celulas Vivas: %d\n", celulasVivas);

        calcularProximaGeracao(tabuleiro, proximoTabuleiro, altura, largura);
        copiarTabuleiro(tabuleiro, proximoTabuleiro, altura, largura);
        
        if (i < numeroGeracoes) {
            esperarEnter();
        }
    }

    free(tabuleiro);
    free(proximoTabuleiro);
    printf("Simulacao concluida.\n");
    return 0;
}