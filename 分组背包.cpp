#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N =1000010;

int f[N];
struct Good{
	int num;
	vector<int> w;
	vector<int> v;
};
vector<Good> goods;
//统一输入完再进行处理会浪费太多空间，可以在每次输入之后进行一次数据更新 
int n,m,s;
int weight,value;
int main(){
	cin>>n>>m;
	for(int i =0;i<n;i++){
		cin>>s;
		Good good;
		good.num = s;
		for(int j=1;j<=s;j++){
			cin>>weight>>value;
			good.w.push_back(weight);
			good.v.push_back(value);
		}
		goods.push_back(good);
	}
//	for(int i=0;i<n;i++){
//		for(int k=0;k<goods[i].num;k++){
			//错误原因：j层嵌套在最里面，会把问题转化成01背包问题，也就是每件物品选与不选的问题 
//			for(int j=m;j>=goods[i].w[k];j--){
//				f[j] = max(f[j],f[j-goods[i].w[k]]+goods[i].v[k]);
//			}	
//		}
//		
//	}

//正确思路：将对每组物品的循环嵌套在最里面，意思就是对于每个f[j]有num+1种选择，即该组不选，选第1个，
//选第2个......共n+1种情况，也就是多重背包问题 
	for(auto good:goods){
		for(int j =m;j>=0;j--){
			for(int i=0;i<good.num;i++){
				if(j>=good.w[i]){
					f[j] = max(f[j],f[j-good.w[i]]+good.v[i]);
				}
			}
		}
	}
	int res =0;
	for(int i=0;i<=m;i++){
		res = max(res,f[i]);
	}
	cout<<res;
	return 0;
}
//
//int w[N],v[N];
//int main(){
//	cin>>n>>m;
//	for(int i=1;i<=n;i++){
//		cin>>s;
//		for(int k=0;k<s;k++){
//			cin>>w[k]>>v[k];
//		}
//		for(int j =m;j>=0;j--){
//			for(int k=0;k<s;k++){
//				if(j>=w[k]){
//					f[j] = max(f[j],f[j-w[k]]+v[k]);
//				}
//			}
//		}
//	}
//	cout<<f[m];
//	return 0;
//} 
