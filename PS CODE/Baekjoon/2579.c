#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <limits.h>

#define N 3001
#define MAX(a,b) ((a)>(b)?(a):(b))

int dp[N];

int main(void)
{
	int n, st[N];
	scanf("%d", &n);
	for (int i = 1; i < n + 1; i++)
		scanf("%d", &st[i]);
	for (int i = 1; i < 4; i++) {
		if (i != 3)
			dp[i] = dp[i - 1] + st[i];
		else
			dp[i] = MAX((dp[i - 3] + st[i - 1]), dp[i - 2]) + st[i];
	}
	for (int i = 4; i < n + 1; i++)
			dp[i] = MAX((dp[i - 3] + st[i - 1]), dp[i - 2]) + st[i];
	printf("%d\n", dp[n]);

	return 0;
}