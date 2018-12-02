#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
int map[101][101];
bool visited[101][101];
int n;

void dfs(int y, int x) {
	visited[y][x] = true;

	for (int i = 0; i < 4; ++i) {
		int nexty = y + dy[i];
		int nextx = x + dx[i];
		if (nexty < 0 || nexty >= n || nextx < 0 || nextx >= n)
			continue;
		if (!visited[nexty][nextx])
			dfs(nexty, nextx);
	}
}

int main(void)
{
	scanf("%d", &n);
	int maxH = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			scanf("%d", &map[i][j]);
			maxH = maxH > map[i][j] ? maxH : map[i][j];
		}

	int ln = n * n;
	//비가 오지 않은 경우가 존재하므로, 최소값은 1이다.
	int safeZone = 1;
	for (int h = 1; h <= maxH; ++h) {
		int cn = 0, cs = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				visited[i][j] = false;

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				if (h >= map[i][j]) {
					visited[i][j] = true;
					cn++;
				}
			}
		if (cn == ln) break;

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (!visited[i][j]) {
					dfs(i, j);
					cs++;
				}
		safeZone = safeZone > cs ? safeZone : cs;
	}
	printf("%d\n", safeZone);

	return 0;
}