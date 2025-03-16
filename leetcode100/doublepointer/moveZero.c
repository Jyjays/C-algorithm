#include "stdio.h"
#include "stdlib.h"




// void moveZeroes(int* nums, int numsSize) {
//     for (int i = 0; i < numsSize; i ++){
//         if (nums[i] != 0) {
//             continue;
//         }
//         for (int j = i + 1; j < numsSize; j++) {
//             // Find the first num which is not zero.
//             if (nums[j] != 0) {
//                 // swap(nums,i,j);
//                 nums[i] = nums[j];
//                 nums[j] = 0;
//                 break;
//             }
//         }
//     }
// }

void moveZeroes(int* nums, int numsSize) {
    // 单层循环解法
    int slow = 0, fast = 0;
    while (fast < numsSize) {
        if (nums[fast] != 0) {
            nums[slow++] = nums[fast++]; 
        } else {
            fast ++;
        }
    }
    while (slow < numsSize) {
        nums[slow] = 0;
    }
}

int main() {
    int numSize;
    
    scanf("%d",&numSize);
    int *nums = (int*)malloc(numSize * sizeof(int));
    for (int i=0;i<numSize;i++){
        scanf("%d", &nums[i]);
    }
    moveZeroes(nums,numSize);
    for (int i = 0;i<numSize;i++ ){
        printf("%d ",nums[i]);
    }
    return 0;

}