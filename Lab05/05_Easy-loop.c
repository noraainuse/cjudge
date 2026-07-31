#include "stdio.h"

int main() {
    int n;
    scanf("%d", &n);
    char *sep = "";

    if (n > 0) {
        while (n >= 0) {
            printf("%s%d", sep, n);
            sep = " ";
            n--;
        }
        printf("\n");
    }
    else if (n < 0) {
        while (n <= 0) {
            printf("%s%d", sep, n);
            sep = " ";
            n++;
        }
        printf("\n");
    }
    else {
        printf("%d\n", 0);
    }
    return 0;
}
