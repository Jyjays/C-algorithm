#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 排序方法会超时
// vector<int> findAnagrams(string s, string p) {
//     vector<int> res;
//     int slen = s.size();
//     int plen = p.size();
//     string tmp = p;
//     sort(tmp.begin(),tmp.end());
//     if (slen < plen) {
//         return res;
//     }
//     for (int i = 0;i <= slen - plen;i ++) {
//         string substr = s.substr(i,plen);
//         sort(substr.begin(),substr.end());
//         if (substr == tmp) {
//             res.push_back(i);
//         }
//     }

//     return res;
// }

vector<int> findAnagrams(string s, string p) {
  vector<int> res;
  int slen = s.size();
  int plen = p.size();
  if (slen < plen) {
    return res;
  }
  vector<int> smap(26);
  vector<int> pmap(26);
  for (int i = 0; i < plen; i++) {
    pmap[p[i] - 'a']++;
  }
  // int l = 0, r = plen - 1;
  // for (int i = l;i <= r; i++) {
  //     smap[s[i] - 'a'] ++;
  // }
  // while (r < slen) {
  //     if (smap == pmap) {
  //         res.push_back(l);
  //     }
  //     smap[s[l++] - 'a']--;
  //     smap[s[++r] - 'a']++;
  // }
  for (int i = 0; i < plen; i++) {
    smap[s[i] - 'a']++;
  }
  for (int i = 0; i < slen - plen; i++) {
    if (smap == pmap) {
        res.push_back(i);
    }
    smap[s[i]]--;
    if (i < slen - plen) {
        smap[s[i + plen]] ++;
    }
    
  }
  return res;
}

// C 实现方法
// int* findAnagrams(char* s, char* p, int* returnSize) {
//     int* ans = malloc(strlen(s) * sizeof(int));
//     *returnSize = 0;
//     int cnt_p[26] = {}; // 统计 p 的每种字母的出现次数
//     int cnt_s[26] = {}; // 统计 s 的长为 n 的子串 s' 的每种字母的出现次数
//     int n = 0;
//     for (; p[n]; n++) {
//         cnt_p[p[n] - 'a']++; // 统计 p 的字母
//     }
//     for (int right = 0; s[right]; right++) {
//         cnt_s[s[right] - 'a']++; // 右端点字母进入窗口
//         int left = right - n + 1;
//         if (left < 0) { // 窗口长度不足 n
//             continue;
//         }
//         if (memcmp(cnt_s, cnt_p, sizeof(cnt_s)) == 0) { // s' 和 p 的每种字母的出现次数都相同
//             ans[(*returnSize)++] = left; // s' 左端点下标加入答案
//         }
//         cnt_s[s[left] - 'a']--; // 左端点字母离开窗口
//     }
//     return ans;
// }


int main() {
  string s, p;
  cin >> s >> p;
  vector<int> res = findAnagrams(s, p);
  for (auto i : res) {
    cout << i << " ";
  }
  return 0;
}
