#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define N 31

int dp[N];

int main(void)
{
	int n;
	scanf("%d", &n);

	dp[0] = 1;
	dp[2] = 3;
	if (n > 2) {
		for (int i = 4; i <= n; i += 2) {
			dp[i] = 3 * dp[i - 2];
			for (int j = 4; j <= i; j += 2) {
				dp[i] += 2 * dp[i - j];
			}
		}
	}
	printf("%d\n", dp[n]);

	return 0;
}