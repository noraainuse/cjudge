#include <stdio.h>
#include <math.h>

int main(){
    float kg;
    float height;
    scanf("%f",&height);
    scanf("%f",&kg);
    printf("%f",kg/((height/100)*(height/100)));
    return 0;
}