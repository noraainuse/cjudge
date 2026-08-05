#include <stdio.h>

int main(void) {
    char uInput[100];
    unsigned int loInput;
    scanf("%[^\n]s", uInput);
    scanf("%d", &loInput);

    uInput[loInput] = '\0';
    printf("%s\n", uInput);
    return 0;
}