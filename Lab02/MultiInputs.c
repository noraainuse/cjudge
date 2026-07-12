#include <stdio.h>

int main() {
    char userInput1[30];
    scanf("%30s", &userInput1);


    char userInput2[30];
    scanf("%30s", &userInput2);


    char userInput3[30];
    scanf("%30s", &userInput3);

    char userInput4[30];
    scanf("%30s", &userInput4);

    printf("String 1: %.3s\n", userInput1);
    printf("String 2: %.4s\n", userInput2);
    printf("String 3: %.5s\n", userInput3);
    printf("String 4: %.6s\n", userInput4);

    return 0;
}