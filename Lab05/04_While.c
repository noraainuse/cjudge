#include "stdio.h"

int main() {
    int i = 1, n;
    scanf("%d", &n);
    char *sep = "";

    while (i <= n) {
        printf("%s%d", sep, i);
        sep = " ";
        i++;
    }
    printf("\n");
    return 0;
}