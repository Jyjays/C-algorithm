#include<iostream>
using namespace std;

int main() {
    int count = 0;
    int l,r;
    cin >> l >> r;
    for (size_t i = l; i <= r; i++)
    {
        if(i % 2 != 0 || i % 4 == 0) count++;
    }
    
    // while (cin >> num) {
    //     if (num / 2 != 0 || num % 4 == 0) {
    //         count++;
    //     }
    //     if(cin.get() == '\n') break;

    // }

    cout << count << endl;
    return 0;
}
