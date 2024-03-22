#include <stdio.h>
#include <string.h>

int main() {
    char str1[10000];
    char str2[10000];
    fgets(str1, 10000, stdin); // 读取第一个字符串
    fgets(str2, 10000, stdin); // 读取第二个字符串

    // 移除字符串末尾的换行符
    str1[strcspn(str1, "\n")] = 0;
    str2[strcspn(str2, "\n")] = 0;

    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int found = 0; // 标记是否找到匹配的子字符串

    for (int i = 0; i <= len2 - len1; i++) {
        int match = 1; // 假设找到了匹配的子字符串
        for (int j = 0; j < len1; j++) {
            if (str2[i + j] != str1[j]) {
                match = 0; // 如果有任何字符不匹配，那么这不是匹配的子字符串
                break;
            }
        }
        if (match) {
            printf("%d ", i); // 输出匹配子字符串的起始位置
            found = 1; // 标记已找到匹配的子字符串
        }
    }

    if (!found) {
        printf("-1"); // 如果没有找到匹配的子字符串，输出-1
    }

    printf("\n"); // 打印换行符
    return 0;
}
