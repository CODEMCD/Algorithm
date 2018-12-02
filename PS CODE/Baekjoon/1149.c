#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <limits.h>

#define N 1002
#define MIN(a,b) ((a) < (b) ? (a) : (b))

int dp[N][3];

int main(void)
{
	int n, rgb[N][3], min;
	scanf("%d", &n);
	for (int i = 1; i < n + 1; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &rgb[i][j]);

	for (int i = 0; i < 3; i++) {
		dp[0][i] = 0;
		rgb[0][i] = 0;
	}
	for (int i = 0; i < n + 1; i++) {
		dp[i][0] = MIN(dp[i - 1][1], dp[i - 1][2]) + rgb[i][0];
		dp[i][1] = MIN(dp[i - 1][0], dp[i - 1][2]) + rgb[i][1];
		dp[i][2] = MIN(dp[i - 1][0], dp[i - 1][1]) + rgb[i][2];
	}

	min = INT_MAX;
	for (int i = 0; i < 3; i++)
		if (min > dp[n][i])
			min = dp[n][i];
	printf("%d\n", min);

	return 0;
}