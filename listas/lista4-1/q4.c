#include <stdio.h>
#include <math.h>

float distancia(float x1, float y1, float x2, float y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int pontuacaoPrincipal(float d) {
    if (d <= 1.0) return 10;
    else if (d <= 2.0) return 6;
    else if (d <= 3.0) return 4;
    else return 0;
}

int main() {
    float x, y;
    float ultimoX = 0, ultimoY = 0;
    int total = 0;

    for (int i = 0; i < 10; i++) {
        printf("Digite as coordenadas do lançamento %d (x y): ", i+1);
        scanf("%f %f", &x, &y);
        float dCentro = distancia(x, y, 0, 0);
        int pontos = pontuacaoPrincipal(dCentro);
        total += pontos;
        if (i > 0) {
            float dUltimo = distancia(x, y, ultimoX, ultimoY);
            if (dUltimo <= 3.0) {
                total += pontos / 2;
            }
        }

        ultimoX = x;
        ultimoY = y;
    }

    printf("Pontuação total: %d\n", total);

    return 0;
}
