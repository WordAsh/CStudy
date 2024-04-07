#include <stdio.h>

int main(void)
{
    double salary,rate,tax;
    scanf("%lf",&salary);
    if(salary > 4500){
        rate = 0.2;
    }else if(salary > 3500){
        rate = 0.15;
    }else if(salary > 2500){
        rate = 0.1;
    }else if (salary > 1600){
        rate = 0.05;
    }else{
        rate = 0.0;
    }
    tax = rate * (salary - 1600);
    printf("%.2f",tax);

    return 0;
}