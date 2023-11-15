#include<iostream>
#include<vector>

using namespace std;

vector<pair<int,int>> M;

void oper(int& x,int& y,int id){
	int opid = M[id].first();
	if(id==1){
		x = x*M[id].second();
	}
	
}

int main(){
	return 0;
}
