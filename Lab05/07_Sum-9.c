#include "stdio.h"

int main() {
    int n, op = 0;
    while (1) {
        scanf("%d", &n);
        if (n == -9) {
            break;
        }
        op = op + n;
    }
    printf("%d\n", op);
    return 0;
}
