#include<iostream>
using namespace std;
const int N=10010;
int _x[N],_y[N];
int main(){
	int a,b;
	cin>>a>>b;
	int dx =0,dy = 0;
	int op1,op2;
	for(int i=0;i<a;i++){
		cin>>op1>>op2;
		dx+=op1;dy+=op2; 
	}
	for(int i=0;i<b;i++){
		cin>>_x[i]>>_y[i];
		_x[i]+=dx;_y[i]+=dy;
	}
	for(int i =0 ;i<b;i++){
		cout<<_x[i]<<" "<<_y[i]<<endl; 
	}
	return 0;
} 
