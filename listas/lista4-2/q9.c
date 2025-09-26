#include <stdio.h>

int main(void) {
    int precoFornecedor1, precoFornecedor2, quantiaDisponivel;
    int melhorCompra1 = 0, melhorCompra2 = 0;
    int menorResto;

    printf("Digite o preco do primeiro fornecedor: ");
    scanf("%d", &precoFornecedor1);

    printf("Digite o preco do segundo fornecedor: ");
    scanf("%d", &precoFornecedor2);

    printf("Digite a quantia disponivel: ");
    scanf("%d", &quantiaDisponivel);

    menorResto = quantiaDisponivel;

    for (int unidades1 = 0; unidades1 <= 10; unidades1++) {
        for (int unidades2 = 0; unidades2 <= 10; unidades2++) {
            int custoTotal = (unidades1 * precoFornecedor1) + (unidades2 * precoFornecedor2);

            if (custoTotal <= quantiaDisponivel) {
                int restoAtual = quantiaDisponivel - custoTotal;

                if (restoAtual < menorResto) {
                    menorResto = restoAtual;
                    melhorCompra1 = unidades1;
                    melhorCompra2 = unidades2;
                }
            }
        }
    }

    printf("Resta menos comprando %d do primeiro e %d do segundo\n", melhorCompra1, melhorCompra2);

    return 0;
}