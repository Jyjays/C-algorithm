#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

vector<vector<int>> q;
vector<vector<int>> k;
vector<vector<int>> v; 


vector<int> get_row(const vector<vector<int>>& matrix, int row) {
    return matrix[row];
}

vector<int> get_column(const vector<vector<int>>& matrix, int column) {
    vector<int> col;
    for (const auto& row : matrix) {
        col.push_back(row[column]);
    }
    return col;
}

int dot_product(const vector<int>& a, const vector<int>& b) {
    int ans = 0;
    for (int i = 0; i < a.size(); i++) {
        ans += a[i] * b[i];
    }
    return ans;
}

vector<vector<int>> matrix_multiply(const vector<vector<int>>& a, const vector<vector<int>>& b) {
    int n = a.size();
    int m = a[0].size();
    int p = b[0].size();
    vector<vector<int>> result(n, vector<int>(p, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            vector<int> row = get_row(a, i);
            vector<int> column = get_column(b, j);
            result[i][j] = dot_product(row, column);
        }
    }
    return result;
}

vector<vector<int>> matrix_transposition(vector<vector<int>>& a) {
    int n = a.size();
    int m = a[0].size();
    vector<int> temp(n, 0);
    vector<vector<int>> result(m, temp);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j ++) {
            result[i][j] = a[j][i];
        }
    }
    return result;
}


vector<vector<int>> w;
int main() {
    int n, m;
    cin >> n >> m;
    int x;
    for (int i = 0; i < n; i++) {
        vector<int> temp;
        q.push_back(temp);
        for (int j = 0; j < m; j++) {
            cin >> x;
            q[i].push_back(x);  
        }
    }
    for (int i = 0; i < n; i++) {
        vector<int> temp;
        k.push_back(temp);
        for (int j = 0; j < m; j++) {
            
            cin >> x;
            k[i].push_back(x);  
        }
    }
    for (int i = 0; i < n; i++) {
        vector<int> temp;
        v.push_back(temp);
        for (int j = 0; j < m; j++) {
            cin >> x;
            v[i].push_back(x); 
        }
    }
    for(int i= 0;i<n;i++){
        vector<int> temp;
        w.push_back(temp);
        cin>>x;
        w[i].push_back(x);
    }

    vector<vector<int>> kt = matrix_transposition(k);
    vector<vector<int>> qkt = matrix_multiply(q, kt);
    vector<vector<int>> wqkt = matrix_multiply(w, qkt);
    vector<vector<int>> wqktv = matrix_multiply(wqkt, v);
    for(int i=0;i<wqktv.size();i++){
        for(int j=0;j<wqktv[0].size();j++){
            cout<<wqktv[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// #include <iostream>

// using namespace std;
// typedef long long LL;
// const int N = 10010, D = 30;
// LL tmp[D][D], ans[N][N];
// int n, d;
// int Q[N][D], K[N][D], V[N][D], W[N];
// int main()
// {
//     cin >> n >> d;
//     for (int i = 1; i <= n; i ++)
//         for (int j = 1; j <= d; j ++)
//             cin >> Q[i][j];
//     for (int i = 1; i <= n; i ++)
//         for (int j = 1; j <= d; j ++)
//             cin >> K[i][j];
//     for (int i = 1; i <= n; i ++)
//         for (int j = 1; j <= d; j ++)
//             cin >> V[i][j];
//     for (int i = 1; i <= n; i ++) cin >> W[i];
    
// 	// 计算 K的转置 * V = tmp
//     for (int i = 1; i <= d; i ++)
//         for (int j = 1; j <= d; j ++)
//             for (int k = 1; k <= n; k ++)
//                 tmp[i][j] += K[k][i] * V[k][j];
                
//     // 计算 Q * tmp = ans
//     for (int i = 1; i <= n; i ++)
//         for (int j = 1; j <= d; j ++)
//         {
//             for (int k = 1; k <= d; k ++)
//                 ans[i][j] += Q[i][k] * tmp[k][j];
//             ans[i][j] *= (LL) W[i];
//         }
        
//     for (int i = 1; i <= n; i ++)
//     {
//         for (int j = 1; j <= d; j ++)
//             cout << ans[i][j] << " ";
//         cout << endl;
//     }
//     return 0;
// }