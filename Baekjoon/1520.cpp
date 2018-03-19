#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define N 501
int map[N][N];
int dp[N][N];
int mx[4] = { 1,-1,0,0 };
int my[4] = { 0,0,1,-1 };
int m, n;

int dfs(int nowx, int nowy)
{
	if (nowx == n - 1 && nowy == m - 1)
		return 1;
	if (dp[nowy][nowx] != -1) return dp[nowy][nowx];
	dp[nowy][nowx] = 0;
	for (int i = 0; i < 5; i++) {
		int nextx = nowx + mx[i];
		int nexty = nowy + my[i];
		if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < m) {
			if (map[nowy][nowx] > map[nexty][nextx]) {
				dp[nowy][nowx] += dfs(nextx, nexty);
				/*for (int i = 0; i < m; i++) {
					for (int j = 0; j < n; j++)
						printf("%d ", dp[i][j]);
					printf("\n");
				}
				printf("---------------\n");*/
			}
		}
	}
	return dp[nowy][nowx];
}

int main(void)
{
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			dp[i][j] = -1;
		}
	dfs(0, 0);
	/*for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			printf("%d ", dp[i][j]);
		printf("\n");
	}*/
	printf("%d\n", dp[0][0]);

	return 0;
}