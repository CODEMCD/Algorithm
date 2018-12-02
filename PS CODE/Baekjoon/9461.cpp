#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 101
long long dp[N];

int main(void)
{
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;
	dp[4] = 2;
	dp[5] = 3;
	dp[6] = 4;
	dp[7] = 5;
	dp[8] = 7;
	for (int i = 9; i < N; i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}

	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%lld\n", dp[n - 1]);
	}
	return 0;
}