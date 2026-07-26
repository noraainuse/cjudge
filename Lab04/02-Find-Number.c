#include "stdio.h"

int main() {
    double a, b, c;
    double median;

    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);

    if ((a >= b && a <= c) || (a <= b && a >= c)) {
        median = a;
    }
    else if (((b >= a) && (b <= c)) || ((b <= a) && ( b >= c))) {
        median = b;
    }
    else {
        median = c;
    }
    printf("%.2lf\n", median);

}