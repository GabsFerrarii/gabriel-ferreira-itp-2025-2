#include <stdio.h>
#include <math.h>

double calculaAltura(double x, double y) {
    return sin(cos(y) + x) + cos(y + sin(x));
}

int ehPontoSeguro(double x, double y) {
    double h;
    h = calculaAltura(x, y);
    if (h < 0.0 || h > 2.0) return 0;
    h = calculaAltura(x + 0.2, y + 0.2);
    if (h < 0.0 || h > 2.0) return 0;
    h = calculaAltura(x - 0.2, y - 0.2);
    if (h < 0.0 || h > 2.0) return 0;
    h = calculaAltura(x + 0.2, y - 0.2);
    if (h < 0.0 || h > 2.0) return 0;
    h = calculaAltura(x - 0.2, y + 0.2);
    if (h < 0.0 || h > 2.0) return 0;
    return 1;
}

int main() {
    double x, y;
    scanf("%lf %lf", &x, &y);
    if (x == 0.0 && y == 0.0) {
        printf("relativamente seguro\n");
        return 0;
    }

    if (ehPontoSeguro(x, y) == 0) {
        printf("troque de coordenada\n");
    } else {
        int vizinhosSeguros = 0;
        if (ehPontoSeguro(x + 2.0, y)) vizinhosSeguros++;
        if (ehPontoSeguro(x - 2.0, y)) vizinhosSeguros++;
        if (ehPontoSeguro(x, y + 2.0)) vizinhosSeguros++;
        if (ehPontoSeguro(x, y - 2.0)) vizinhosSeguros++;

        if (vizinhosSeguros <= 1) {
            printf("inseguro\n");
        } else if (vizinhosSeguros <= 3) {
            printf("relativamente seguro\n");
        } else {
            printf("seguro\n");
        }
    }
    return 0;
}