#ifndef JOGO_H
#define JOGO_H

#define CELULA_VIVA '#'
#define CELULA_MORTA '.'

void inicializarTabuleiro(int* tabuleiro, int altura, int largura);
void imprimirTabuleiro(int* tabuleiro, int altura, int largura, const char* titulo, int* ptrTotalVivas);
int contarVizinhosVivos(int* tabuleiro, int altura, int largura, int linha, int coluna);
void calcularProximaGeracao(int* tabuleiro, int* proximoTabuleiro, int altura, int largura);
void copiarTabuleiro(int* destino, int* origem, int altura, int largura);
void esperarEnter();

#endif