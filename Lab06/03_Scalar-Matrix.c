// Author by noraainuse
#include <stdio.h>
#define ROWS 3
#define COLS 3

int main(void) {
    double mtrix[ROWS][COLS];
    int isScalar = 1;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            scanf("%lf", &mtrix[i][j]);
        }
    }
    if (mtrix[0][0] == mtrix[1][1] && mtrix[1][1] == mtrix[2][2]) {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if ((i != j) && (mtrix[i][j] != 0)) {
                    isScalar = 0;
                }
            }
        }
    }
    else {
        isScalar = 0;
    }
    if (isScalar) {
        printf("This is a scalar matrix\n");
    } else {
        printf("This is not a scalar matrix\n");
    }
    
    return 0;
}