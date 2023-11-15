#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1000000;

int f[N];
int w[N],v[N];
int n,m;
int weight,value,num;
int idx =0;
//朴素算法，基于01背包问题改造 
//第一种.通过改变数组w和v的输入方式
//但当数据过大时，需要进行二进制优化 
//第二种.在更新语句那里再加一重循环即
/*
	for(int z=1;z<=num&&z*w[i]<=j;z++){
		f[j] = max(f[j],f[j-z*w[i]]+z*v[i]);
	}
	暴力表示第i个物品选取个数的情况 
*/ 
int main(){
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin>>weight>>value>>num;
		for(int j =0;j<num;j++){
			idx++; 
			w[idx]= weight;
			v[idx]= value;
			
		}
	}
	for(int i=1;i<=idx;i++){
		for(int j=m;j>=w[i];j--){
			
			f[j] = max(f[j],f[j-w[i]]+v[i]);
		}
	}
	
	int res = 0;
	for(int i=0;i<=m;i++){
		res = max(res,f[i]);
	}
	cout<<res;
	return 0;
}
