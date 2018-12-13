#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int my[4] = { 0, 1, 0, -1 };
int mx[4] = { 1, 0, -1, 0 };
int board[5][5];
bool check[10][10][10][10][10][10];
int num[6];
int ans;

void dfs(int y, int x, int step) {
	num[step] = board[y][x];
	if (step == 5) {
		if (!check[num[0]][num[1]][num[2]][num[3]][num[4]][num[5]]) {
			ans += 1;
			check[num[0]][num[1]][num[2]][num[3]][num[4]][num[5]] = true;
		}
		return;
	}
	for (int i = 0; i < 4; ++i) {
		int nexty = y + my[i];
		int nextx = x + mx[i];
		if (nexty < 0 || nexty >= 5 || nextx < 0 || nextx >= 5)
			continue;
		dfs(nexty, nextx, step + 1);
	}
}

int main(void)
{
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			scanf("%d", &board[i][j]);

	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			dfs(i, j, 0);
	printf("%d\n", ans);
	
	return 0;
}