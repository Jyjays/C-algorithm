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
        *num = {0};
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
                int temp = num[i] * now + temp;
                res.num[res.len++] = temp % 10;
                carry = temp / 10;
            }
            while (carry)
            {
                res.num[res.len++] = carry;
            }
        }

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
        output << endl;
        return output;
    }
    friend istream &operator>>(istream &input, BigNum &b)
    {
        string s;
        input >> s;
        if (s[0] == '-')
        {
            b.flag = false;
            for (int i = 0, j = s.size() - 1; i < s.size() - 1 && j > 0; i++, j--)
            {
                b.num[i] = s[i] - '0';
            }
        }
        else
        {
            for (int i = 0, j = s.size() - 1; i < s.size() - 1 && j >= 0; i++, j--)
            {
                b.num[i] = s[i] - '0';
            }
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
    BigNum n5 = n3*n4;
    cout<<n5;
    return 0;
}