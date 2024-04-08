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
//
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
			//����ԭ��j��Ƕ���������棬�������ת����?01�������⣬Ҳ����ÿ����Ʒѡ�벻ѡ������ 
//			for(int j=m;j>=goods[i].w[k];j--){
//				f[j] = max(f[j],f[j-goods[i].w[k]]+goods[i].v[k]);
//			}	
//		}
//		
//	}

//��ȷ˼·������ÿ����Ʒ��ѭ��Ƕ���������棬��˼���Ƕ���ÿ��f[j]��num+1��ѡ�񣬼����鲻ѡ��ѡ��1����
//ѡ��2��......��n+1�������Ҳ���Ƕ��ر�������? 
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
