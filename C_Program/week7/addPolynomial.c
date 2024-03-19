#include <stdio.h>

#define MAX_DEGREE 100

int main()
{
    int coefficients[MAX_DEGREE + 1] = {0};
    int degree, coeff;

    while(scanf("%d %d",&degree, &coeff) != EOF && degree != 0){
        coefficients[degree] += coeff;
    }
    coefficients[0] += coeff;

    while(scanf("%d %d",&degree, &coeff) != EOF && degree != 0){
        coefficients[degree] += coeff;
    }
    coefficients[0] += coeff;

    int firstItemPrinted = 0;
    for(int i = MAX_DEGREE; i >= 0; i--){
        if(coefficients[i] != 0){
            if(firstItemPrinted){
                printf("+");
            }
            if(i == 0){
                printf("%d",coefficients[i]);
            }else if(i == 1){
                printf("%dx",coefficients[i]);
            }else{
                printf("%dx%d",coefficients[i],i);
            }
            firstItemPrinted = 1;
        }
    }

    if(!firstItemPrinted){
        printf("0");
    }

    printf("\n");


    return 0;
}