#include "stdio.h"

int main () {
    char userInput; 

    scanf("%c", &userInput);
    if (userInput >= 'a' && userInput <= 'z') {
        printf("%c\n", userInput - 32);
    }
    else if (userInput >= 'A' && userInput <= 'Z') {
        printf("%c\n", userInput + 32);
    }
    else {
        printf("error\n");
    }

    return 0;
}