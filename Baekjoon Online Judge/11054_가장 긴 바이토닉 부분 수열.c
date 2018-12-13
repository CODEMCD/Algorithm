#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <limits.h>

#define N 1001

int dp[N], dp2[N], num[N];

int main(void)
{
	int n, max, max2, maxI;
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

	
	for (int i = n; i >= 1; i--) {
		dp2[i] = 1;
		max2 = 0;
		for (int j = i + 1; j <= n; j++) {
			if (num[i] > num[j] && max2 < dp2[j])
				max2 = dp2[j];
		}
		dp2[i] = max2 + 1;
	}

	max = 0;
	for (int i = 1; i <= n; i++)
		if (max < dp[i] + dp2[i] - 1)
			max = dp[i] + dp2[i] - 1;
	printf("%d\n", max);

	return 0;
}