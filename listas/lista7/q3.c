#include <stdio.h>
#include <string.h>

int main() {
    char targetName[11];
    char currentWord[11];
    int totalClasses = 0;
    int studentAttendances = 0;

    scanf("%s", targetName);

    while (scanf("%s", currentWord) != EOF) {
        if (strlen(currentWord) == 5 && currentWord[2] == '/') {
            totalClasses++;
        } else {
            if (strcmp(currentWord, targetName) == 0) {
                studentAttendances++;
            }
        }
    }

    int faltas = totalClasses - studentAttendances;
    printf("%d\n", faltas);

    return 0;
}
