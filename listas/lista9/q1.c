#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int campo[10][10];
    int irrigado[10][10] = {0};
    int ferteisIrrigados = 0;
    int ferteisNaoIrrigados = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &campo[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (campo[i][j] == 2) {
                if (i > 0) irrigado[i - 1][j] = 1;
                if (i < m - 1) irrigado[i + 1][j] = 1;
                if (j > 0) irrigado[i][j - 1] = 1;
                if (j < n - 1) irrigado[i][j + 1] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (campo[i][j] == 1) {
                if (irrigado[i][j] == 1) {
                    ferteisIrrigados++;
                } else {
                    ferteisNaoIrrigados++;
                }
            }
        }
    }

    printf("%d %d\n", ferteisIrrigados, ferteisNaoIrrigados);

    return 0;
}
