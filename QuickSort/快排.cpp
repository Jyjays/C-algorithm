//#include<iostream>
//using namespace std;
//void quick_sort(int q[],int l,int r) {
//	if (l >= r)return;
//	//q[l]是分界点,可以任意取
//	int x = q[l]; int i = l - 1, j = r + 1;
//	while (i < j) {
//		do i++; while (q[i] < x);
//		do j--; while (q[j] > x);
//		if (i < j)swap(q[i], q[j]);
//	}
//	quick_sort(q, l, j); quick_sort(q, j + 1, r);
//}
//int main() {
//	int n;
//	cin >> n;
//	int* p = new int[n];
//	for (int i = 0; i < n; i++) cin >> p[i];
//	quick_sort(p, 0, n - 1);
//	for (int i = 0; i < n;i++)cout << p[i];
//	return 0;
//}
////快排最怕分界是发生无限划分,比如所有的数都被划分到一边,
////当使用最左边的数q[l]作为分界点时,如果右侧的数全部都比第一个数大,则会发生无限划分,取右边同理
////若数组中的数据全部相等会导致指针下标超限
//// 采用do-while并且i和j都有偏移量是因为如果用while循环的话两个指针指向的数都等于分界值的话会导致无限循环
////递归必须按照上述格式,因为完成一遍循环后数组已经成功被分成0到j和j+1到r两组