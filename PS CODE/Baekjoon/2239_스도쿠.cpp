#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define curBoxIdx(y,x) ((y)/3*3) + ((x)/3)
int board[9][9];
bool rowCheck[9][10];
bool colCheck[9][10];
bool boxCheck[9][10];
int emptyN = 0;

bool dfs(int y, int x) {
	if (x == 9) {
		if (emptyN == 0)
			return true;
		else
			return false;
	}

	bool ret = false;
	if (board[y][x] == 0) {
		for (int i = 1; i < 10; ++i) {
			if (!rowCheck[y][i] && !colCheck[x][i] &&
				!boxCheck[curBoxIdx(y, x)][i]) {
				rowCheck[y][i] = colCheck[x][i] =
					boxCheck[curBoxIdx(y, x)][i] = true;
				board[y][x] = i;
				emptyN--;

				if (x == 8 && y != 8)
					ret = dfs(y + 1, 0);
				else
					ret = dfs(y, x + 1);
				if (ret) return true;

				rowCheck[y][i] = colCheck[x][i] =
					boxCheck[curBoxIdx(y, x)][i] = false;
				board[y][x] = 0;
				emptyN++;
			}
		}
	}
	else {
		if (x == 8 && y != 8)
			ret = dfs(y + 1, 0);
		else
			ret = dfs(y, x + 1);
		if (ret) return true;
	}

	return false;
}

int main(void)
{
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j) {
			scanf("%1d", &board[i][j]);
			if (!board[i][j]) emptyN++;
			else {
				rowCheck[i][board[i][j]] = colCheck[j][board[i][j]] =
					boxCheck[curBoxIdx(i, j)][board[i][j]] = true;
			}
		}

	if (dfs(0, 0)) {
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j)
				printf("%d", board[i][j]);
			printf("\n");
		}
	}

	return 0;
}