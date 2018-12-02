#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
bool visited[13];
int magicstarIdx[12][2] = {
	{ 0, 4 }, 
	{ 1, 1 },{ 1, 3 },{ 1,5 },{ 1, 7 },
	{ 2, 2 },{ 2, 6 },
	{ 3, 1 },{ 3, 3 },{ 3,5 },{ 3, 7 },
	{ 4, 4 }
};
int board[5][9];
bool fix[5][9];

bool possibility() {
	int ms1 = board[0][4] + board[1][3] + board[2][2] + board[3][1];
	int ms2 = board[0][4] + board[1][5] + board[2][6] + board[3][7];
	int ms3 = board[1][1] + board[1][3] + board[1][5] + board[1][7];
	int ms4 = board[3][1] + board[3][3] + board[3][5] + board[3][7];
	int ms5 = board[4][4] + board[3][3] + board[2][2] + board[1][1];
	int ms6 = board[4][4] + board[3][5] + board[2][6] + board[1][7];
	if (ms1 == 26 && ms2 == 26 && ms3 == 26 &&
		ms4 == 26 && ms5 == 26 && ms6 == 26)
		return true;
	else return false;
}

bool dfs(int len) {
	if (len == 12) {
		if (possibility()) return true;
		else return false;
	}

	if (fix[magicstarIdx[len][0]][magicstarIdx[len][1]]) {
		if (dfs(len + 1)) return true;
	}
	else {
		for (int i = 1; i <= 12; ++i) {
			if (board[magicstarIdx[len][0]][magicstarIdx[len][1]] == 0 &&
				!visited[i]) {
				visited[i] = true;
				board[magicstarIdx[len][0]][magicstarIdx[len][1]] = i;
				if (dfs(len + 1)) return true;
				visited[i] = false;
				board[magicstarIdx[len][0]][magicstarIdx[len][1]] = 0;
			}
		}
	}
	return false;
}

int main(void)
{
	for (int i = 0; i < 5; ++i) {
		string in; cin >> in;
		for (int j = 0; j < 9; ++j) {
			if (in[j] == 'x')
				board[i][j] = 0;
			else if (in[j] == '.')
				board[i][j] = -1;
			else {
				fix[i][j] = true;
				board[i][j] = in[j] - 'A' + 1;
				visited[board[i][j]] = true;
			}
		}
	}

	if (dfs(0))
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] == -1) printf(".");
				else printf("%c", board[i][j] + 'A' - 1);
			}
			printf("\n");
		}

	return 0;
}