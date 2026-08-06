#include <stdio.h>

int main() {
    unsigned int i = 1, n, sumNum = 0;
    scanf("%u", &n);
    while (i <= n) {
        sumNum += i;
        i++;
    }
    printf("%u\n", sumNum);
    return 0;
}
