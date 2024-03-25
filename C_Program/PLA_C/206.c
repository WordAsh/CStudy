#include <stdio.h>
#include <string.h>

void processString(const char *input, char *result) {
    int len = strlen(input);
    int idx = 0;
    for (int i = 1; i < len; i++) {
        if ((input[i] - '0') % 2 == (input[i-1] - '0') % 2) {
            result[idx++] = input[i] > input[i-1] ? input[i] : input[i-1];
        }
    }
    result[idx] = '\0';  // 确保结果字符串以空字符终止
}

int main() {
    char a[10001] = {0}, b[10001] = {0}, ar[10001] = {0}, br[10001] = {0};

    if (fgets(a, sizeof(a), stdin) != NULL) {
        a[strcspn(a, "\n")] = '\0';
    }

    if (fgets(b, sizeof(b), stdin) != NULL) {
        b[strcspn(b, "\n")] = '\0';
    }

    processString(a, ar);
    processString(b, br);

    if (strcmp(ar, br) == 0) {
        printf("%s\n", ar);
    } else {
        printf("%s\n%s\n", ar, br);
    }

    return 0;
}
