#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
int board[101][101];
int w[10001];
int m, n, k;
int wc = 0;

void dfs(int y, int x) {
	board[y][x] = 1;
	wc++;
	for (int i = 0; i < 4; ++i) {
		int nexty = y + dy[i];
		int nextx = x + dx[i];
		if (nexty < 0 || nexty >= m || nextx < 0 || nextx >= n)
			continue;
		if (board[nexty][nextx] == 0)
			dfs(nexty, nextx);
	}
}

int main(void)
{
	scanf("%d %d %d", &m, &n, &k);

	int total = m * n;
	int fill = 0;
	for (int i = 0; i < k; ++i) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (int y = y1; y < y2; ++y)
			for (int x = x1; x < x2; ++x) {
				board[y][x] = 1;
				fill++;
			}
	}

	int cnt = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (board[i][j] == 0) {
				wc = 0;
				dfs(i, j);
				w[cnt++] = wc;
			}
		}
	}

	printf("%d\n", cnt);
	sort(w, w + cnt);
	for (int i = 0; i < cnt; ++i)
		printf("%d ", w[i]);
	printf("\n");

	return 0;
}