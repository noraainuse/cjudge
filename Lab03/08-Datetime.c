#include <stdio.h>

int main() {
    int total_seconds;
    scanf("%d", &total_seconds);

    int seconds = total_seconds % 60;

    int total_minutes = total_seconds / 60;
    int minutes = total_minutes % 60;
    
    int total_hours = total_minutes / 60;
    int hours = total_hours % 24;
    int days = total_hours / 24;


    printf("%d s = %d d %d h %d m %d s", total_seconds, days, hours, minutes, seconds);
}