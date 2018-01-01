#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define N 100001

int dp[N];

int main(void)
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		dp[i] = i;
		for (int j = 1; j*j <= i; j++) {
			if (dp[i] > dp[i - j*j] + 1)
				dp[i] = dp[i - j*j] + 1;
		}
	}
	printf("%d\n", dp[n]);

	return 0;
}