#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 
const int N = 2020;
int n,m;
int f[N];
struct Good{
	int w,v;
}; 
/*
将n件相同的物品拆成n份 
二进制优化：
	给定任意一个数n，1到n范围内的所有数都可以用小于其的若干个数表示出来，为寻找普遍规律，我们喜欢用log2n来寻找
	例如：n=7, 可以拆成1，2，4  7=1+2+4，6=2+4....
	对于不是2的n次方的数，可以用作差的方法
	n-2^0-2^1-2^2-....=差 
	用以上的减数和最后得出的差就可以表示n以内所有的整数 
*/ 
int main(){
	vector<Good> goods;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int weight,value,num;
		cin>>weight>>value>>num;
		for(int k=1;k<=num;k*=2){
			num-=k;
			goods.push_back({k*weight,k*value});
		}
		if(num>0){
			goods.push_back({num*weight,num*value});
		}
	}
	for(auto good: goods){
		for(int j=m;j>=good.w;j--){
			f[j] = max(f[j],f[j-good.w]+good.v);
		}
	}
	cout<<f[m];
	return 0;
}
