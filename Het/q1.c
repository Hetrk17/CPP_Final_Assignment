#include <stdio.h>
int main()
{
    float salary,gross_salary;
    printf("Enter your salary:- ");
    scanf("%f", &salary);
    gross_salary = (0.4*salary)+(0.2*salary)+salary;
    printf("gross salary:- %f", gross_salary);
    return 0;
}


