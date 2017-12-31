#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <limits.h>

#define N 1001

int dp[N], num[N];

int main(void)
{
	int n, max;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &num[i]);

	dp[1] = 1;
	for (int i = 1; i <= n; i++) {
		max = 0;
		for (int j = 1; j < i; j++) {
			if (num[i] > num[j] && max < dp[j])
				max = dp[j];
		}
		dp[i] = max + 1;
	}
	max = dp[1];
	for (int i = 1; i <= n; i++)
		if (max < dp[i])
			max = dp[i];
	printf("%d\n", max);

	return 0;
}