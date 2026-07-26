#include <stdio.h>

int main() {
    double rawScore;
    scanf("%lf", &rawScore);

    if (rawScore > 100) {
        printf("Out of Range\n");
    }
    else if ((rawScore >= 80) && (rawScore <= 100)) {
        printf("A\n");
    }
    else if (rawScore >= 70) {
        printf("B\n");
    }
    else if (rawScore >= 60) {
        printf("C\n");
    }
    else if (rawScore >= 50) {
        printf("D\n");
    }
    else if (rawScore >= 0) {
        printf("F\n");
    }
    else {
        printf("Out of Range\n");
    }
    
}