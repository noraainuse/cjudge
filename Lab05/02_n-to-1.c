#include "stdio.h"

int main() {
    int n;
    char *sep = "";
    scanf("%d", &n);
    
    do {
        printf("%s%d", sep, n);
        sep = " ";
        n--;
    } 
    while (n > 0);
    printf("\n");
    return 0;
}
