#include "stdio.h"

int main() {
    int n;
    scanf("%d", &n);
    char *sep = "";

    while (n >= 0) {
        printf("%s%d", sep, n);
        sep = " ";
        n--;
    }
    printf("\n");
    return 0;
}