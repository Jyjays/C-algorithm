//#include<iostream>
//using namespace std;
//const int N = 1e6;
//int q[N];
////快速排序算法
////void quick_sort(int* q,int l,int r) {
////	if (l >= r)return;
////	int x = q[(l + r) / 2];
////	int i = l - 1, j = r + 1;
////	while (i < j) {
////		do i++; while (q[i] < x);
////		do j--; while (q[j] > x);
////		if (i < j)swap(q[i], q[j]);
////	}
////	quick_sort(q, l, j); quick_sort(q, j + 1, r);
////}
//
////快速选择
//int quick_sort(int l, int r, int k) {
//	if (l == r) { return q[l]; }
//	int x = q[(l + r) / 2];
//	int i = l - 1, j = r + 1;
//	while (i < j) {
//		do i++; while (q[i] < x);
//		do j--; while (q[j] > x);
//		if (i < j)swap(q[i], q[j]);
//	}
//	int sl = j - l + 1;
//	if (k <= sl) { return quick_sort(l, j, k); }
//	return quick_sort(j + 1, r, k - sl);
//}
//int main() {
//	int n, k;
//	cin >> n >> k;
//	for (int i = 0; i < n; i++) {
//		cin >> q[i];
//	}
//	cout << quick_sort(0,n-1,k);
//	return 0;
//}