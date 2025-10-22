#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* misturar(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int totalLen = len1 + len2;

    char* resultado = (char*) malloc((totalLen + 1) * sizeof(char));
    
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < len1 || j < len2) {
        if (i < len1) {
            resultado[k] = str1[i];
            k++;
            i++;
        }
        if (j < len2) {
            resultado[k] = str2[j];
            k++;
            j++;
        }
    }
    
    resultado[k] = '\0';
    return resultado;
}

int main() {
    char str1[101];
    char str2[101];

    fgets(str1, 101, stdin);
    str1[strcspn(str1, "\n")] = 0;

    fgets(str2, 101, stdin);
    str2[strcspn(str2, "\n")] = 0;

    char* stringMisturada = misturar(str1, str2);

    printf("%s\n", stringMisturada);

    free(stringMisturada);

    return 0;
}
