#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <limits.h>

#define N 10001

int dp[N], c[N];

int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]);

	dp[0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = c[i]; j < k + 1; j++)
			dp[j] += dp[j - c[i]];

	printf("%d\n", dp[k]);

	return 0;
}