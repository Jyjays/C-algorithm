#include <stdio.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char* s) {
    if (s[0] == '\0') {
        return 0;
    }
    int maxLen = 1;
    int l = 0, r = 1;
    while (s[r] != '\0') {
        
    }
    return maxLen;
}

int main(){
    int n;
    scanf("%d",&n);
    char *s = (char*)malloc(sizeof(char) * n);
    for(int i=0;i<n;i++) {
        scanf("%c", &s[i]);
    }

    int res = lengthOfLongestSubstring(s);
    printf("%d",res);
    free(s);
    return 0;
}