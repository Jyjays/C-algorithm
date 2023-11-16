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
��n����ͬ����Ʒ���n�� 
�������Ż���
	��������һ����n��1��n��Χ�ڵ���������������С��������ɸ�����ʾ������ΪѰ���ձ���ɣ�����ϲ����log2n��Ѱ��
	���磺n=7, ���Բ��1��2��4  7=1+2+4��6=2+4....
	���ڲ���2��n�η�����������������ķ���
	n-2^0-2^1-2^2-....=�� 
	�����ϵļ��������ó��Ĳ�Ϳ��Ա�ʾn�������е����� 
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
