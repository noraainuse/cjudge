#include <stdio.h>

int main() {
    int integerNum;
    float floatNum;
    char Chac;
    char string[50];

    scanf("%d", &integerNum);
    scanf(" %f", &floatNum);
    scanf(" %c", &Chac);
    scanf(" %49s", &string);

    printf("Integer: %d\n", integerNum);
    printf("Float: %.3f\n", floatNum);
    printf("Character: %c\n", Chac);
    printf("String: %s\n", string);

}