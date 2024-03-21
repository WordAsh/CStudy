#include <stdio.h>


int main()
{
    int *arr;
    int i = 0;
    int num;
    while(scanf("%d",&num)){
        if(num == -1){
            break;
        }
        arr[i++] = num;
    }

    for(; i > 0; i--){
        printf("%d ",arr[i-1]);
    }

    return 0;
}