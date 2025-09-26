#include <stdio.h>

int main() {
    double valorCompra;
    double percentualDesconto = 0.0;
    double valorDesconto = 0.0;
    double valorFinal = 0.0;

    printf("Digite o valor total da compra: R$ ");
    scanf("%lf", &valorCompra);

    if (valorCompra <= 100.00) {
        percentualDesconto = 0.0;
    } else if (valorCompra <= 500.00) {
        percentualDesconto = 10.0;
    } else if (valorCompra <= 1000.00) {
        percentualDesconto = 15.0;
    } else {
        percentualDesconto = 20.0;
    }

    valorDesconto = valorCompra * (percentualDesconto / 100.0);
    valorFinal = valorCompra - valorDesconto;

    printf("Valor do desconto: R$ %.2f\n", valorDesconto);
    printf("Valor final a pagar: R$ %.2f\n", valorFinal);
    printf("Porcentagem de desconto aplicada: %.0f%%\n", percentualDesconto);
    
    return 0;
}