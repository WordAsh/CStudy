#include <stdio.h>

int main()
{   
    int num;
    char *string[] = {"ling","yi","er","san","si","wu","liu","qi"
    ,"ba","jiu"};

    scanf("%d",&num);

    if(num < 0){
        printf("fu ");
        num = -num;
    }

    int i = 0;
    int arr[10];
    while(num > 0){
        arr[i++] = num % 10;
        num /= 10;
    }

    for(; i >= 1; i--){
        printf(string[arr[i-1]]);
        if(i != 1){
            printf(" ");
        }
    }

    return 0;
}