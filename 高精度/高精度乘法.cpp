#include<iostream>

#include<vector>

#include<string>
using namespace std;

string a;
vector<int> num1;
int num2;

vector<int> mul(vector<int>& num1,int num2){
	
	int up = 0;
	vector<int> res;
	if(!num2) {
		res.push_back(0);
		return res;
	}
	for(int i =0;i<num1.size() || up;i++){ 
	//循环条件很重要，当i = num1.size()-1时，up中很可能还存有进位的数据 
		if(i<num1.size())up += num1[i]*num2;
		res.push_back(up%10);
		up/=10;
	}
	return res;
}

int main(){
	cin>>a>>num2;
	for(int i = a.size()-1;i>=0;i--){
		num1.push_back(a[i]-'0');
	}
	vector<int> res = mul(num1,num2);
	for(int i =res.size()-1;i >=0;--i){
		cout<<res[i];
	} 
	return 0;
} 
