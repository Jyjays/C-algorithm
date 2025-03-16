#include "stdlib.h"
#include "string.h"
#include <stdio.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_SINGLE_STR_LEN 100
#define MAX_STR_COUNT 10000
typedef struct {
    int index;
    char *str;
} SingleStr;

int cmp_char(const void *a, const void *b)
{
    return *(char *)a - *(char *)b;
}

int cmp_dictionary(const void *a, const void *b)
{
    return strcmp(((SingleStr *)a)->str, ((SingleStr *)b)->str);
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    /* arrays sort in dictionary*/
    char buf[strsSize][MAX_SINGLE_STR_LEN];
    SingleStr *strBuf = (SingleStr *)malloc(sizeof(SingleStr) * strsSize);
    for (int i = 0; i < strsSize; i++) {
        strcpy(buf[i], strs[i]);
        strBuf[i].index = i;
        strBuf[i].str = buf[i];
        qsort(strBuf[i].str, strlen(strBuf[i].str), sizeof(char), cmp_char);
    }
    qsort(strBuf, strsSize, sizeof(SingleStr), cmp_dictionary);

    /* malloc retStr memory and retColSize memory */
    int rowNum = 0, colNum = 0;
    *returnColumnSizes = (int *)malloc(sizeof(int) * strsSize);
    char ***retStr = (char ***)malloc(sizeof(char **) * strsSize);

    retStr[rowNum] = (char **)malloc(sizeof(char *) * strsSize);
    int left = 0;
    for (int right = 0; right < strsSize; right++) {
        if (!strcmp(strBuf[left].str, strBuf[right].str)) { /* Inter loop if arrays compare quel. */
            retStr[rowNum][colNum] = (char *)malloc(strlen(strs[strBuf[right].index]) + 1);
            strcpy(retStr[rowNum][colNum], strs[strBuf[right].index]);
            colNum++;
            continue;
        }
        (*returnColumnSizes)[rowNum] = colNum;
        left = right;

        /* create new column and new rowStr*/
        colNum = 0;
        rowNum++;
        retStr[rowNum] = (char **)malloc(sizeof(char *) * strsSize);
        retStr[rowNum][colNum] = (char *)malloc(strlen(strs[strBuf[right].index]) + 1);
        strcpy(retStr[rowNum][colNum], strs[strBuf[right].index]);
        colNum++;
    }
    (*returnColumnSizes)[rowNum] = colNum;
    rowNum++;

    *returnSize = rowNum;
    free(strBuf);
    return retStr;
}

int main() {
    char **strs = NULL;
    char buffer[MAX_SINGLE_STR_LEN];
    int count = 0;

    while(1){
        if(fgets(buffer,MAX_SINGLE_STR_LEN,stdin) == NULL) {
            break;
        }

        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n'){
            buffer[len -1] = '\0';
        }

        if (strlen(buffer) == 0) {
            break;
        }

        char* line = strdup(buffer);
        strs = (char**)realloc(strs,(count+1)*sizeof(char*));
        strs[count++] = line;
    }
    int rowNum = 0;
    int* columSize = (int*)malloc(count * sizeof(int));
    char*** res = groupAnagrams(strs,count,&rowNum,&columSize);
    for (int i = 0;i<rowNum;i++){
        for (int j = 0;j<columSize[i];j++) {
            printf("%s,",res[i][j]);
        }
        printf("\n");
    }

    for(int i=0;i<count;i++) free(strs[i]);
    free(strs);
    free(columSize);
    return 0;
}