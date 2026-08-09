#include "stdio.h"

int main(void) {
    int a[2][3] = { {1,2,3},
                    {4,5,6}
    };
    printf("a [0] [2] = %d\n", a[1][1]);
    double arr_one[3][3];
    double arr_two[3][3];
    double sum_arr[3][3];
    char *sep = "";
    for (int i = 0; i < 3; i++) {   //rows อิหยัง
        for (int j = 0; j < 3; j++) {   //col เจโคตรอรอ่ย
            scanf("%lf", &arr_one[i][j]);
        }
    }
    for (int i = 0; i < 3; i++) {   //rows
        for (int j = 0; j < 3; j++) {   //col
            scanf("%lf", &arr_two[i][j]);
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sum_arr[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                sum_arr[i][j] += arr_one[i][k] * arr_two[k][j];
            }
        }
    }
    printf("A x B\n");
    for (int i = 0; i < 3; i++) {
        sep = "";
        for (int j = 0; j < 3; j++) {
            printf("%s%.2lf", sep, sum_arr[i][j]);
            sep = " ";
            }
        printf("\n");
        }
    return 0;
}