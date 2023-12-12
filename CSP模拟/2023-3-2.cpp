#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int,int>> days;



int main(){
    ios::snyc_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    int a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        days.push_back(make_pair(a,b));
    }
    
}