#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <limits.h>

#define N 100

int dp[N][2];

int fibonacci(int n, int cnt)
{
	if (n == 0) {
		dp[cnt][0]++;
		return 0;
	}
	else if (n == 1) {
		dp[cnt][1]++;
		return 1;
	}
	else {
		return fibonacci(n - 1, cnt) + fibonacci(n - 2, cnt);
	}
}

int main(void)
{
	int t, n[N], res;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
		scanf("%d", &n[i]);
	for (int i = 0; i < t; i++)
		res = fibonacci(n[i], i);
	for (int i = 0; i < t; i++)
		printf("%d %d\n", dp[i][0], dp[i][1]);

	return 0;
}