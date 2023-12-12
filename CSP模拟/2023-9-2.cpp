#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<iomanip> 
using namespace std;

int n,m; 
vector<pair<int,double>> ops;
vector<pair<pair<int,int>,pair<double,double>>> sites;
void cal(int l,int r,double x,double y){
	for(int i=l-1;i<=r-1;i++){
		if(ops[i].first==1){
			x*=ops[i].second;
			y*=ops[i].second;
		}
		else if(ops[i].first==2){
			double tmp1=x,tmp2 =y;
			x = tmp1*cos(ops[i].second)-tmp2*sin(ops[i].second);
			y = tmp1*sin(ops[i].second)+tmp2*cos(ops[i].second); 
		}
	}
	cout<<fixed<<setprecision(3)<<x<<" "<<fixed<<setprecision(3)<<y<<endl;
}
int main(){
	cin>>n>>m;
	int k;
	double op;
	for(int i =0;i<n;i++){
		cin>>k>>op;
		auto d = make_pair(k,op);
		ops.push_back(d);
	}
	int l,r;
	double x,y;
	for(int i=0;i<m;i++){
		cin>>l>>r>>x>>y;
		auto pair1 = make_pair(l,r);
		auto pair2 = make_pair(x,y);
		auto pair3 = make_pair(pair1,pair2);
		sites.push_back(pair3);
	}
	for(int i =0;i<m;i++){
		cal(sites[i].first.first,sites[i].first.second,sites[i].second.first,sites[i].second.second);
	}
	return 0;
} 

