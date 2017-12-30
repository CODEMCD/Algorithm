#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <limits.h>

#define N 1001

long long dp[N][N];

int main(void)
{
	int n;
	long long ans = 0;
	scanf("%d", &n);

	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;
	for(int i = 2; i <= n; i++)
		for (int j = 0; j < 10; j++)
			for (int k = 0; k < 10; k++) {
				if (j == 9)
					dp[i][j] = dp[i - 1][9];
				else if(j != 9 && j + k < 10)
					dp[i][j] += dp[i - 1][j + k];
				dp[i][j] %= 10007;
			}
	for (int i = 0; i < 10; i++)
		ans += dp[n][i];
	printf("%llu\n", ans % 10007);
	return 0;
}