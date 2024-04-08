#include<iostream>

using namespace std;

int main(){
    int (*a[3]) = {new int(1),new int(2),new int(3)};
    // cout<<*a[0]<<endl;
    // cout<<a[1]<<endl;

    int *a2[3] = {new int(1),new int(2),new int(3)};
    int (*a3)[3];
    cout<<sizeof(a3)<<endl; 
    a3 = new int[3][3];
    cout<<sizeof(a3)<<endl;

    return 0;

 }