#include <stdio.h>

int main()
{
    int n,i;
    printf("Enter the number of students: \n");
    scanf("%d", &n);

    for(i = 1; i <= n; i++){
        if(i % 2 != 0){
            if(i < n - 1){
                printf("%d ",i);
            }else{
                printf("%d",i);
            }
        }
    }
    return 0;
}