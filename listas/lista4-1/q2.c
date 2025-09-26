#include <stdio.h>
#include <math.h>

int main() {
    float x, y, L;
    int n;

    printf("Digite a coordenada inicial (x y): ");
    scanf("%f %f", &x, &y);
    printf("Digite o comprimento máximo da teia: ");
    scanf("%f", &L);
    printf("Digite a quantidade de alvos: ");
    scanf("%d", &n);

    int i;
    for (i = 0; i < n; i++) {
        float ax, ay;
        printf("Digite a coordenada do alvo %d (x y): ", i+1);
        scanf("%f %f", &ax, &ay);
        float dist = sqrt((ax - x) * (ax - x) + (ay - y) * (ay - y));
        if (dist > L) {
            printf("N\n");
            return 0;
        }
        float novoX = 2 * ax - x;
        float novoY = y;
        x = novoX;
        y = novoY;
    }

    printf("S\n");
    return 0;
}
