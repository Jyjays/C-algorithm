//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//const int N = 8;
//
//struct Situ{
//	char a[N][N];
//	int count =0;
//};
//
//vector<Situ> situs;
//
//int n;
//
//bool eq(char a[][N],char b[][N]){
//	for(int i=0;i<N;i++){
//		for(int j=0;j<N;j++){
//			if(a[i][j]!=b[i][j]){
//				return false;
//			}
//		}
//	}
//	return true;
//}
//
//int main(){
//	cin>>n;
//	for(int i=0;i<n;i++){
//		Situ s;
//		for(int j = 0;j<N;j++){
//			for(int k = 0;k<N;k++){
//				cin>>s.a[j][k];	
//			}
//		}
//		situs.push_back(s);
//	}	
//	for(int i =0 ;i<situs.size();i++){
//		for(int j = i;j>=0;j--){
//			if(eq(situs[i].a,situs[j].a)){
//				situs[i].count = situs[j].count+1;
//			}
//		}
//		if(i>0) cout<<endl;
//		cout<<situs[i].count;
//	}
//	return 0;
//}

#include<iostream>
#include<map>
#include<string>
using namespace std;
char str[64];
map<string,int> m;

int n;
int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<64;j++){
			cin>>str[j];
		}
		if(m.count(str)){
			m[str]++;
		}
		else{
			m[str] = 1;
		}
		cout<<m[str]<<endl;
	}

	return 0;
}

 
