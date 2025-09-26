#include <stdio.h>
#include <stdlib.h>

int somaDivisores(int n) {
    int soma = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            soma += i;
            if (i != n / i) {
                soma += n / i;
            }
        }
    }
    return soma;
}

int main() {
    int A, B;
    printf("Digite dois números inteiros diferentes: ");
    scanf("%d %d", &A, &B);

    int DA = somaDivisores(A);
    int DB = somaDivisores(B);

    if (abs(DA - B) <= 2 && abs(DB - A) <= 2) {
        printf("S\n");
    } else {
        printf("N\n");
    }

    return 0;
}
