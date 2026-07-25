#include "stdio.h"

int main() {
    int userInput1, userInput2, output;
    scanf("%d", &userInput1);
    scanf("%d", &userInput2);

    if (userInput1 == userInput2) {
        output = userInput1 + userInput2;
        printf("%d + %d = %d\n", userInput1, userInput2, output);
    }
    else if (userInput1 != userInput2) {
        output = userInput1 - userInput2;
        printf("%d - %d = %d\n", userInput1, userInput2, output);
    }
    
    return 0;
}                                                                      