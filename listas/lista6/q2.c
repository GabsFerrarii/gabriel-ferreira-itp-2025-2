#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int figurinhas_possuidas[1001] = {0};
    int numero_figurinha;

    for (int i = 0; i < n; i++) {
        scanf("%d", &numero_figurinha);
        if (numero_figurinha >= 1 && numero_figurinha <= m) {
            figurinhas_possuidas[numero_figurinha] = 1;
        }
    }

    int primeiro_numero = 1;
    for (int i = 1; i <= m; i++) {
        if (figurinhas_possuidas[i] == 0) {
            if (primeiro_numero == 0) {
                printf(" ");
            }
            printf("%d", i);
            primeiro_numero = 0;
        }
    }
    printf("\n");

    return 0;
}