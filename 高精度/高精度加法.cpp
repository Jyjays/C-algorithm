#include <iostream>
#include <string>
using namespace std;

const int N = 100010;

int a[N],b[N],res[N];

int Add(int a[], int b[], int res[], int size) {
    int up = 0; // 进位存储
    for (int i = 0; i < size; i++) {
        up += a[i] + b[i];
        res[i] = up % 10;
        up /= 10;
    }
    if (up) {
        res[size] = up;
        size++; // 如果最高位有进位，结果的长度加一
    }
    return size;
}
int Sub(int a[], int b[], int res[], int sizeA, int sizeB) {
    int borrow = 0; // 借位存储

    for (int i = 0; i < max(sizeA, sizeB); i++) {
        int diff = a[i] - borrow - (i < sizeB ? b[i] : 0);
        if (diff >= 0) {
            res[i] = diff;
            borrow = 0;
        } else {
            res[i] = diff + 10;
            borrow = 1;
        }
    }

    // 删除结果数组末尾的多余零（如果有的话）
    int newSize = max(sizeA, sizeB);
    while (newSize > 0 && res[newSize - 1] == 0) {
        newSize--;  
    }
    if(newSize>=2){
    	return newSize;
	}else{
		return 2;
	}

    // 返回结果的新大小
    // 如果需要保留结果数组的大小，可以使用 newSize
}


int main(){
	string num1,num2;
	cin>>num1>>num2;
	
	int sizeA =0,sizeB = 0;
	
	for(int i=num1.size()-1;i>=0;--i){
		a[sizeA++] = num1[i] - '0';
	}
	for (int i = num2.size() - 1; i >= 0; --i) {
   	    b[sizeB++] = num2[i] - '0'; // 减去 '0' 来将字符转换为整数
	}

//	int resSize = Add(a,b,res,max(sizeA,sizeB));
	int resSize2 = Sub(a,b,res,sizeA,sizeB); 
//	for(int i = resSize - 1;i>= 0;--i){
//		cout<< res[i];
//	}
	for(int i = resSize2-1 ;i>= 0;--i){
		cout<< res[i];
	}
	return 0;
} 
