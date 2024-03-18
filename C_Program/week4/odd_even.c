#include <stdio.h>

int main()
{   
    int odd_count = 0, even_count = 0;
    int num;
    scanf("%d",&num);
    while(num != -1){
        if(num % 2 == 0){
            even_count++;
        }else{
            odd_count++;
        }
        scanf("%d",&num);
    }
    printf("%d %d",odd_count,even_count);

    return 0;
}