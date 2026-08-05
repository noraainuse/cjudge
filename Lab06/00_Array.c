#include <stdio.h>

int main(void) {
    unsigned int num1, num2, num3, num4, num5, arrLocation;
    scanf("%u", &num1);
    scanf("%u", &num2);
    scanf("%u", &num3);
    scanf("%u", &num4);
    scanf("%u", &num5);
    scanf("%u", &arrLocation);
    unsigned int myNumbers[5] = {num1, num2, num3, num4, num5};
    printf("Value at index %u is %u\n", arrLocation, myNumbers[arrLocation]);
    return 0;
}
