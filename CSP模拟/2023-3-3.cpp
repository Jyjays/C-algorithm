#include<iostream>
#include<cstring>

#include<map>

using namespace std;

map<map<int,int>,int> M;
int main(){
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++){
        int DN,p;
        for(int j=0;j<p;i++){
            int a,b;
            cin>>a>>b;
            M[a][DN]=b;
        }
    }
    cin>>m;
    string op;
    for(int i=0;i<m;i++){
        cin>>op;
        if(op[1]==':'||op[1]=='~'){
            int pro = op[0]-'0';
            int data = op[2]-'0';
            if(op[1]==':'){
                if(M.find(pro)->second.find(pro)->second==data){
                    int res = M.find(pro)->second;
                    cout<<res<<endl;
                }
                
            }else{
                if(M.find(pro)->second.find(pro)){
                    int res = M.find(pro)->second;
                    cout<<res<<endl;
                }
            }
        }
    }
    return 0;
}