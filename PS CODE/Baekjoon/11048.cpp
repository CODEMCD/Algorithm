#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;
#define N 1001
int miro[N][N];
int dp[N][N];
int mx[3] = { 0,1,1 };
int my[3] = { 1,0,1 };

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &miro[i][j]);
	
	dp[0][0] = miro[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 3; k++) {
				int x = i + mx[k];
				int y = j + my[k];
				if (x < n && y < m) {
					int sum = dp[i][j] + miro[x][y];
					if (sum > dp[x][y])
						dp[x][y] = sum;
				}
			}
		}
	}
	/*printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf("%d ", dp[i][j]);
		printf("\n");
	}*/
	printf("%d\n", dp[n - 1][m - 1]);
	return 0;
}