#include <stdio.h>
#include <ctype.h>

int main() {
    char ch;
    scanf("%c", &ch);

    if (isdigit(ch)) {
        printf("number\n");
    }
    else if (islower(ch)) {
        printf("lowercase\n");
    }
    else if (isupper(ch)) {
        printf("uppercase\n");
    }
    else {
        printf("error\n");
    }
}