#include <stdio.h>
#define rows 2
#define cols 3
int main(void) {
    int a[rows][cols] = { {1,2,3},
                          {4,5,6} };
    for (int i = 0; i < rows; i++) {
        for (int j = 0;j < cols; j++) {
            printf("Enter a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("a[%d][%d] = %d\n", i, j, a[i][j]);
        }
    }
    
    return 0;
}