#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <limits.h>

#define N 1001
#define MAX(a,b) ((a)>=(b)?(a):(b))

int dp[N], f[N];

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &f[i]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			dp[i] = MAX(dp[i], (dp[i - j] + f[j]));

	printf("%d\n", dp[n]);
	return 0;
}