#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

static int global_var = 10;

void greet_run(void);
void counter(void);

int main(void)
{
    for(int i=0;i<5;i++){
        counter();
    }

    return 0;
}



void counter(void){
    static int cnt = 1;
    printf("%d ",cnt);
    cnt++;
}



