#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <limits.h>

#define N 1001

int dp[N];

int main(void)
{
	int n;
	scanf("%d", &n);

	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + 2 * dp[i - 2];
		dp[i] %= 10007;
	}
	printf("%d\n", dp[n]);

	return 0;
}