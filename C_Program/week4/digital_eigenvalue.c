#include <stdio.h>
#include <math.h>

int main()
{
    int num,ans;
    int m,flag;
    int n = 1;
    scanf("%d",&num);
    while(num % 10 != 0){
        m = num % 10;
        if((m % 2 == 0 && n % 2 == 0) || (m % 2 != 0 && n % 2 != 0)){
            flag = 1;
        }else{
            flag = 0;
        }
        ans += pow(2 ,n-1) * flag;
        n++;
        num /= 10;
    }
    printf("%d",ans);

    return 0;
}