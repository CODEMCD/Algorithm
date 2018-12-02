#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
#define N 200001
int home[N];

int main(void)
{
	int n, c;
	scanf("%d %d", &n, &c);
	for (int i = 0; i < n; i++)
		scanf("%d", &home[i]);
	sort(home, home + n);
	int ans = 0;
	int cnt;
	int l = 1;
	int r = home[n - 1] - home[0];
	int tmp = home[0];
	while (l <= r) {
		int mid = (l + r) / 2;
		cnt = 1;
		tmp = home[0];
		for (int i = 1; i < n; i++)
			if (home[i] - tmp >= mid) {
				cnt++;
				tmp = home[i];
			}
		if (cnt >= c) {
			if (ans < mid)
				ans = mid;
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	printf("%d\n", ans);

	return 0;
}