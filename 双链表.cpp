#include<iostream>
#include<string>
using namespace std;
const int N = 10010;

int idx, _data[N] , _next[N] , _last[N];

void init(){
	idx = 2;
	_next[0] = 1;
	_last[1] = 0;
} 
//0表示左端点，1表示右端点 
 //idx 从2开始计数，所以下面的place要+1 
void add(int k,int x){
	_data[idx] = x;
	_last[idx] = k;
	_next[idx] = _next[k]; //若想要在k的左边添加节点可以输入_last[k];
	_last[_next[k]] = idx;
	_next[k] = idx;        //让原来k的next = ids; 
	idx ++;
}
void remove(int k){
	_next[_last[k]] = _next[k];//上一个节点的next为k的下一个 
	_last[_next[k]] = _last[k];
}
int main(){
	int count;
	string signal;
	cin>>count;
	init();
	int num,place;
	for(int i=0;i<count;i++){
		
		cin>>signal;
		if(signal=="L"){
			cin>>num;
			add(0,num);
		}else if(signal=="R"){
			cin>>num;
			add(_last[1],num);
		}else if(signal=="D"){
			cin>>place;
			remove(place+1);
		}else if(signal=="IL"){
			cin>>place>>num;
			add(_last[place+1],num);
		}else if(signal=="IR"){
			cin>>place>>num;
			add(place+1,num);
		}
	}
	for(int i = _next[0];i!=1;i = _next[i]){
		cout<<_data[i]<<" ";
	}
	return 0;		
} 





