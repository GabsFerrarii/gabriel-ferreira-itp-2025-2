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
    while (getchar() != '\n');

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
                    while (getchar() != '\n');
                    break;
                }
                scanf("%d", &coluna);
                while (getchar() != '\n');

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

            int vizinhoLinha = (linha + i + altura) % altura;
            int vizinhoColuna = (coluna + j + largura) % largura;

            contador += tabuleiro[vizinhoLinha * largura + vizinhoColuna];
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

int esperarEnter() {
    printf("\nPressione Enter para a proxima acao (ou 's' para salvar)...");
    int c = getchar();
    
    int temp;
    if (c != '\n' && c != EOF) {
        while ((temp = getchar()) != '\n' && temp != EOF);
    }
    
    return c;
}

void salvarTabuleiro(int* tabuleiro, int altura, int largura) {
    char nomeArquivo[100];
    printf("\nDigite o nome do arquivo para salvar (ex: padrao.bin): ");
    scanf("%99s", nomeArquivo);
    while (getchar() != '\n'); 

    FILE* arquivo = fopen(nomeArquivo, "wb"); 
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo para salvar!\n");
        esperarEnter();
        return;
    }

    fwrite(&altura, sizeof(int), 1, arquivo);
    fwrite(&largura, sizeof(int), 1, arquivo);
    fwrite(tabuleiro, sizeof(int), altura * largura, arquivo);

    fclose(arquivo);
    printf("Tabuleiro salvo com sucesso em %s!\n", nomeArquivo);
    esperarEnter(); 
}

int* carregarTabuleiro(int* ptrAltura, int* ptrLargura, int** ptrProximoTabuleiro) {
    char nomeArquivo[100];
    printf("Digite o nome do arquivo para carregar (ex: padrao.bin): ");
    scanf("%99s", nomeArquivo);
    while (getchar() != '\n');

    FILE* arquivo = fopen(nomeArquivo, "rb"); 
    if (arquivo == NULL) {
        printf("Erro: Arquivo %s nao encontrado!\n", nomeArquivo);
        return NULL;
    }

    fread(ptrAltura, sizeof(int), 1, arquivo);
    fread(ptrLargura, sizeof(int), 1, arquivo);

    int tamanho = (*ptrAltura) * (*ptrLargura);

    int* tabuleiro = (int*) malloc(tamanho * sizeof(int));
    *ptrProximoTabuleiro = (int*) malloc(tamanho * sizeof(int));

    if (tabuleiro == NULL || *ptrProximoTabuleiro == NULL) {
        printf("Erro ao alocar memoria para carregar o jogo!\n");
        fclose(arquivo);
        free(tabuleiro);
        free(*ptrProximoTabuleiro);
        return NULL;
    }

    fread(tabuleiro, sizeof(int), tamanho, arquivo);

    fclose(arquivo);
    printf("Tabuleiro %dx%d carregado de %s!\n", *ptrAltura, *ptrLargura, nomeArquivo);
    esperarEnter();

    return tabuleiro;
}

