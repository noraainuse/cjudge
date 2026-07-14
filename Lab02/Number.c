#include <stdio.h>

int main() {
    int input_num;
    scanf("%d", &input_num);
    
    int last_two = input_num / 1000;
    int first_three = input_num % 1000;
    int fin = (first_three * 100) + last_two;
    printf("%d\n", fin);
}