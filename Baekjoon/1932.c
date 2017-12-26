#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define N 2002

int dp[N][N];

int calMax(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int main(void)
{
	memset(dp, -1, sizeof(dp));
	int n, max = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i + 1; j++)
			scanf("%d", &dp[i][j]);

	for(int i = 1; i < n; i++)
		for (int j = 0; j < i + 1; j++) {
			if (j == 0)
				dp[i][j] += dp[i - 1][j];
			else if (i == j)
				dp[i][j] += dp[i - 1][j - 1];
			else
				dp[i][j] = calMax(dp[i][j] + dp[i - 1][j], dp[i][j] + dp[i - 1][j - 1]);
		}

	for (int i = 0; i < n; i++)
		if (dp[n - 1][i] > max)
			max = dp[n - 1][i];
	printf("%d\n", max);

	return 0;
}