#include "stdio.h"

int main(){
    double a,b,c;
    int fi , se , th;

    scanf("%lf",&a);
    scanf("%lf",&b);
    scanf("%lf",&c);

    fi = a + b > c;
    se = a + c > b;
    th = b + c > a;

    if (fi && se && th) {
        printf("Triangle is valid.");
    }
    else {
        printf("Triangle is not valid.");
    }
}