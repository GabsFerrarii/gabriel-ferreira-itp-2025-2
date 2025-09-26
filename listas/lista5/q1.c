#include <stdio.h>

void imprimeHorario(int h, int m, int formato) {
    int totalMinutos = h * 60 + m;
    int horasFinais = (totalMinutos / 60) % 24;
    int minutosFinais = totalMinutos % 60;

    if (formato == 0) {
        printf("%02d:%02d\n", horasFinais, minutosFinais);
    } else {
        int horas12h;
        char* periodo;

        if (horasFinais == 0) {
            horas12h = 12;
            periodo = "AM";
        } else if (horasFinais < 12) {
            horas12h = horasFinais;
            periodo = "AM";
        } else if (horasFinais == 12) {
            horas12h = 12;
            periodo = "PM";
        } else {
            horas12h = horasFinais - 12;
            periodo = "PM";
        }
        printf("%02d:%02d %s\n", horas12h, minutosFinais, periodo);
    }
}

int main() {
    int hInicial, mInicial, formato;
    scanf("%d %d %d", &hInicial, &mInicial, &formato);

    imprimeHorario(hInicial, mInicial, formato);
    imprimeHorario(hInicial + 1, mInicial, formato);
    imprimeHorario(hInicial + 2, mInicial + 10, formato);
    imprimeHorario(hInicial + 4, mInicial + 40, formato);
    imprimeHorario(hInicial + 12, mInicial + 5, formato);

    return 0;
}