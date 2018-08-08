#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define N 101
vector<int> v[N];
vector<int> g[N];
bool check[N];
int map[N][N];
int dp[N][N];
int ans[N];

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (i == j)
				dp[i][j] = 0;
			else
				dp[i][j] = n + 1;
		}
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int from, to;
		scanf("%d %d", &from, &to);
		dp[from][to] = 1;
		dp[to][from] = 1;
		v[from].push_back(to);
		v[to].push_back(from);
	}
	//Floyd Washall
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dp[i][j] > dp[i][k] + dp[k][j])
					dp[i][j] = dp[i][k] + dp[k][j];
			}
		}
	}
	// group(BFS)
	int gcnt = -1;
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			q.push(i);
			gcnt++;
			g[gcnt].push_back(i);
			check[i] = true;
		}
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (int j = 0; j < (int)v[now].size(); j++) {
				int next = v[now][j];
				if (!check[next]) {
					q.push(next);
					g[gcnt].push_back(next);
					check[next] = true;
				}
			}
		}
	}
	/*for (int i = 0; i <= gcnt; i++) {
		for (int j = 0; j < g[i].size(); j++)
			printf("%d ", g[i][j]);
		printf("\n");
	}*/

	int imax, totalmin, index;
	for (int k = 0; k <= gcnt; k++) {
		totalmin = n + 1;
		if ((int)g[k].size() == 1) {
			ans[k] = g[k][0];
			continue;
		}
		for (int i = 0; i < (int)g[k].size(); i++) {
			imax = 0;
			for (int j = 0; j < (int)g[k].size(); j++) {
				int ni = g[k][i];
				int nj = g[k][j];
				if (imax < dp[ni][nj] && dp[ni][nj] < n) {
					imax = dp[ni][nj];
					index = ni;
				}
			}
			if (imax != 0 && totalmin > imax) {
				totalmin = imax;
				ans[k] = index;
			}
		}
	}
	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			printf("%d ", dp[i][j]);
		printf("\n");
	}*/
	sort(ans, ans + (gcnt + 1));
	printf("%d\n", gcnt + 1);
	for (int i = 0; i <= gcnt; i++)
		printf("%d\n", ans[i]);

	return 0;
}
/* 테스트 케이스, 답 3
9
8
1 2
2 3
3 4
4 5
4 6
4 7
4 8
4 9
*/