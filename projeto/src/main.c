#include <stdio.h>
#include <stdlib.h>

#define ALTURA 20
#define LARGURA 40
#define CELULA_VIVA '#'
#define CELULA_MORTA '.'

void inicializarTabuleiro(int tabuleiro[ALTURA][LARGURA]);
void imprimirTabuleiro(int tabuleiro[ALTURA][LARGURA], const char *titulo);
int contarVizinhosVivos(int tabuleiro[ALTURA][LARGURA], int linha, int coluna);
void calcularProximaGeracao(int tabuleiro[ALTURA][LARGURA], int proximoTabuleiro[ALTURA][LARGURA]);
void copiarTabuleiro(int destino[ALTURA][LARGURA], int origem[ALTURA][LARGURA]);
void esperarEnter();

int main()
{
    int tabuleiro[ALTURA][LARGURA];
    int proximoTabuleiro[ALTURA][LARGURA];
    int numeroGeracoes = 100;
    char tituloGeracao[50]; // Buffer para a string do título

    inicializarTabuleiro(tabuleiro);

    for (int i = 0; i <= numeroGeracoes; i++)
    {
        // Formata o título com o número da geração atual
        sprintf(tituloGeracao, "Geracao: %d", i);
        imprimirTabuleiro(tabuleiro, tituloGeracao);

        calcularProximaGeracao(tabuleiro, proximoTabuleiro);
        copiarTabuleiro(tabuleiro, proximoTabuleiro);
        esperarEnter();
    }

    return 0;
}

void inicializarTabuleiro(int tabuleiro[ALTURA][LARGURA])
{
    int linha, coluna;
    for (int i = 0; i < ALTURA; i++)
    {
        for (int j = 0; j < LARGURA; j++)
        {
            tabuleiro[i][j] = 0;
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

    switch (opcao)
    {
    case 1: // Glider
        tabuleiro[1][2] = 1;
        tabuleiro[2][3] = 1;
        tabuleiro[3][1] = 1;
        tabuleiro[3][2] = 1;
        tabuleiro[3][3] = 1;
        break;
    case 2: // Blinker 
        tabuleiro[10][20] = 1;
        tabuleiro[10][21] = 1;
        tabuleiro[10][22] = 1;
        break;
    case 3: // Sapo
        tabuleiro[10][20] = 1;
        tabuleiro[10][21] = 1;
        tabuleiro[10][22] = 1;
        tabuleiro[11][19] = 1;
        tabuleiro[11][20] = 1;
        tabuleiro[11][21] = 1;
        break;
    case 4:
        // Laço para entrada de dados do usuário
        while (1)
        {
            imprimirTabuleiro(tabuleiro, "MODO DE EDICAO: Adicione celulas vivas");
            printf("\nDigite as coordenadas (linha coluna) para adicionar uma celula.\n");
            printf("Digite -1 para iniciar a simulacao.\n");
            printf("Sua vez: ");

            scanf("%d", &linha);
            if (linha == -1)
            {
                break;
            }
            scanf("%d", &coluna);

            if (linha >= 0 && linha < ALTURA && coluna >= 0 && coluna < LARGURA)
            {
                tabuleiro[linha][coluna] = 1;
            }
            else
            {
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

void imprimirTabuleiro(int tabuleiro[ALTURA][LARGURA], const char *titulo)
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    printf("=== Jogo da Vida de Conway ===\n");
    printf("%s\n", titulo);

    for (int i = 0; i < ALTURA; i++)
    {
        for (int j = 0; j < LARGURA; j++)
        {
            char displayChar = (tabuleiro[i][j] == 1) ? CELULA_VIVA : CELULA_MORTA;
            printf("%c ", displayChar);
        }
        printf("\n");
    }
}

int contarVizinhosVivos(int tabuleiro[ALTURA][LARGURA], int linha, int coluna)
{
    int contador = 0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }

            int vizinhoLinha = linha + i;
            int vizinhoColuna = coluna + j;

            if (vizinhoLinha >= 0 && vizinhoLinha < ALTURA && vizinhoColuna >= 0 && vizinhoColuna < LARGURA)
            {
                contador += tabuleiro[vizinhoLinha][vizinhoColuna];
            }
        }
    }
    return contador;
}

void calcularProximaGeracao(int tabuleiro[ALTURA][LARGURA], int proximoTabuleiro[ALTURA][LARGURA])
{
    for (int i = 0; i < ALTURA; i++)
    {
        for (int j = 0; j < LARGURA; j++)
        {
            int vizinhosVivos = contarVizinhosVivos(tabuleiro, i, j);
            int estadoAtual = tabuleiro[i][j];

            proximoTabuleiro[i][j] = 0;

            if (estadoAtual == 1 && (vizinhosVivos == 2 || vizinhosVivos == 3))
            {
                proximoTabuleiro[i][j] = 1;
            }
            if (estadoAtual == 0 && vizinhosVivos == 3)
            {
                proximoTabuleiro[i][j] = 1;
            }
        }
    }
}

void copiarTabuleiro(int destino[ALTURA][LARGURA], int origem[ALTURA][LARGURA])
{
    for (int i = 0; i < ALTURA; i++)
    {
        for (int j = 0; j < LARGURA; j++)
        {
            destino[i][j] = origem[i][j];
        }
    }
}

void esperarEnter()
{
    printf("\nPressione Enter para a proxima acao...");
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}