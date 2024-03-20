#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

class BigNum
{
private:
    bool flag;
    int len;
    int num[210];

public:
    BigNum()
    {
        flag = true;
        len = 0;
        memset(num, 0, sizeof(num)); // 使用memset初始化数组为0
    }
    bool operator<(const BigNum &num2) const
    {
        if (len != num2.len)
            return len < num2.len;
        if (flag != num2.flag)
            return !flag;
        bool cmp = false;
        for (int i = len - 1; i >= 0; i--)
        {
            if (num[i] == num2.num[i])
                continue;
            else
            {
                return num[i] < num2.num[i];
            }
        }
        return false;
    }
    BigNum operator-(const BigNum &num2) const
    {
        BigNum res;
        int n1[210];
        for (int i = 0; i < this->len; i++)
            n1[i] = num[i];
        int size = max(this->len, num2.len);
        for (int i = 0; i < size; i++)
        {
            if (n1[i] < num2.num[i])
            {
                n1[i] += 10;
                n1[i + 1]--;
            }
            res.num[res.len++] = n1[i] - num2.num[i];
        }
        while (res.len >= 1 && res.num[res.len - 1] == 0)
        {
            res.len--;
        }
        return res;
    }
    BigNum operator+(const BigNum &num2) const
    {
        BigNum res;
        int carry = 0;
        for (int i = 0; i < max(len, num2.len); i++)
        {
            int temp = num[i] + num2.num[i] + carry;
            res.num[res.len++] = temp % 10;
            carry = temp / 10;
        }
        if (carry)
        {
            res.num[res.len++] = carry;
        }
        return res;
    }
    BigNum operator*(BigNum &b)
    {
        BigNum res;
        BigNum bn[120];

        for (int i = 0; i < b.len; i++)
        {
            int now = b.num[i];
            bn[i].len = i;
            int carry = 0;
            for (int j = 0; j < len; j++)
            {
                int temp = num[j] * now + carry; // 修正变量名
                bn[i].num[bn[i].len++] = temp%10; 
                carry = temp / 10;
            }
            while (carry)
            {
                bn[i].num[bn[i].len++] = carry%10; // 修正写入的值
                carry /= 10;
            }
        }
        for(int i=0;i<120;i++) res = res + bn[i];
        return res;
    }
    BigNum operator*(int b){
        BigNum res;
        int carry = 0;
        for(int i=0;i<len;i++){
            int temp = num[i]*b+carry;
            res.num[res.len++] = temp%10;
            carry = temp/10;
        }
        while(carry){
            res.num[res.len++] = carry%10;
            carry /= 10;
        }
        return res;
    }
    bool operator == (BigNum &b) const {
        if(len!=b.len) return false;
        for(int i=0;i<len;i++){
            if(num[i]!=b.num[i]) return false;
        }
        return true;
    }
    bool operator<= (BigNum &b) const {
        if(len<b.len) return true;
        if(len>b.len) return false;
        for(int i=len-1;i>=0;i--){
            if(num[i]<b.num[i]) return true;
            if(num[i]>b.num[i]) return false;
        }
        return true;
    }
    BigNum operator/(BigNum &b) const {
        BigNum res;
        BigNum temp;
        for(int i=len-1;i>=0;i--){
            temp = temp*10;
            temp.num[0] = num[i];
            while(b<=temp){
                temp = temp - b;
                res.num[i]++;
                if(temp.len==1&&temp.num[0]==0) break;
            }
        }
        while(res.len>=1&&res.num[res.len-1]==0) res.len--;
        return res;
    }
    friend ostream &operator<<(ostream &output, BigNum &b)
    {
        if (b.flag == false)
            output << "-";
        for (int i = b.len - 1; i >= 0; i--)
        {
            output << b.num[i];
        }
        return output; // 移除额外的换行符
    }
    friend istream &operator>>(istream &input, BigNum &b)
    {
        string s;
        input >> s;
        int start = 0;
        if (s[0] == '-')
        {
            b.flag = false;
            start = 1;
        }
        b.len = s.size() - start; // 修正长度计算
        for (int i = 0, j = s.size() - 1; i < b.len && j >= start; i++, j--)
        {
            b.num[i] = s[j] - '0'; // 修正写入的值
        }
        return input;
    }
};

int main()
{
    BigNum n1, n2, n3, n4;
    cin >> n1 >> n2;
    n3 = (n1 < n2) ? n2 - n1 : n1 - n2;
    n4 = n1 + n2;
    BigNum n5 = n4/n3;
    cout << n5;
    return 0;
}
