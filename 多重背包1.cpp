#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1000000;

int f[N];
int w[N],v[N];
int n,m;
int weight,value,num;
int idx =0;
//�����㷨������01����������� 
//��һ��.ͨ���ı�����w��v�����뷽ʽ
//�������ݹ���ʱ����Ҫ���ж������Ż� 
//�ڶ���.�ڸ�����������ټ�һ��ѭ����
/*
	for(int z=1;z<=num&&z*w[i]<=j;z++){
		f[j] = max(f[j],f[j-z*w[i]]+z*v[i]);
	}
	������ʾ��i����Ʒѡȡ��������� 
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
