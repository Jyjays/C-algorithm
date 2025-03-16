#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1000

int main() {
    char buffer[MAX_LINE_LEN];
    char **lines = NULL;  // 存储所有行的指针数组
    int line_count = 0;

    printf("输入多行内容（空行结束）:\n");
    
    while (1) {
        if (fgets(buffer, MAX_LINE_LEN, stdin) == NULL) {
            break;  // 处理输入结束或错误
        }

        // 去除末尾的换行符（如果有）
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }

        // 检查是否为空行
        if (strlen(buffer) == 0) {
            break;  // 空行结束输入
        }

        // 动态分配内存保存行内容
        char *line = strdup(buffer);
        if (line == NULL) {
            perror("内存分配失败");
            exit(EXIT_FAILURE);
        }

        // 扩展指针数组
        lines = (char**)realloc(lines, (line_count + 1) * sizeof(char*));
        lines[line_count++] = line;
    }

    // 打印所有行
    printf("输入的 %d 行内容:\n", line_count);
    for (int i = 0; i < line_count; i++) {
        printf("%s\n", lines[i]);
        free(lines[i]);  // 释放每行内存
    }
    free(lines);  // 释放指针数组

    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define MAX_INPUT_LEN 10000

// int main() {
//     char input[MAX_INPUT_LEN];
//     char **tokens = NULL;  // 存储所有分割后的字符串
//     int token_count = 0;

//     printf("输入内容（空格分隔）:\n");
    
//     if (fgets(input, MAX_INPUT_LEN, stdin) == NULL) {
//         perror("输入错误");
//         exit(EXIT_FAILURE);
//     }

//     // 去除末尾的换行符
//     size_t len = strlen(input);
//     if (len > 0 && input[len - 1] == '\n') {
//         input[len - 1] = '\0';
//     }

//     // 使用 strtok 分割字符串
//     char *token = strtok(input, " \t");  // 支持空格和制表符分隔
//     while (token != NULL) {
//         // 动态分配内存保存每个分割后的字符串
//         char *copy = strdup(token);
//         if (copy == NULL) {
//             perror("内存分配失败");
//             exit(EXIT_FAILURE);
//         }

//         // 扩展指针数组
//         tokens = realloc(tokens, (token_count + 1) * sizeof(char*));
//         tokens[token_count++] = copy;

//         token = strtok(NULL, " \t");
//     }

//     // 打印所有分割后的内容
//     printf("分割后的 %d 个元素:\n", token_count);
//     for (int i = 0; i < token_count; i++) {
//         printf("%s\n", tokens[i]);
//         free(tokens[i]);  // 释放每个元素内存
//     }
//     free(tokens);  // 释放指针数组

//     return 0;
// }

// #include <stdio.h>
// #define MAX_N 1000  // 假设最多读取1000个数字

// int main() {
//     int nums[MAX_N], n = 0;
//     while (scanf("%d", &nums[n]) == 1) {
//         n++;
//     }
    
//     // 此时nums[0]到nums[n-1]是读取的数字
//     for (int i = 0; i < n; i++) {
//         printf("%d ", nums[i]);
//     }
//     return 0;
// }
