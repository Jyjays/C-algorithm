/*
问题描述：每头牛有重量和强壮指数，求所有牛堆叠起来后的最大风险指数的最小值
最大风险指数 = 该牛身上的重量-该牛的强壮指数

解题思路：将所有牛按照重量从小到大排序，然后依次将每头牛放入堆中，
堆中的牛按照强壮指数从大到小排序，每次放入牛时，将堆中的牛按照强壮指数从大到小
*/
#include <iostream>
#include<algorithm>
#include<queue>
#define int long long 
using namespace std;

