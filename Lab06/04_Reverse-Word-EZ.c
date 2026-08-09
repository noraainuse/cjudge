// Author by noraainuse
#include <stdio.h>

int main(void) {
    char message[100];
    scanf("%[^\n]", message);

    int termi = 0;
    while (message[termi] != '\0') {
        termi++;
    }
    for (int i = termi - 1; i >= 0; i--) {
        printf("%c", message[i]);
    }

    printf("\n");
    return 0;
}