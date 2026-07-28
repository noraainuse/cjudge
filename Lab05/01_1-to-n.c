#include "stdio.h"

int main() {
    int n, i;
    char *sep = "";
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("%s%d", sep, i);
        sep = " ";

    }
    printf("\n");
}
