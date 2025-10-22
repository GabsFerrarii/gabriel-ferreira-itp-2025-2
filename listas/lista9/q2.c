#include <stdio.h>

int main() {
    int m;
    scanf("%d", &m);

    int amizades[100][100];
    int usuarioX;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &amizades[i][j]);
        }
    }

    scanf("%d", &usuarioX);

    for (int i = 0; i < m; i++) {
        if (i == usuarioX) {
            continue;
        }

        if (amizades[usuarioX][i] == 0) {
            int amigoEmComum = 0;
            for (int j = 0; j < m; j++) {
                if (amizades[usuarioX][j] == 1 && amizades[i][j] == 1) {
                    amigoEmComum = 1;
                    break;
                }
            }

            if (amigoEmComum) {
                printf("%d\n", i);
            }
        }
    }

    return 0;
}
