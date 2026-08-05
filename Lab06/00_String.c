#include <stdio.h>

int main(void) {
    char uInput[100];
    int loInput;
    scanf("%[^\n]s", uInput);
    scanf("%d", &loInput);
    for (int i = 0; i < loInput; i++) {
        printf("%c", uInput[i]);
    }
    printf("\n");
    return 0;
}