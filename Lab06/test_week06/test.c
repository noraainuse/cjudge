#include <stdio.h>

int main() {
    int i = 1, n;
    char *sep = "";
    scanf("%d", &n);

    while (i <= n) {
        printf("%s%d", sep, i);
        i++;
        sep = " ";
    }

    return 0;
}