#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int alturas[30];
    int max_altura = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &alturas[i]);
        if (alturas[i] > max_altura) {
            max_altura = alturas[i];
        }
    }

    int indice1 = -1;
    int indice2 = -1;

    for (int i = 0; i < n; i++) {
        if (alturas[i] == max_altura) {
            if (indice1 == -1) {
                indice1 = i;
            } else {
                indice2 = i;
            }
        }
    }

    int comprimento = (indice2 - indice1) - 1;
    printf("%d\n", comprimento);

    return 0;
}