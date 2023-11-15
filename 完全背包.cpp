#include<iostream>

#include<algorithm>
#include<cstring>

using namespace std;

const int N = 1010;

int n,m;

int f[N],value[N],weight[N];

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>weight[i]>>value[i];
	}
	for(int i =1;i<=n;i++){
		for(int j=weight[i];j<=m;j++){
		
			f[j] = max(f[j],f[j-weight[i]]+value[i]); 	
		
			
		}
}
	cout<<f[m];
	return 0; 
} 
