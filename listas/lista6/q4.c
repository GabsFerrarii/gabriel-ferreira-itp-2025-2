#include <stdio.h>

int main() {
    int mapa[10];
    int visitas[10] = {0};
    int ilha_atual = 0;

    for (int i = 0; i < 10; i++) {
        scanf("%d", &mapa[i]);
    }

    while (1) {
        visitas[ilha_atual]++;

        if (visitas[ilha_atual] == 2) {
            printf("%d\n", ilha_atual);
            break;
        }

        ilha_atual = mapa[ilha_atual];
    }

    return 0;
}