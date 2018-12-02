#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0, 0 };
int n;
double dp[4];
int visited[31][31];

double dfs(int y, int x, int step) {
	if (step == n) return 1.0;
	visited[y][x] = true;
	double ret = 0.0;
	for (int i = 0; i < 4; ++i) {
		int nexty = y + dy[i];
		int nextx = x + dx[i];
		if (visited[nexty][nextx]) continue;
		ret += dfs(nexty, nextx, step + 1) * dp[i];
	}
	visited[y][x] = false;
	return ret;
}


int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < 4; ++i) {
		scanf("%lf", &dp[i]);
		dp[i] /= 100.0;
	}

	printf("%.9lf\n", dfs(15, 15, 0));

	return 0;
}
