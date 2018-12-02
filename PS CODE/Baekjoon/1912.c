#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <limits.h>

#define N 100001
#define MAX(a,b) ((a)>(b)?(a):(b))

int dp[N], num[N];

int main(void)
{
	int n, max;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &num[i]);

	dp[1] = num[1];
	for (int i = 2; i <= n; i++)
		dp[i] = MAX((dp[i - 1] + num[i]), num[i]);
	
	max = dp[1];
	for (int i = 2; i <= n; i++)
		if (max < dp[i])
			max = dp[i];
	printf("%d\n", max);

	return 0;
}