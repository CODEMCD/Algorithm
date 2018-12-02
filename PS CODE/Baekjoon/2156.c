#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <limits.h>

#define N 10001

int dp[N], g[N];

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n + 1; i++)
		scanf("%d", &g[i]);

	dp[1] = g[1];
	dp[2] = g[1] + g[2];
	for (int i = 3; i < n + 1; i++) {
		dp[i] = dp[i - 1];
		if (dp[i] < dp[i - 2] + g[i])
			dp[i] = dp[i - 2] + g[i];
		if (dp[i] < dp[i - 3] + g[i - 1] + g[i])
			dp[i] = dp[i - 3] + g[i - 1] + g[i];
	}

	printf("%d\n", dp[n]);

	return 0;
}