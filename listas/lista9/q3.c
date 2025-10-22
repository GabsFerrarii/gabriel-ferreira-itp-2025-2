#include <stdio.h>

int main() {
    int m;
    scanf("%d", &m);

    int resultados[20][20];
    int empates = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &resultados[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (resultados[i][j] == resultados[j][i]) {
                empates++;
            }
        }
    }

    printf("%d\n", empates);

    return 0;
}
