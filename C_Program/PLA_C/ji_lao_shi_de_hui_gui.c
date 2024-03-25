#include <stdio.h>
#include <string.h>

int main() {
    int N, M;
    scanf("%d %d\n", &N, &M); // 读取题目总数和已完成题目数

    char problem[501];
    int solved = 0; // 已解决题目计数器
    for (int i = 0; i < N; i++) {
        fgets(problem, 501, stdin); // 读取每个题目描述
        problem[strcspn(problem, "\n")] = '\0'; // 移除换行符

        if (solved == M) { // 如果已解决题目数等于M
            if (strstr(problem, "qiandao") == NULL && strstr(problem, "easy") == NULL) {
                printf("%s\n", problem); // 输出当前题目
                return 0;
            }
        }

        // 检查题目是否为签到题
        if (strstr(problem, "qiandao") == NULL && strstr(problem, "easy") == NULL) {
            solved++; // 非签到题，计数器加一
        }
    }

    // 如果所有题目都检查完，吉老师仍未开始做第M题
    if (solved <= M) {
        printf("Wo AK le\n");
    }

    return 0;
}

