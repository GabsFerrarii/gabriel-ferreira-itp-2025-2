#include <stdio.h>

int main(void) {
    float p, q;
    int melhorX = 1;
    int melhorY = 1;
    float maiorRazao = 1.0f;

    printf("Digite o preco de venda p: ");
    scanf("%f", &p);

    printf("Digite o preco de producao q: ");
    scanf("%f", &q);

    for (int x = 2; x <= 10; x++) {
        for (int y = 1; y < x; y++) {
            if (y * p >= x * q) {
                float razaoAtual = (float)x / y;

                if (razaoAtual > maiorRazao) {
                    maiorRazao = razaoAtual;
                    melhorX = x;
                    melhorY = y;
                }
            }
        }
    }

    printf("A melhor promocao eh: leve %d pague %d\n", melhorX, melhorY);

    return 0;
}