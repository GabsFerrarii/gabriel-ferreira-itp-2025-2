#include <stdio.h>

int main(void) {
    int precoFornecedor1, precoFornecedor2, quantiaDisponivel;
    int custoTotal, restante;

    printf("Digite o preco do primeiro fornecedor: ");
    scanf("%d", &precoFornecedor1);

    printf("Digite o preco do segundo fornecedor: ");
    scanf("%d", &precoFornecedor2);

    printf("Digite a quantia disponivel: ");
    scanf("%d", &quantiaDisponivel);

    printf("\n");

    for (int unidades1 = 0; unidades1 <= 10; unidades1++) {
        for (int unidades2 = 0; unidades2 <= 10; unidades2++) {
            custoTotal = (unidades1 * precoFornecedor1) + (unidades2 * precoFornecedor2);

            if (custoTotal <= quantiaDisponivel) {
                restante = quantiaDisponivel - custoTotal;
                printf("Comprando %d do primeiro e %d do segundo resta: %d\n", unidades1, unidades2, restante);
            }
        }
    }
    return 0;
}