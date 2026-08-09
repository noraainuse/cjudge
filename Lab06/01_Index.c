#include <stdio.h>

int main(void) {
    int M[] = {2, 20, 8, 10, 4, 6, 16, 18};
    int N[] = {1, 3, 9, 7, 11, 15, 19};
    int M_size = sizeof(M) / sizeof(M[0]);
    int N_size = sizeof(N) / sizeof(N[0]);

    int numInput;

    while (scanf("%d", &numInput) == 1) {
        if (numInput < 1 || numInput > 20)
            continue;

        int idx = -1;
        for (int i = 0; i < M_size; i++) {
            if (M[i] == numInput) {
                idx = i;
                break;
            }
        }

        if (idx != -1) {
            printf("%d is in M at index [%d]\n", numInput, idx);
        } else {
            for (int i = 0; i < N_size; i++) {
                if (N[i] == numInput) {
                    idx = i;
                    break;
                }
            }
            if (idx != -1)
                printf("%d is in N at index [%d]\n", numInput, idx);
            else
                printf("%d is not in neither M nor N\n", numInput);
        }
    }

    return 0;
}
