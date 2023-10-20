#include <iostream>
#include <vector>
#include <string>
using namespace std;

string a, b;

vector<int> num1, num2, res;

// 辅助函数：比较两个数字的大小
// 如果 num1 大于等于 num2，返回 true，否则返回 false
bool Compare(vector<int>& num1, vector<int>& num2) {
    if (num1.size() > num2.size()) {
        return true;
    } else if (num1.size() < num2.size()) {
        return false;
    } else {
        for (int i = num1.size() - 1; i >= 0; i--) {
        	if(num1[i]!=num2[i]) {
				//只需要比较最先出现的不同的位数 
            	if (num1[i] > num2[i]) {
           	    	return true;
          	    } else if (num1[i] < num2[i]) {
                	return false;
            }
        }
		} 
        return true; // 两数相等时也返回 true
    }
}

void Subtract(vector<int>& num1, vector<int>& num2, vector<int>& result) {
    int borrow = 0;
    int n1 = num1.size();
    int n2 = num2.size();
    
    for (int i = 0; i < max(n1, n2); i++) {
        int digit1 = (i < n1) ? num1[i] : 0;
        int digit2 = (i < n2) ? num2[i] : 0;
        
        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        
        result.push_back(diff);
    }
    
    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }
}

int main() {
    cin >> a >> b;
    
    for (int i = a.size() - 1; i >= 0; i--) {
        num1.push_back(a[i] - '0');
    }
    
    for (int i = b.size() - 1; i >= 0; i--) {
        num2.push_back(b[i] - '0');
    }
    
    bool isNegative = false;
    
    if (!Compare(num1, num2)) {
        swap(num1, num2);
        isNegative = true;
    }
    
    Subtract(num1, num2, res);
    
    if (isNegative) {
        cout << "-";
    }
    
    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i];
    }
    
    return 0;
}

