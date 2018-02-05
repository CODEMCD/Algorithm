#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
#define N 1000001
long long tree[N];

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	long long max = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &tree[i]);
		if (max < tree[i])
			max = tree[i];
	}
	long long ans = 0;
	long long cnt = 0;
	long long l = 1;
	long long r = max;
	while (l <= r) {
		long long mid = (l + r) / 2;
		cnt = 0;
		for (int i = 0; i < n; i++) {
			if (tree[i] > mid)
				cnt += (tree[i] - mid);
		}
		//printf("%lld %lld %lld %lld\n", mid, l, r, cnt);
		if (cnt >= m) {
			if (ans < mid)
				ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	printf("%lld\n", ans);
	return 0;
}