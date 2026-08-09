#include "stdio.h"

int main(void) {
    int a[2][3] = { {1,2,3},
                    {4,5,6}
    };
    printf("a [0] [2] = %d\n", a[1][1]);
}