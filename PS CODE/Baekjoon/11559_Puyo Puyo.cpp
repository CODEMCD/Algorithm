#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };
int board[13][7];
int check[13][7], exCnt;

void dfs(int y, int x, int color) {
	exCnt++;
	check[y][x] = 1;

	for (int i = 0; i < 4; ++i) {
		int nexty = y + dy[i];
		int nextx = x + dx[i];
		if (nexty < 0 || nexty >= 12 || nextx < 0 || nextx >= 6)
			continue;
		if (board[nexty][nextx] == color && !check[nexty][nextx]) {
			check[nexty][nextx] = 1;
			dfs(nexty, nextx, color);
		}
	}
}

void init() {
	for (int i = 0; i < 12; ++i)
		for (int j = 0; j < 6; ++j)
			check[i][j] = 0;
}

int main(void)
{
	for (int i = 0; i < 12; ++i) {
		string row;
		cin >> row;
		for (int j = 0; j < 6; ++j) {
			if (row[j] == '.') board[i][j] = 0;
			else if (row[j] == 'R') board[i][j] = 1;
			else if (row[j] == 'G') board[i][j] = 2;
			else if (row[j] == 'B') board[i][j] = 3;
			else if (row[j] == 'P') board[i][j] = 4;
			else if (row[j] == 'Y') board[i][j] = 5;
		}
	}

	bool flag = true;
	int ans = 0;
	while (flag) {
		flag = false;
		init();
		for (int y = 0; y < 12; ++y) {
			for (int x = 0; x < 6; ++x) {
				if (board[y][x] > 0 && check[y][x] == 0) {
					exCnt = 0;
					dfs(y, x, board[y][x]);
					if (exCnt >= 4) {
						flag = true;
						for (int y = 0; y < 12; ++y)
							for (int x = 0; x < 6; ++x)
								if (check[y][x] == 1)
									board[y][x] = 0;

					}
					else {
						for (int y = 0; y < 12; ++y)
							for (int x = 0; x < 6; ++x)
								if (check[y][x] == 1)
									check[y][x] = -1;
					}
				}
			}
		}

		for (int x = 0; x < 6; ++x) {
			int tmp[13] = { 0, };
			int ycnt = 11;
			for (int y = 11; y >= 0; --y)
				if (board[y][x] > 0)
					tmp[ycnt--] = board[y][x];
			for (int y = 11; y >= 0; --y)
				board[y][x] = tmp[y];
		}

		/*for (int y = 0; y < 12; ++y) {
			for (int x = 0; x < 6; ++x)
				printf("%d ", board[y][x]);
			printf("\n");
		}*/
		if(flag)
			ans++;
	}
	printf("%d\n", ans);

	return 0;
}