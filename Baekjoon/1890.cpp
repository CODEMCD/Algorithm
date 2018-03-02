#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
#define N 101
int map[N][N];
long long dp[N][N];

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &map[i][j]);
	dp[0][0] = 1;
	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int next = map[i][j];
			if (j != n - 1 && j + next < n)
				dp[i][j + next] += dp[i][j];
			if (i != n - 1 && i + next < n)
				dp[i + next][j] += dp[i][j];
		}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%lld ", dp[i][j]);
		printf("\n");
	}*/
	printf("%lld\n", dp[n - 1][n - 1]);
	return 0;
}