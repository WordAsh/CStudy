#include <stdio.h>

int main() {
    char ch;
    int len = 0; // 初始化单词长度计数器

    while (scanf("%c", &ch) && ch != '.') { // 读取字符直到遇到冒号
        if (ch == ' ') { // 遇到空格
            if (len > 0) { // 如果当前单词长度不为0，则输出单词长度
                printf("%d ", len);
                len = 0; // 重置单词长度计数器
            }
        } else { // 遇到非空格字符
            len++; // 增加当前单词的长度
        }
    }

    if (len > 0) { // 如果最后一个单词后没有空格，则输出最后一个单词的长度
        printf("%d", len);
    }

    return 0;
}
