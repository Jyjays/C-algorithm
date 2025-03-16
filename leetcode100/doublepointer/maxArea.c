#include "stdio.h"
//#include "stdlib.h"

#define Max(a,b) ((a) > (b) ? (a) : (b))
#define Min(a,b) ((a) < (b) ? (a) : (b))

int n;
int num[10000];


int maxArea(int* height, int heightSize) {
    // int max = 0;
    // for (int i = 0;i< heightSize; i++) {
    //     for (int j = i + 1; j < heightSize; j++) {
    //         printf("%d,%d\n",height[i],height[j]);
    //         max = Max(Min(height[i] ,height[j]) * (j-i), max);
    //     }
    // }
    // return max;
    int max = 0;
    int left = 0, right = heightSize -1;
    while (right > left){
        max = Max(Min(height[left] ,height[right]) * (right-left), max);
        if (height[left] <= height[right]){
            left ++;
        } else {
            right --;
        }
    }
    return max;
}

int main () {

    scanf("%d",&n);
    for (int i=0;i<n;i ++) {
        scanf("%d", &num[i]);
    }
    int res = maxArea(num,n);
    printf("%d",res);
    return 0;
}