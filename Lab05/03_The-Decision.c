#include "stdio.h"

int main() {
    int i, m, n;
    scanf("%d", &m);
    scanf("%d", &n);
    char *sep = "";

    if (m > n) {
        for (i = m; i >= n; i--) {
            printf("%s%d", sep, i);
            sep = " ";
        }
        printf("\n");
    }
    else if (n > m) {
        for (i = m; i <= n; i++) {
            printf("%s%d", sep, i);
            sep = " ";
        }
        printf("\n");
    }
    return 0;
}