#include <bits/stdc++.h>
using namespace std;

const int mo = 1e9+7; // 定义模数为10^9 + 7

// 定义一些常量用于标识节点类型
#define CONST -1
#define VAR -2
#define OP -3

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    int n, m;
    cin >> n >> m; // 读取变量数量 n 和查询数量 m
    getline(cin, s); // 读取换行符
    getline(cin, s); // 读取整个表达式
    istringstream qwq(s); // 使用字符串流解析表达式
    vector<int> l, r, info, kind; // 分别存储左子节点、右子节点、节点信息和节点类型
    stack<int> id; // 用于构建表达式树的栈
    int node_id = 0; // 节点编号
    
    // 解析表达式，构建表达式树
    while(getline(qwq, s, ' ')){
        if (s.size() == 1 && (s[0] == '+' || s[0] == '*' || s[0] == '-')){
        	//s提取到运算符时 
            int rson = id.top();
            id.pop();
            int lson = id.top();
            id.pop();
            //提取左右两个操作数 
            l.push_back(lson);
            r.push_back(rson);
            info.push_back(s[0]);
            //将运算符存入 
            kind.push_back(OP);
 			//确定为OP类型 
            id.push(node_id);
            //给节点进行编号
			//实际上使用一个栈加左右两边两个vector模拟树 
            ++ node_id;
        }else if (s[0] == 'x'){
        	//提取到"x1""x2"等 
            int x = stoi(s.substr(1));
            -- x;
            l.push_back(-1);
            r.push_back(-1);
            //左右无操作数 
            info.push_back(x);
            kind.push_back(VAR);
 
            id.push(node_id);
            ++ node_id;
        }else{
            int x = stoi(s);
            l.push_back(-1);
            r.push_back(-1);
            info.push_back(x);
            kind.push_back(CONST);
 
            id.push(node_id);
            ++ node_id;
        }
    }
    int root = id.top();
    vector<int> a(n);
 
  // 定义一个递归函数来计算偏导数
    function<array<int, 2>(int, int)> solve = [&](int u, int x){
        if (kind[u] == VAR){
            return array<int, 2>{a[info[u]], (info[u] == x)};
        }else if (kind[u] == CONST){
            return array<int, 2>{info[u], 0};
        }else{
            auto lans = solve(l[u], x), rans = solve(r[u], x);
            int sum = 0, dsum = 0;
            if (info[u] == '+'){
                sum = lans[0] + rans[0];
                dsum = lans[1] + rans[1];
                if (sum >= mo)  sum -= mo;
                if (dsum >= mo) dsum -= mo;
            }else if (info[u] == '-'){
                sum = lans[0] - rans[0];
                dsum = lans[1] - rans[1];
                if (sum >= mo)  sum -= mo;
                if (dsum >= mo) dsum -= mo;
            }else{
                sum = 1ll * lans[0] * rans[0] % mo;
                dsum = (1ll * lans[0] * rans[1] % mo + 1ll * lans[1] * rans[0] % mo);
                if (dsum >= mo) dsum -= mo;
            }
            if (sum < 0)
                sum += mo;
            if (dsum < 0)
                dsum += mo;
            return array<int, 2>{sum, dsum};
        }
    };
    for(int i = 0; i < m; ++ i){
        int x;
        cin >> x;
        -- x;
        for(auto &i : a)
            cin >> i;
        cout << solve(root, x)[1] << '\n';
    }
    return 0;
}
