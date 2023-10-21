#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string a;
vector<int> num1;
int num2;
vector<int> resInt;
//vector<int> resDec
int Div(vector<int>& num1,int num2){
	int yushu =0;
	for(int i=0;i<num1.size();i++){
		yushu = yushu*10 + num1[i] ;
		resInt.push_back(yushu/num2);
		yushu %= num2;
	}
	reverse(resInt.begin(),resInt.end());
	while(resInt.back()==0&&resInt.size()>1) resInt.pop_back();
	reverse(resInt.begin(),resInt.end());
	return yushu;
}

int main(){
	cin>>a>>num2;
	for(int i=0;i<a.size();i++){
		num1.push_back(a[i]-'0');
	}
	int yushu = Div(num1,num2);
	//bool flag = false;
	for(int i =0;i<resInt.size();i++){
	//	if(resInt[i]&&resInt.size()>1||resInt.size() == 1) flag = true;
		cout<<resInt[i];
	}
	cout<<endl<<yushu;
	
	return 0;
}

 
