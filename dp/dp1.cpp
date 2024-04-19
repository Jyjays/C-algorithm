#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 1010;

int n,m;
//物品数量和背包容量

int f[N],value[N],weight[N];
//容量为n的情况下所能容纳的最大价值，价值数组，容量数组
int main(){
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>weight[i]>>value[i];
	}
	for(int i =1;i<=n;i++){
		//决定物品i选与不选
		for(int j=m;j>=weight[i];j--)
		//因为f数组要依靠小容量的状态来更新，所以j要从大往小循环
		{
			f[j] = max(f[j],f[j-weight[i]]+value[i]); 
		}
	}

	cout<<f[m];
	return 0; 
} 
