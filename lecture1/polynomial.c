#include <stdio.h>
#include <time.h>
#include <math.h>
clock_t start, stop;
double duration;
#define MAXN 10 //多项式最大项数
#define MAXK 1e7 //函数调用次数



double f1(int n, double a[], double x);
double f2(int n, double a[], double x);
void calulate_time(double (*f)(int, double[], double),double x);


int main(void)
{
    calulate_time(f1, 1.1);
    calulate_time(f2, 1.1);

    return 0;
}

double f1(int n, double a[], double x)
{
    int i;
    double p = a[0];
    for(int i = 1; i <= n; i++){
        p += (a[i] * pow(x, i));
    }
    return p;
}

double f2(int n, double a[], double x)
{
    int i;
    double p = a[n];
    for(i = n; i > 0; i--){
        p = a[i-1] + x*p;
    }
    return p;
}

void calulate_time(double (*f)(int, double[], double),double x)
{
    int i;
    double a[MAXN];
    for(i = 0; i < MAXN; i++){
        a[i] = (double)i;
    } //初始化系数数组

    start = clock();
    
    for(int j = 0; j < MAXK; j++){
        f(MAXN-1, a, x);
    }//重复

    stop = clock();
    duration = ((double)(stop - start)) / CLK_TCK;
    printf("ticks = %f\n",(double)(stop - start));
    printf("duration = %6.2e\n", duration);

    return;
}