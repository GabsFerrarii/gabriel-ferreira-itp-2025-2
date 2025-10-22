#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int ordemLargada[20];
    int ordemChegada[20];
    int posicaoLargada[21];
    int posicaoChegada[21];

    for (int i = 0; i < n; i++) {
        scanf("%d", &ordemLargada[i]);
        posicaoLargada[ordemLargada[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &ordemChegada[i]);
        posicaoChegada[ordemChegada[i]] = i;
    }

    int pilotoVencedor = 0;
    int maxPosicoesGanhas = 0;
    int houveEmpate = 0;

    for (int piloto = 1; piloto <= n; piloto++) {
        int posicoesGanhas = posicaoLargada[piloto] - posicaoChegada[piloto];
        if (posicoesGanhas > maxPosicoesGanhas) {
            maxPosicoesGanhas = posicoesGanhas;
            pilotoVencedor = piloto;
            houveEmpate = 0;
        } else if (posicoesGanhas == maxPosicoesGanhas && maxPosicoesGanhas > 0) {
            houveEmpate = 1;
        }
    }

    if (houveEmpate || maxPosicoesGanhas == 0) {
        printf("empate\n");
    } else {
        printf("%d\n", pilotoVencedor);
    }

    return 0;
}