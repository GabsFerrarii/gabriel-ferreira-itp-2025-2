#include <stdio.h>
#include <string.h>

int main() {
    char campo[21];
    int indice;

    scanf("%s %d", campo, &indice);

    if (campo[indice] == 'x') {
        printf("bum!\n");
    } else {
        int bombasVizinhas = 0;
        int len = strlen(campo);

        if (indice > 0 && campo[indice - 1] == 'x') {
            bombasVizinhas++;
        }

        if (indice < len - 1 && campo[indice + 1] == 'x') {
            bombasVizinhas++;
        }

        printf("%d\n", bombasVizinhas);
    }

    return 0;
}