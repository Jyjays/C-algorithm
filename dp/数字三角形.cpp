#include <iostream>
#include <algorithm>
#include<vector>

using namespace std;

const int N = 10010;

int num[N][N];
int f[N][N];
int n;

vector<vector<int>> generate(int numRows) {
    vector<vector<int> > vecs;
    for(int i =0;i<numRows;i++){
        vector<int> vec;
        vec.push_back(1);
        if(i==1) vecs.push_back(vec);
        else if (i==2){
            vec.push_back(1);
            vecs.push_back(vec);
        }
        else{
            for(int j =1;j<i-1;j++){
                vector<int> temp = vecs.back(); 
                vec.push_back(temp[j-1]+temp[j+1]);
            }
                vec.push_back(1);
                vecs.push_back(vec);
            }
        }
    return vecs;
}

int main(){
    int numRows;
    cin>>numRows;
    vector<vector<int>> res = generate(numRows);
    for(int i =0;i<res.size();i++){
        for(int j =0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
    
}

// int getMax(int x, int y) {
//     if (x == n) return num[x][y];
//     return max(num[x][y] + getMax(x + 1, y), num[x][y] + getMax(x + 1, y + 1));
// }

// int main() {
// 	cin>>n;
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= i; j++) {
//             cin >> num[i][j];
//         }
//     }
//     for(int i=1;i<=n;i++) f[n][i] = num[n][i];
//     for(int i=n-1;i>0;i--){
//     	for(int j=1;j<=i;j++){
//     		f[i][j] = max(f[i+1][j]+num[i][j],f[i+1][j+1]+num[i][j]);
// 		}
// 	} 

//     //int res = getMax(1, 1);
//     cout << f[1][1];
//     return 0;
// }

