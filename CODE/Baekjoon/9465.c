#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <limits.h>

#define N 100001
#define MAX(a,b) ((a)>(b)?(a):(b))
int dp[N][3], s[2][N];

int comMax(int a, int b, int c)
{
	int max;
	max = a;
	if (max < b)
		max = b;
	if (max < c)
		max = c;
	return max;
}
int main(void)
{
	int t, n;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		for (int j = 0; j < 2; j++)
			for (int k = 1; k <= n; k++)
				scanf("%d", &s[j][k]);

		for (int i = 1; i <= n; i++) {
			dp[i][0] = comMax(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]);
			dp[i][1] = MAX(dp[i - 1][0], dp[i - 1][2]) + s[0][i];
			dp[i][2] = MAX(dp[i - 1][0], dp[i - 1][1]) + s[1][i];
		}

		printf("%d\n", comMax(dp[n][0], dp[n][1], dp[n][2]));
	}

	return 0;
}