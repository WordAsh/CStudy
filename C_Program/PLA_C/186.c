#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
    char str[31];
    int n,m;
    scanf("%d %d",&n,&m);
    int k=pow(2,n);
    int a,b;
    for(int i=0;i<m;i++){
        a=1;
        b=k;
        scanf("%s",str);
        for(int j=0;j<strlen(str);j++){
            if(str[j]=='n'){
                a+=(b/2);
            }
            b/=2;
        }
        printf("%d\n",a);
    }
    return 0;
}