#include <algorithm>
#include <iostream>

using namespace std;

const int N = 10010;
int n;
int heap[N];
int s = 0;
bool cmp(int a, int b) { return a > b; }

void down(int x) {
  int t = x;
  if (2 * x <= s && cmp(heap[x], heap[2 * x])) {
    t = 2 * x;
  }
  if (2 * x + 1 <= s && cmp(heap[t], heap[2 * x + 1])) {
    t = 2 * x + 1;
  }
  if (t != x) {
    swap(heap[x], heap[t]);
    down(t);
  }
}

void up(int x) { int newx = 0; }

int main() {
  int m;
  cin >> n >> m;
  s = n;
  for (int i = 1; i <= n; i++) {
    cin >> heap[i];
  }

  for (int i = s / 2; i > 0; i--) {
    down(i);
  }
  while (m --) {
    cout << heap[1];
    heap[1] = heap[s] ;
    s --;
    down(1);
  }
  return 0;
}