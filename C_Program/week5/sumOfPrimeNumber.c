#include <stdio.h>
#include <math.h>

// 检查一个数是否为素数
int isPrime(int num) {
    if (num <= 1) return 0; // 0和1不是素数
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return 0; // 如果num能被i整除，则不是素数
    }
    return 1; // 是素数
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m); // 读取n和m

    int count = 0; // 素数计数器
    int sum = 0; // 素数和
    int i = 2; // 从2开始，因为2是第一个素数

    while (count < m) {
        if (isPrime(i)) {
            count++; // 找到一个素数，计数器加1
            if (count >= n) {
                sum += i; // 如果计数器在n和m之间，将当前素数加到sum中
            }
        }
        i++; // 检查下一个数
    }

    printf("%d\n", sum); // 输出素数和
    return 0;
}
