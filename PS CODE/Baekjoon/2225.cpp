#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 201
long long dp[N][N];

int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);

	int mod = 1000000000;
	for (int i = 1; i <= n; i++)
		dp[i][1] = 1;
	for (int i = 1; i <= k; i++)
		dp[1][i] = i;
	for (int i = 2; i <= n; i++)
		for (int j = 2; j <= k; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			dp[i][j] %= mod;
		}
	printf("%lld\n", dp[n][k] % mod);
	return 0;
}