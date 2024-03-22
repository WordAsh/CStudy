#include <stdio.h>


int main(void)
{
    int a1,b1,a2,b2;
    scanf("%d/%d %d/%d",&a1,&b1,&a2,&b2);

    double res1 = (double)a1 / b1;
    double res2 = (double)a2 / b2;

    if(res1 > res2){
        printf("%d/%d > %d/%d",a1,b1,a2,b2);
    }else if(res1 < res2){
        printf("%d/%d < %d/%d",a1,b1,a2,b2);
    }else{
        printf("%d/%d = %d/%d",a1,b1,a2,b2);
    }

    return 0;
}