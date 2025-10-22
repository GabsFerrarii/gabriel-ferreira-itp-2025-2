#include <stdio.h>
#include <stdlib.h>

int* alocarVetor(int n) {
    int* vetor = (int*) malloc(n * sizeof(int));
    return vetor;
}

void somaVetores(int* u, int n1, int* v, int n2) {
    if (n1 != n2) {
        printf("dimensoes incompativeis\n");
    } else {
        int* soma = alocarVetor(n1);
        for (int i = 0; i < n1; i++) {
            soma[i] = u[i] + v[i];
            printf("%d ", soma[i]);
        }
        printf("\n");
        free(soma);
    }
}

int main() {
    int n1, n2;
    scanf("%d %d", &n1, &n2);

    int* u = alocarVetor(n1);
    int* v = alocarVetor(n2);

    for (int i = 0; i < n1; i++) {
        scanf("%d", &u[i]);
    }

    for (int i = 0; i < n2; i++) {
        scanf("%d", &v[i]);
    }

    somaVetores(u, n1, v, n2);

    free(u);
    free(v);

    return 0;
}
