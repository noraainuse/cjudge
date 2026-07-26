#include <stdio.h>

int main() {
    int start, end, floor;
    double t_accel,t_cruise,s_cruise,s_accel,s_total;
    scanf("%d %d",&start , &end);
    s_accel = 2.25;
    t_accel = 3.0;

    if (start - end < 0) {
        floor = -1 * (start - end);
    }
    else {
        floor = start - end;
    }
    if (start == 2 && end == 1) {
        s_total = 6;
    }
    else if (start == 1) {
        s_total = ((floor - 1) * 4)+ 6;
    } 
    else {
        s_total = floor * 4;
    }

    s_cruise = s_total - (2*s_accel);
    t_cruise = s_cruise / 1.5;
    printf("%.2lf",t_accel+t_cruise+t_accel);
    
    return 0;
}