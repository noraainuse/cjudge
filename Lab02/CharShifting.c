#include <stdio.h>
int main() {
    char char1, char2, char3, char4, char5;

    scanf("%c", &char1);
    scanf(" %c", &char2);
    scanf(" %c", &char3);
    scanf(" %c", &char4);
    scanf(" %c", &char5);

    printf("%c\n", char1 + 1);
    printf("%c\n", char2);
    printf("%c\n", char3 + 1);
    printf("%c\n", char4);
    printf("%c\n", char5 + 1);

    return 0;
}