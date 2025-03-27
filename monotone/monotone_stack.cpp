#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
int n ;

int main () {
    cin >> n;
    stack<int> s;
    
    int tmp;
    for (int i = 0; i< n; i++) {
        cin >> tmp;
        while (!s.empty() && s.top() >= tmp) {
            s.pop();
        } 
        if (!s.empty()) cout << s.top() << " ";
        else cout << -1 << " ";
        s.push(tmp);
    }
    return 0;

}