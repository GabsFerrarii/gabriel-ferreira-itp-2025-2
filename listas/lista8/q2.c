#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[10];
    int chuva;
} Mes;

int main() {
    Mes meses[12];
    char nomesDosMeses[12][10] = {
        "Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho",
        "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"
    };

    for (int i = 0; i < 12; i++) {
        strcpy(meses[i].nome, nomesDosMeses[i]);
        scanf("%d", &meses[i].chuva);
    }

    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11 - i; j++) {
            if (meses[j].chuva < meses[j + 1].chuva) {
                Mes temp = meses[j];
                meses[j] = meses[j + 1];
                meses[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < 12; i++) {
        printf("%s %d\n", meses[i].nome, meses[i].chuva);
    }

    return 0;
}
