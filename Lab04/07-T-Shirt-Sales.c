#include "stdio.h"

int main() {
    double price;
    int discount, amount;

    scanf("%lf", &price);
    scanf("%d", &discount);
    scanf("%d", &amount);

    double price1 = (price * (100 - discount) / 100.0) * amount;
    int paid_items = amount - (amount / 3);
    double price2 = paid_items * price;
    
    if (price1 <= price2) {
        printf("Discount %d%%\n", discount);
        printf("%.2lf\n", price1);
    } else {
        printf("Buy 2 Get 1\n");
        printf("%.2lf\n", price2);
        }
    return 0;
}