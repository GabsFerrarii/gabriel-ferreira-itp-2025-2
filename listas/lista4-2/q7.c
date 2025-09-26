#include <stdio.h>

int main(void) {
    int a, b;

    do {
        printf("Digite um numero inteiro para a: ");
        scanf("%d", &a);
        printf("Digite um numero inteiro para b: ");
        scanf("%d", &b);

        if (a <= b) {
            printf("Erro: 'a' deve ser maior que 'b'. Tente novamente.\n\n");
        }
    } while (a <= b);

    printf("\nNumeros primos entre %d e %d:\n", b, a);

    for (int i = b; i <= a; i++) {
        if (i <= 1) {
            continue;
        }

        int ePrimo = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                ePrimo = 0;
                break;
            }
        }

        if (ePrimo) {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}