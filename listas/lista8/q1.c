#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int numerosSorteados[30];
    int numerosApostados[50];
    int acertos = 0;

    for (int i = 0; i < m; i++) {
        scanf("%d", &numerosSorteados[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &numerosApostados[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (numerosApostados[i] == numerosSorteados[j]) {
                acertos++;
                break;
            }
        }
    }

    printf("%d\n", acertos);

    return 0;
}
