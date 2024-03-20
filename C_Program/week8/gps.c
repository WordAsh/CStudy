#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 函数：计算校验和
int calculateChecksum(const char *sentence) {
    int checksum = 0;
    for (const char *p = sentence + 1; *p != '*' && *p; p++) {
        checksum ^= *p;
    }
    return checksum;
}

int main() {
    char line[100];
    int finalHour = 0, finalMinute = 0, finalSecond = 0;

    while (fgets(line, sizeof(line), stdin) && strcmp(line, "END\n") != 0) {
        if (strncmp(line, "GPRMC", 5) == 0) {
            // 提取校验和
            char *checksumStr = strchr(line, '*') + 1;
            int checksum = strtol(checksumStr, NULL, 16);
            // 计算校验和
            if (calculateChecksum(line) == checksum) {
                // 提取UTC时间
                int hour, minute, second;
                sscanf(line + 7, "%2d%2d%2d", &hour, &minute, &second);
                // 转换为北京时间
                hour = (hour + 8) % 24;
                finalHour = hour;
                finalMinute = minute;
                finalSecond = second;
            }
        }
    }

    // 输出最后一条有效记录的北京时间
    printf("%02d:%02d:%02d\n", finalHour, finalMinute, finalSecond);

    return 0;
}
