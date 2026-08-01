#include <stdio.h>

int main() {
    float accountBalance;
    float cashOnHand;
    char operation;
    float amount;
    int failCount = 0;

    scanf("%f", &accountBalance);
    scanf("%f", &cashOnHand);

    while (1) {
        scanf("%c %f", &operation, &amount);

        if (operation == 'E')
            break;

        if (operation == 'D') {
            if (cashOnHand - amount >= 0) {
                accountBalance += amount;
                cashOnHand -= amount;
                failCount = 0;
                continue;
            }
            failCount++;
        } else if (operation == 'W') {
            if (accountBalance - amount >= 0) {
                accountBalance -= amount;
                cashOnHand += amount;
                failCount = 0;
                continue;
            }
            failCount++;
        }

        if (failCount == 3)
            break;
    }

    printf("%.2f\n", accountBalance);
    printf("%.2f", cashOnHand);
    return 0;
}
