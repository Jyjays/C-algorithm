#include<iostream>
using namespace std;
typedef long long LL;
const int N = 10010;
int q[N], tmp[N];
LL res = 0;
void merge_sort(int q[], int l, int r) {
	if (l >= r)return;

	int mid = (l + r) / 2;
	merge_sort(q,l, mid); merge_sort(q,mid + 1, r);
	int i = l, k = 0, j = mid + 1;
	while (i <= mid && j <= r) {
		if (q[i] <= q[j]) {
			tmp[k++] = q[i++];
		}
		else if (q[i] > q[j]) {
			tmp[k++] = q[j++];
			res += mid - i + 1;
		}
	}
	while (i <= mid) tmp[k++] = q[i++];
	while (j <= r) tmp[k++] = q[j++];
	for (int i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j];
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> q[i];
	merge_sort(q,0, n - 1);
	cout << res;
	return 0;
}