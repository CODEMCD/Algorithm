#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
using namespace std;
#define N 101
int dp[N][N];
int maxn = 100001;

int main(void)
{
	int n, m;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (i == j)
				dp[i][j] = 0;
			else
				dp[i][j] = maxn;
		}

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (dp[a][b] > c)
			dp[a][b] = c;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i != j && i != k && j != k)
					if (dp[i][j] > dp[i][k] + dp[k][j])
						dp[i][j] = dp[i][k] + dp[k][j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] == maxn)
				printf("0 ");
			else
				printf("%d ", dp[i][j]);
		}
		printf("\n");
	}

	return 0;
}