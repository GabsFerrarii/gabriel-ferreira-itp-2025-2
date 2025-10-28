#include <stdio.h>

int main() {
    int m;
    scanf("%d", &m);

    int amizades[100][100];
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &amizades[i][j]);
        }
    }

    int usuarioX;
    scanf("%d", &usuarioX);

    int primeiraSugestao = 1;

    for (int j = 0; j < m; j++) {
        if (j == usuarioX || amizades[usuarioX][j] == 1) {
            continue;
        }

        int temAmigoEmComum = 0;
        for (int k = 0; k < m; k++) {
            if (amizades[usuarioX][k] == 1 && amizades[j][k] == 1) {
                temAmigoEmComum = 1;
                break;
            }
        }

        if (temAmigoEmComum) {
            if (primeiraSugestao == 0) {
                printf(" ");
            }
            printf("%d", j);
            primeiraSugestao = 0;
        }
    }

    printf("\n");

    return 0;
}

