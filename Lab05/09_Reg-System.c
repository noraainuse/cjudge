#include "stdio.h"

int main() {
    float age, height, weight;
    float sumAge = 0, sumHeight = 0, sumWeight = 0;
    int i, c1 = 0, c2 = 0, c3 = 0, c4 = 0;

    for (i = 0; i < 50; i++) {
        scanf("%f %f %f", &age, &height, &weight);

        sumAge += age;
        sumHeight += height;
        sumWeight += weight;

        if (age >= 20 && height >= 160) {
            c1++;
        }
        if (age < 20 && (height <= 180 || weight >= 60)) {
            c2++;
        }
        if (age >= 30 && weight >= 40 && weight <= 80) {
            c3++;
        }
        if (age < 40 && (weight < 85 || height <= 200)) {
            c4++;
        }
    }
    printf("Age >= 20 and Height >= 160: %d\n", c1);
    printf("Age < 20 and Height <= 180 or Weight >= 60: %d\n", c2);
    printf("Age >= 30 and Weight >= 40 and Weight <= 80: %d\n", c3);
    printf("Age < 40 and Weight < 85 or Height <= 200: %d\n", c4);
    printf("Average Age: %d\n", (int)sumAge / 50);
    printf("Average Height: %.2f\n", sumHeight / 50);
    printf("Average Weight: %.2f\n", sumWeight / 50);
}