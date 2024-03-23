#include <stdio.h>


int main() 
{
    int N,M,Q;
    scanf("%d %d %d",&N,&M,&Q);
    
    int row_count = 0, column_count = 0;
    int T,C;
    int com = 0;
    int total = N * M;

    for(int i = 0; i < Q; i++){
        scanf("%d %d\n",&T,&C);
        if(T == 0){
            row_count++;
            com += N;
        }else{
            column_count++;
            com += M;
        }
    }

    printf("%d",total - com + row_count * column_count);

    return 0;
}
