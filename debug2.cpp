#include<iostream>
#include<cstring>

using namespace std;


int main(){
    string s = "()))";
    cout<<s.insert(1,1,')');
    cout<<endl<<s<<endl;
    return 0; 
}