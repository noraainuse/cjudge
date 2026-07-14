#include <stdio.h>

int main() {
    int inputNumber;
    scanf("%d", &inputNumber);

    int firstR = inputNumber / 10000;
    int secondR = inputNumber / 1000;
    int thirdR = inputNumber / 100;
    int fourthR = inputNumber / 10;
    
    printf("%d\x0A", firstR);
    printf("\x20%d\x0A", secondR);
    printf("\x20\x20%d\x0A", thirdR);
    printf("\x20\x20\x20%d\x0A", fourthR);
    printf("\x20\x20\x20\x20%d\x0A", inputNumber);
}