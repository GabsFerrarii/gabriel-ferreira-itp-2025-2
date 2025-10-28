#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"

void inicializarTabuleiro(int* tabuleiro, int altura, int largura) {
    int linha, coluna;

    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            tabuleiro[i * largura + j] = 0;
        }
    }

    int opcao;
    printf("=== Montagem do Tabuleiro ===\n");
    printf("1 - Inserir padrao 'Glider' (planador)\n");
    printf("2 - Inserir padrao 'Blinker' (oscilador)\n");
    printf("3 - Inserir padrao 'Sapo' (oscilador)\n");
    printf("4 - Modo de edicao manual\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1: // Glider
            if (altura > 3 && largura > 3) {
                tabuleiro[1 * largura + 2] = 1;
                tabuleiro[2 * largura + 3] = 1;
                tabuleiro[3 * largura + 1] = 1;
                tabuleiro[3 * largura + 2] = 1;
                tabuleiro[3 * largura + 3] = 1;
            }
            break;
        case 2: // Blinker
            if (altura > 10 && largura > 22) {
                tabuleiro[10 * largura + 20] = 1;
                tabuleiro[10 * largura + 21] = 1;
                tabuleiro[10 * largura + 22] = 1;
            }
            break;
        case 3: // Sapo
             if (altura > 11 && largura > 22) {
                tabuleiro[10 * largura + 20] = 1;
                tabuleiro[10 * largura + 21] = 1;
                tabuleiro[10 * largura + 22] = 1;
                tabuleiro[11 * largura + 19] = 1;
                tabuleiro[11 * largura + 20] = 1;
                tabuleiro[11 * largura + 21] = 1;
             }
            break;
        case 4:
            while (1) {
                imprimirTabuleiro(tabuleiro, altura, largura, "MODO DE EDICAO: Adicione celulas vivas", NULL);
                printf("\nDigite as coordenadas (linha coluna) para adicionar uma celula.\n");
                printf("Digite -1 para iniciar a simulacao.\n");
                printf("Sua vez: ");

                scanf("%d", &linha);
                if (linha == -1) {
                    break;
                }
                scanf("%d", &coluna);

                if (linha >= 0 && linha < altura && coluna >= 0 && coluna < largura) {
                    tabuleiro[linha * largura + coluna] = 1;
                } else {
                    printf("\nCoordenadas invalidas! Tente novamente.\n");
                    esperarEnter();
                }
            }
            break;
        default:
            printf("Opcao invalida. Iniciando com tabuleiro vazio.\n");
            break;
    }
}

void imprimirTabuleiro(int* tabuleiro, int altura, int largura, const char* titulo, int* ptrTotalVivas) {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    printf("=== Jogo da Vida de Conway ===\n");
    printf("%s\n", titulo);

    int contagemVivas = 0;
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            if (tabuleiro[i * largura + j] == 1) {
                printf("%c ", CELULA_VIVA);
                contagemVivas++;
            } else {
                printf("%c ", CELULA_MORTA);
            }
        }
        printf("\n");
    }

    if (ptrTotalVivas != NULL) {
        *ptrTotalVivas = contagemVivas;
    }
}

int contarVizinhosVivos(int* tabuleiro, int altura, int largura, int linha, int coluna) {
    int contador = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }

            int vizinhoLinha = linha + i;
            int vizinhoColuna = coluna + j;

            if (vizinhoLinha >= 0 && vizinhoLinha < altura && vizinhoColuna >= 0 && vizinhoColuna < largura) {
                contador += tabuleiro[vizinhoLinha * largura + vizinhoColuna];
            }
        }
    }
    return contador;
}

void calcularProximaGeracao(int* tabuleiro, int* proximoTabuleiro, int altura, int largura) {
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            int vizinhosVivos = contarVizinhosVivos(tabuleiro, altura, largura, i, j);
            int estadoAtual = tabuleiro[i * largura + j];

            proximoTabuleiro[i * largura + j] = 0;

            if (estadoAtual == 1 && (vizinhosVivos == 2 || vizinhosVivos == 3)) {
                proximoTabuleiro[i * largura + j] = 1;
            }
            if (estadoAtual == 0 && vizinhosVivos == 3) {
                proximoTabuleiro[i * largura + j] = 1;
            }
        }
    }
}

void copiarTabuleiro(int* destino, int* origem, int altura, int largura) {
    int tamanhoTotal = altura * largura;
    for (int i = 0; i < tamanhoTotal; i++) {
        destino[i] = origem[i];
    }
}

void esperarEnter() {
    printf("\nPressione Enter para a proxima acao...");
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}
