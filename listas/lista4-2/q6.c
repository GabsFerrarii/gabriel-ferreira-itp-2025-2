#include <stdio.h>
#include <math.h>

int main(void) {
    int a, b;
    double c;

    for (a = 1; a < 1000; a++) {
        for (b = a + 1; b < 1000; b++) {
            c = sqrt(a * a + b * b);

            if (c >= 1000) {
                break;
            }

            if (c == (int)c) {
                printf("%d, %d, %d\n", a, b, (int)c);
            }
        }
    }
    return 0;
}