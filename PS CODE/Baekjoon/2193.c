#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <limits.h>

#define N 101

long long dp[N][2];

int main(void)
{
	int n;
	scanf("%d", &n);

	dp[1][0] = 0; dp[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}
	
	printf("%llu\n", dp[n][0] + dp[n][1]);

	return 0;
}