#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
int board[6][10];
int remains, totals, cnt;

void dfs(int y, int x) {
	for (int i = 0; i < 4; ++i) {
		int nexty = y + dy[i];
		int nextx = x + dx[i];
		if (nexty < 0 || nexty >= 5 || nextx < 0 || nextx >= 9 ||
			board[nexty][nextx] != 1)
			continue;
		int nextnexty = nexty + dy[i];
		int nextnextx = nextx + dx[i];
		if (nextnexty < 0 || nextnexty >= 5 || nextnextx < 0 || nextnextx >= 9 ||
			board[nextnexty][nextnextx] != 0)
			continue;
		board[y][x] = board[nexty][nextx] = 0;
		board[nextnexty][nextnextx] = 1;
		cnt -= 1;
		remains = remains < cnt ? remains : cnt;
		for (int j = 0; j < 5; ++j)
			for (int k = 0; k < 9; ++k)
				if (board[j][k] == 1)
					dfs(j, k);
		board[y][x] = board[nexty][nextx] = 1;
		board[nextnexty][nextnextx] = 0;
		cnt += 1;
	}
}

int main(void)
{
	int tc; scanf("%d", &tc);
	char c;
	while (tc--) {
		cnt = 0;
		for (int i = 0; i < 5; ++i) {
			string in; cin >> in;
			for (int j = 0; j < 9; ++j) {
				if (in[j] == '#') board[i][j] = -1;
				else if (in[j] == 'o') {
					board[i][j] = 1;
					cnt++;
				}
				else if (in[j] == '.') board[i][j] = 0;
			}
		}
		remains = cnt;
		totals = cnt;
		for (int i = 0; i < 5; ++i)
			for (int j = 0; j < 9; ++j)
				if (board[i][j] == 1)
					dfs(i, j);
		//최소 이동 횟수 체크
		printf("%d %d\n", remains, totals - remains);
		scanf("%c", &c);
	}

	return 0;
}