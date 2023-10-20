#include<iostream>

using namespace std;

const int N = 100000; 

int num[N]; 

int n,q,k;

int findNumLeft(int _find,int length){
	int left = 0, right = length-1;
	while(left<=right){
		int mid = left + right >> 1;
		if (num[mid] >= _find) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
	}
	if(left < length && num[left] == _find) return left;
	else{
			return -1;
		} 
}
	 
int findNumRight(int _find,int length){
	int left = 0, right = length-1;
	while(left<=right){
		int mid = left + right >> 1;
		if (num[mid] <= _find) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
	}
	 if (right >= 0 && num[right] == _find) {
        return right;
    } else {
        return -1;
    }
	 
}

int main(){
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>> num[i];
	}
	for(int i=0;i<q;i++){
		cin>>k;
		cout<< findNumLeft(k,n)<<" "<< findNumRight(k,n);
	}
	return 0;
} 
