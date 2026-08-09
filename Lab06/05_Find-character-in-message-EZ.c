// Author by noraainuse
#include <stdio.h>

int main(void) {
    char message[300];
    char targeted;
    char finalP;
    int amount = 0;
    int lentmi = 0;
    char *sep = "";
    scanf("%[^\n]", message);
    scanf(" %c", &targeted);
    if (targeted >= 97) {
        finalP = targeted - 32;
    }
    while (message[lentmi] != '\0') {
        lentmi++;
    }
    for (int i = 0; i < lentmi; i++) {
        if (finalP == message[i] || finalP + 32 == message[i]) {
            amount++;
        }
    }
    if (amount) {
        printf("There is/are %d \"%c\" in the above sentences.\n", amount, targeted);
        printf("Position: ");
        for (int i = 0; i < lentmi; i++) {
            if (finalP == message[i] || finalP + 32 == message[i]) {
                printf("%s%d", sep, i + 1);
                sep = ", ";
            }
        }
        printf("\n");
    } else {
        printf("Not found.\n");
    }
    
      
    return 0;
}