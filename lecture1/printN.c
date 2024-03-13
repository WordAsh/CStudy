#include <stdio.h>

void PrintNLoop(int N);
void PrintNRecursive(int N);

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    PrintNLoop(N);
    // PrintNRecursive(N);
    return 0;
}


void PrintNLoop(int N)
{
    int i;
    for(i = 1; i < N; i++)
    {
        printf("%d\n",i);
    }
    return;
}

void PrintNRecursive(int N)
{
    if(N){
        PrintNRecursive(N - 1);
        printf("%d\n", N);
    }
    return;
}