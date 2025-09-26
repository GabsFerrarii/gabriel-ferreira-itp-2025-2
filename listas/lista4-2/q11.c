#include <stdio.h>
#include <stdlib.h>

#define N 4

void imprimirSolucao(int posicoes[N], int *contadorSolucao) {
    printf("Solucao #%d:\n", (*contadorSolucao)++);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (posicoes[i] == j) {
                printf(" Q ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int ehSeguro(int linha, int coluna, int posicoes[N]) {
    for (int i = 0; i < linha; i++) {
        if (posicoes[i] == coluna || abs(posicoes[i] - coluna) == abs(i - linha)) {
            return 0;
        }
    }
    return 1;
}

void resolver(int linha, int posicoes[N], int *contadorSolucao) {
    if (linha == N) {
        imprimirSolucao(posicoes, contadorSolucao);
        return;
    }

    for (int coluna = 0; coluna < N; coluna++) {
        if (ehSeguro(linha, coluna, posicoes)) {
            posicoes[linha] = coluna;
            resolver(linha + 1, posicoes, contadorSolucao);
        }
    }
}

int main() {
    int posicoes[N];
    int contadorSolucao = 1;

    printf("Buscando todas as solucoes para o problema das 4 rainhas...\n\n");
    
    resolver(0, posicoes, &contadorSolucao);

    return 0;
}