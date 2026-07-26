#include <stdio.h>

int main() {
    double defaultPrice, discount, amount;

    scanf("%lf", &defaultPrice);
    scanf("%lf", &discount);
    scanf("%lf", &amount);

    double total = (defaultPrice - (defaultPrice * discount / 100)) * amount ;
    printf("%.2lf", total);
}
