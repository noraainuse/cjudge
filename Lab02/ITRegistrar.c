#include <stdio.h>
int main() {
    char name[31];
    char surname[31];
    char student_id[9];
    int birthday_date;
    int birthday_month;
    int birthday_year;
    float gpa;

    scanf("%30s", name);
    scanf("%30s", surname);
    scanf("%8s", student_id);
    scanf("%d/%d/%d", &birthday_date, &birthday_month, &birthday_year);
    scanf("%f", &gpa);
    
    printf("Fullname: %s %s\n", name, surname);
    printf("ID: %s\n", student_id);
    printf("DOB: %02d-%02d-%04d\n", birthday_date, birthday_month, birthday_year);
    printf("GPA: %.2f\n", gpa);

    return 0;
}