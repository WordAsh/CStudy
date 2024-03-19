#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n); // 读取矩阵的大小

    int matrix[100][100]; // 声明矩阵

    // 读取矩阵数据
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // 寻找鞍点
    int found = 0; // 标记是否找到鞍点
    for (int i = 0; i < n; i++) {
        int max = matrix[i][0];
        int colIndex = 0;
        // 寻找第i行的最大元素
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
                colIndex = j;
            }
        }

        // 检查这个元素是否是其所在列的最小元素
        int isMin = 1; // 假设它是最小的
        for (int k = 0; k < n; k++) {
            if (matrix[k][colIndex] < max) {
                isMin = 0; // 发现更小的元素，它不是最小的
                break;
            }
        }

        // 如果找到鞍点
        if (isMin) {
            printf("%d %d\n", i, colIndex); // 输出鞍点的位置
            found = 1;
            break; // 题目说明只有一个鞍点
        }
    }

    if (!found) {
        printf("NO\n"); // 没有找到鞍点
    }

    return 0;
}
