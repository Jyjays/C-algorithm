#include "stdlib.h"
#include "stdio.h"


#define LENGTH 100000

int Max(int a,int b) {
    return a > b ? a : b;
}
int cmp(const void* a,const void* b) {
    return *(int*) a - *(int*)b;
}

int longestConsecutive(int* nums, int numsSize) {
    qsort(nums,numsSize,sizeof(int),cmp);
    int maxLen = 1;
    int curr_len = 1;
    for (int i=1;i<numsSize;i++){
        if (nums[i] == nums[i-1] + 1) {
            curr_len ++;
        } else if(nums[i] == nums[i-1]){
            
        } else {
            maxLen = Max(maxLen,curr_len);
            curr_len = 1;
        }

        if (i == numsSize - 1) {
            maxLen = Max(maxLen,curr_len);
        }
    }
    return maxLen;
}
int main() {
    int num[LENGTH];
    int count ;
    scanf("%d",&count);
    for (int i=0;i<count;i++) {
        scanf("%d",&num[i]);
    }
    int res = longestConsecutive(num,count);
    printf("%d",res);
    return 0;
}