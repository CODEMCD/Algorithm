#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
#define N 10001
long long kcord[N];

int main(void)
{
	int k, n;
	scanf("%d %d", &k, &n);
	long long len = 0;
	for (int i = 0; i < k; i++) {
		scanf("%lld", &kcord[i]);
		if (len < kcord[i])
			len = kcord[i];
	}
	long long cnt;
	long long ans = 0;
	long long l = 1;
	long long r = len;
	while(l <= r) {
		long long mid = (l + r) / 2; //binary point
		cnt = 0;
		for (int i = 0; i < k; i++)
			cnt += kcord[i] / mid;
		if (cnt >= n) {
			if (ans < mid)
				ans = mid;
			l = mid + 1;
		}
		else
			r = mid - 1;
		
	}
	printf("%lld\n", ans);
	return 0;
}