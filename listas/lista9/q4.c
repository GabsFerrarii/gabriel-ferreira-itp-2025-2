#include <stdio.h>

int main() {
    int m;
    scanf("%d", &m);

    int precos[10][10];
    int cidadeX, cidadeZ;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &precos[i][j]);
        }
    }

    scanf("%d %d", &cidadeX, &cidadeZ);

    int menorCusto = precos[cidadeX][cidadeZ];
    int cidadeIntermediaria = -1;

    for (int i = 0; i < m; i++) {
        if (i != cidadeX && i != cidadeZ) {
            int custoComEscala = precos[cidadeX][i] + precos[i][cidadeZ];
            if (custoComEscala < menorCusto) {
                menorCusto = custoComEscala;
                cidadeIntermediaria = i;
            }
        }
    }

    if (cidadeIntermediaria != -1) {
        printf("%d-%d-%d R$%d\n", cidadeX, cidadeIntermediaria, cidadeZ, menorCusto);
    } else {
        printf("%d-%d R$%d\n", cidadeX, cidadeZ, menorCusto);
    }

    return 0;
}
