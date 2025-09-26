#include <stdio.h>

int main() {
    int n;
    int contador = 1;

    printf("Digite o numero de linhas: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", contador);
            contador++;
        }
        printf("\n");
    }
    return 0;
}