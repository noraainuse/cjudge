#include <stdio.h>

int main() {
    char fname1[30];
    char sname1[30];
    char person2[80];
    char person3[80];

    scanf("%30s", fname1);
    scanf("%30s", sname1);

    scanf(" %80[^\n]", person2);

    scanf(" %80[^\n]", person3);

    printf("Person 1: %s %s\n", fname1, sname1);
    printf("Person 2: %s\n", person2);
    printf("Person 3: %s\n", person3);

    return 0;
}