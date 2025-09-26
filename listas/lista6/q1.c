#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int gabarito[20];
    int respostas_aluno[20];
    int acertos = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &gabarito[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &respostas_aluno[i]);
    }

    for (int i = 0; i < n; i++) {
        if (gabarito[i] == respostas_aluno[i]) {
            acertos++;
        }
    }

    printf("%d ", acertos);

    if (acertos == 1) {
        printf("acerto\n");
    } else {
        printf("acertos\n");
    }

    return 0;
}