#include <stdio.h>
#include <stdlib.h>

#define ALTURA 20
#define LARGURA 40
#define CELULA_VIVA '#'
#define CELULA_MORTA '.'

// Protótipos das funções
void inicializarTabuleiro(int tabuleiro[ALTURA][LARGURA]);
void imprimirTabuleiro(int tabuleiro[ALTURA][LARGURA], const char* titulo);
int contarVizinhosVivos(int tabuleiro[ALTURA][LARGURA], int linha, int coluna);
void calcularProximaGeracao(int tabuleiro[ALTURA][LARGURA], int proximoTabuleiro[ALTURA][LARGURA]);
void copiarTabuleiro(int destino[ALTURA][LARGURA], int origem[ALTURA][LARGURA]);
void esperarEnter();

// Função principal que orquestra a execução do Jogo da Vida.
int main() {
    int tabuleiro[ALTURA][LARGURA];
    int proximoTabuleiro[ALTURA][LARGURA];
    int numeroGeracoes = 100;
    char tituloGeracao[50]; // Buffer para a string do título

    inicializarTabuleiro(tabuleiro);

    // Laço de repetição principal do jogo
    for (int i = 0; i <= numeroGeracoes; i++) {
        // Formata o título com o número da geração atual
        sprintf(tituloGeracao, "Geracao: %d", i);
        imprimirTabuleiro(tabuleiro, tituloGeracao);
        
        calcularProximaGeracao(tabuleiro, proximoTabuleiro);
        copiarTabuleiro(tabuleiro, proximoTabuleiro);
        esperarEnter();
    }

    return 0;
}

// Preenche o tabuleiro com base nas coordenadas inseridas pelo usuário.
void inicializarTabuleiro(int tabuleiro[ALTURA][LARGURA]) {
    int linha, coluna;

    // Primeiro, limpa o tabuleiro (todas as células mortas)
    for (int i = 0; i < ALTURA; i++) {
        for (int j = 0; j < LARGURA; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Laço para entrada de dados do usuário
    while (1) {
        imprimirTabuleiro(tabuleiro, "MODO DE EDICAO: Adicione celulas vivas");
        printf("\nDigite as coordenadas (linha coluna) para adicionar uma celula.\n");
        printf("Digite -1 para iniciar a simulacao.\n");
        printf("Sua vez: ");

        scanf("%d", &linha);
        // Se o primeiro número for -1, paramos de pedir coordenadas
        if (linha == -1) {
            break;
        }
        scanf("%d", &coluna);

        // Validação das coordenadas
        if (linha >= 0 && linha < ALTURA && coluna >= 0 && coluna < LARGURA) {
            tabuleiro[linha][coluna] = 1; // Adiciona uma célula viva
        } else {
            printf("\nCoordenadas invalidas! Tente novamente.\n");
            esperarEnter(); // Pausa para o usuário ler a mensagem
        }
    }
}

// Imprime o estado atual do tabuleiro no terminal.
void imprimirTabuleiro(int tabuleiro[ALTURA][LARGURA], const char* titulo) {
    // Limpa a tela para uma animação mais fluida
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    printf("=== Jogo da Vida de Conway ===\n");
    printf("%s\n", titulo);

    for (int i = 0; i < ALTURA; i++) {
        for (int j = 0; j < LARGURA; j++) {
            char displayChar = (tabuleiro[i][j] == 1) ? CELULA_VIVA : CELULA_MORTA;
            printf("%c ", displayChar);
        }
        printf("\n");
    }
}

// Conta o número de vizinhos vivos de uma célula específica.
int contarVizinhosVivos(int tabuleiro[ALTURA][LARGURA], int linha, int coluna) {
    int contador = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue; // Não conta a própria célula
            }

            int vizinhoLinha = linha + i;
            int vizinhoColuna = coluna + j;

            // Garante que o vizinho esteja dentro dos limites do tabuleiro
            if (vizinhoLinha >= 0 && vizinhoLinha < ALTURA && vizinhoColuna >= 0 && vizinhoColuna < LARGURA) {
                contador += tabuleiro[vizinhoLinha][vizinhoColuna];
            }
        }
    }
    return contador;
}

/*
 * Calcula a próxima geração do tabuleiro com base nas regras do jogo.
 * Usa um tabuleiro auxiliar para garantir que a atualização de todas as células
 * seja baseada no estado original da geração atual (atualização "simultânea").
 */
void calcularProximaGeracao(int tabuleiro[ALTURA][LARGURA], int proximoTabuleiro[ALTURA][LARGURA]) {
    for (int i = 0; i < ALTURA; i++) {
        for (int j = 0; j < LARGURA; j++) {
            int vizinhosVivos = contarVizinhosVivos(tabuleiro, i, j);
            int estadoAtual = tabuleiro[i][j];
            
            proximoTabuleiro[i][j] = 0;

            if (estadoAtual == 1 && (vizinhosVivos == 2 || vizinhosVivos == 3)) {
                proximoTabuleiro[i][j] = 1;
            }
            if (estadoAtual == 0 && vizinhosVivos == 3) {
                proximoTabuleiro[i][j] = 1;
            }
        }
    }
}

// Copia o tabuleiro de origem para o de destino.
void copiarTabuleiro(int destino[ALTURA][LARGURA], int origem[ALTURA][LARGURA]) {
    for (int i = 0; i < ALTURA; i++) {
        for (int j = 0; j < LARGURA; j++) {
            destino[i][j] = origem[i][j];
        }
    }
}

// Pausa a execução e espera o usuário pressionar a tecla Enter.
void esperarEnter() {
    printf("\nPressione Enter para a proxima acao...");
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}