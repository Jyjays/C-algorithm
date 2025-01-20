#include <iostream>
#include <numeric>
#include <vector>
#include <string>
#include <unordered_map>
#include <array>
using namespace std;

const int N = 10010;
int q[N];

typedef array<int,26> _array;
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        //NOTE - The most simple solution 
        // vector<vector<string>> res;
        // int len = strs.size();
        // if (strs.empty() || len == 1)
        // {
        //     res.push_back(strs);
        //     return res;
        // }
        // for (int i = 0; i < len; i++)
        // {
        //     q[i] = 1;
        // }

        // auto match = [](string str1, string str2) -> bool
        // {
        //     int len1 = str1.length(), len2 = str2.length();
        //     if (len1 != len2)
        //     {
        //         return false;
        //     }
        //     unordered_map<char, int> m1,m2;
        //     for (int i = 0; i < len1; i++)
        //     {
        //         m1[str1[i]]++;
        //     }
        //     for (int i = 0; i < len2; i++)
        //     {
        //         m2[str2[i]]++;
        //     }
        //     return m1 == m2;
        // };
        // auto iter = strs.begin();
        // auto push = [&](int i,vector<string> &v,vector<string>::iterator iter2){
        //     q[i] = 0;
        //     v.push_back(*iter2);
        // };
        // for (int i =0; iter != strs.end(); iter++,i++)
        // {
        //     if (q[i] == 0)
        //     {
        //         continue;
        //     }
        //     vector<string> s;
        //     push(i,s,iter);
        //     auto iter2 = iter + 1;
        //     for (int j=i+1;j<len;j++,iter2++){
        //         if(match(*iter,*iter2)){
        //             push(j,s,iter2);
        //         }
        //     }
        //     res.push_back(s);
        // }
        // return res;

        //NOTE - Custom hash function
        auto arrayHash = [fn = hash<int>{}] (const _array& arr) -> size_t {
            return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
                return (acc << 1) ^ fn(num);
            });
        };
        unordered_map<_array,vector<string>,decltype(arrayHash)> mp(0,arrayHash);
        for (string &str:strs){
            int len = str.length();
            _array count{};
            for (int i=0;i<len;i++){
                count[str[i]-'a'] +=1;
            }
            mp[count].emplace_back(str);
        }
        vector<vector<string>> res;
        for (auto it = mp.begin();it!= mp.end();it++){
            res.emplace_back(it->second);
        }
        return res;
    }
};