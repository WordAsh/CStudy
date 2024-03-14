/*
逆序的三位数
*/

#include <stdio.h>

int main(void)
{
    int num;
    int one;
    int two;
    int three;
    scanf("%d", &num);

    three = num / 100;
    two = num / 10 % 10;
    one = num % 10;

    if(one == 0){
        if(two == 0){
            printf("%d",three);
        }else{
            printf("%d",two * 10 + three);
        }
    }else{
        printf("%d",one * 100 + two * 10 + three);
    }

    return 0;
}