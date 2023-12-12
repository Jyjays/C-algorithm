#include<iostream>
#include<cstring>

#include<map>

using namespace std;

map<map<int,int>,int > M;
int main(){
    ios::sync_with_stdio(false);
  

    map<int, map<int, int>> M;
   
        ios::sync_with_stdio(false);
        int n,m;
        cin>>n;
        for(int i=0;i<n;i++){
            int DN,p;
            cin >> DN >> p; // Initialize DN and p
            for(int j=0;j<p;j++){ // Fix the loop condition from 'i' to 'j'
                int a,b;
                cin>>a>>b;
                M[a][DN]=b;
            }
        }
        cin>>m;
        string op;
        for(int i=0;i<m;i++){
            cin >> op;
            if (op[1] == ':' || op[1] == '~') {
                int pro = op[0] - '0';
                int data = op[2] - '0';
                if (op[1] == ':') {
                    if (M.find(pro)->second.find(data) != M.find(pro)->second.end()) {
                        int res = M.find(pro)->second.find(data)->second;
                        cout << res << endl;
                    }
                } else if (M.find(pro)->second.find(data) != M.find(pro)->second.end()) {
                    int res = M.find(pro)->second.find(data)->second;
                    cout << res << endl;
                }
            }
            }
        
        return 0;
    }
