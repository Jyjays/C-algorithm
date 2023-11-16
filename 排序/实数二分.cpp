#include <iostream>
#include<iomanip>
using namespace std;
 
double n;

double binary(double num ){
	double left = -10000,right = 10000;
	double epsilon = 1e-7;  // ��ֵ����ʾ�㹻�ӽ�
    while (right - left > epsilon) {
		double mid = ( left + right ) / 2.0;
		if(mid*mid*mid>=num) right = mid;
		else left = mid;
	}
	return left;
}

int main(){
	cin >> n;
	cout<<fixed<<setprecision(6)<<binary(n);
	return 0;
}
