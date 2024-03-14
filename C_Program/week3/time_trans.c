#include <stdio.h>

int main(void)
{
    int bjt;
    int utc;
    int hour, minute;
    scanf("%d",&bjt);

    hour = bjt / 100;
    minute = bjt % 100;

    int ih = hour - 8;
    if(ih < 0){
        ih += 24;
    }

    utc = ih * 100 + minute;

    printf("%d\n",utc);
    return 0;
}