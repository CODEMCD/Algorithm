#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };
int board[101][101], blindBoard[101][101];
bool visited[101][101];
int n;

void dfs(int y, int x, int color, bool blindFlag) {
	visited[y][x] = true;
	int boardColor;

	for (int i = 0; i < 4; ++i) {
		int nexty = y + dy[i];
		int nextx = x + dx[i];
		if (nexty < 0 || nexty >= n || nextx < 0 || nextx >= n)
			continue;
		boardColor = blindFlag ? blindBoard[nexty][nextx] :
			board[nexty][nextx];
		if (!visited[nexty][nextx] && boardColor == color)
			dfs(nexty, nextx, color, blindFlag);
	}
}

void visitedInit() {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			visited[i][j] = false;
}

int main(void)
{
	scanf("%d", &n);
	string str;
	for (int i = 0; i < n; ++i) {
		cin >> str;
		for (int j = 0; j < n; ++j) {
			if (str[j] == 'R') {
				board[i][j] = 1;
				blindBoard[i][j] = 1;
			}
			else if (str[j] == 'G') {
				board[i][j] = 2;
				blindBoard[i][j] = 1;
			}
			else if (str[j] == 'B') {
				board[i][j] = 3;
				blindBoard[i][j] = 3;
			}
		}
	}

	int blind = 0, notBlind = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (!visited[i][j]) {
				dfs(i, j, board[i][j], false);
				notBlind++;
			}
	
	visitedInit();
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (!visited[i][j]) {
				dfs(i, j, blindBoard[i][j], true);
				blind++;
			}

	printf("%d %d\n", notBlind, blind);

	return 0;
}