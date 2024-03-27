#include <stdio.h>
#include <string.h>

int main() {
    char line[81];  // 假设每行最多80个字符，+1 是为了放置字符串结束符 '\0'
    int totalLines = 0;  // 朋友信息总条数
    int keywordLines = 0;  // 包含关键词的信息条数
    int firstKeywordLine = 0;  // 第一次出现关键词的行号
    const char *keyword = "chi1 huo3 guo1";  // 要搜索的关键词

    while (fgets(line, sizeof(line), stdin)) {
        // 如果只有一个英文句点，则停止读取
        if (line[0] == '.' && line[1] == '\n') {
            break;
        }

        totalLines++;  // 增加信息条数

        // 查找关键词
        if (strstr(line, keyword)) {
            keywordLines++;  // 增加包含关键词的信息条数
            if (firstKeywordLine == 0) {  // 如果是第一次找到关键词
                firstKeywordLine = totalLines;  // 记录行号
            }
        }
    }

    // 输出朋友信息的总条数
    printf("%d\n", totalLines);

    // 检查是否有包含关键词的信息
    if (keywordLines > 0) {
        printf("%d %d\n", firstKeywordLine, keywordLines);  // 输出第一次出现的行号和总数
    } else {
        printf("-_-#\n");  // 如果没有找到关键词，输出表情
    }

    return 0;
}