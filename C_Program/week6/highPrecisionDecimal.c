#include <stdio.h>

int main() {
    int a, b;
    scanf("%d/%d", &a, &b); // 读取分子和分母

    printf("0."); // 打印小数点

    // 循环最多200次，模拟长除法过程
    for (int i = 0; i < 200; i++) {
        a *= 10; // 将余数乘以10作为新的被除数
        printf("%d", a / b); // 打印当前位的数字
        a = a % b; // 更新余数
        if (a == 0) {
            break; // 如果余数为0，则除尽了，结束循环
        }
    }

    printf("\n"); // 输出结束后换行
    return 0;
}
