#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;
#define N 51
char board[N][N];

void Swap(char *a, char *b) {
	char tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

//행에서 연속되는 같은 색깔의 사탕 개수를 반환한다.
int calLengthRow(int y, int x, char color, int n) {
	int eat = 0;
	for (int i = x; i < n; ++i) {
		if (board[y][i] == color) eat++;
		else break;
	}
	return eat;
}

//열에서 연속되는 같은 색깔의 사탕 개수를 반환한다.
int calLengthColumn(int y, int x, char color, int n) {
	int eat = 0;
	for (int i = y; i < n; ++i) {
		if (board[i][x] == color) eat++;
		else break;
	}
	return eat;
}

//사탕이 교한했을 때, 직접적으로 연관되는 2개의 행과 열을 검사하여
//먹을 수 있는 최대 사탕의 개수를 반환한다.
//(원래 직접적인 연관은 행 교환시, 행 1개 열 2개/ 열 교환시 행 2개 열 1개 이렇게 3개이지만
//4개로 해도 통과되는 것으로 보면 사탕을 교환하지 않고도 가장 긴 사탕열이 있으면 답이 되는듯 하다.)
int checkChangeCandy(int y1, int y2, int x1, int x2, int n) {
	int eatCandy = 0;  //최대 개수
	//행1 검사
	for (int i = 0; i < n; ++i) {
		if (board[y1][i] == 'C')
			eatCandy = max(eatCandy, calLengthRow(y1, i, 'C', n));
		else if (board[y1][i] == 'P') 
			eatCandy = max(eatCandy, calLengthRow(y1, i, 'P', n));
		else if (board[y1][i] == 'Z')
			eatCandy = max(eatCandy, calLengthRow(y1, i, 'Z', n));
		else if (board[y1][i] == 'Y')
			eatCandy = max(eatCandy, calLengthRow(y1, i, 'Y', n));
	}
	//행2 검사
	for (int i = 0; i < n; ++i) {
		if (board[y2][i] == 'C')
			eatCandy = max(eatCandy, calLengthRow(y2, i, 'C', n));
		else if (board[y2][i] == 'P')
			eatCandy = max(eatCandy, calLengthRow(y2, i, 'P', n));
		else if (board[y2][i] == 'Z')
			eatCandy = max(eatCandy, calLengthRow(y2, i, 'Z', n));
		else if (board[y2][i] == 'Y')
			eatCandy = max(eatCandy, calLengthRow(y2, i, 'Y', n));
	}

	//열1 검사
	for (int i = 0; i < n; ++i) {
		if (board[i][x1] == 'C') 
			eatCandy = max(eatCandy, calLengthColumn(i, x1, 'C', n));
		else if (board[i][x1] == 'P')
			eatCandy = max(eatCandy, calLengthColumn(i, x1, 'P', n));
		else if (board[i][x1] == 'Z')
			eatCandy = max(eatCandy, calLengthColumn(i, x1, 'Z', n));
		else if (board[i][x1] == 'Y')
			eatCandy = max(eatCandy, calLengthColumn(i, x1, 'Y', n));
	}
	//열2 검사
	for (int i = 0; i < n; ++i) {
		if (board[i][x2] == 'C')
			eatCandy = max(eatCandy, calLengthColumn(i, x2, 'C', n));
		else if (board[i][x2] == 'P')
			eatCandy = max(eatCandy, calLengthColumn(i, x2, 'P', n));
		else if (board[i][x2] == 'Z')
			eatCandy = max(eatCandy, calLengthColumn(i, x2, 'Z', n));
		else if (board[i][x2] == 'Y')
			eatCandy = max(eatCandy, calLengthColumn(i, x2, 'Y', n));
	}
	//printf("%d\n", eatCandy);
	return eatCandy;
}

int main()
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%s", board[i]);

	int eat = 0;
	//보드에서 행과 열을 바꿀 수 있는 모든 경우를 탐색한다.(완전 탐색)
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			//행 바꾸기
			if (j + 1 < n) {
				Swap(&board[i][j], &board[i][j + 1]);
				eat = max(eat, checkChangeCandy(i, i + 1, j, j + 1, n));
				Swap(&board[i][j], &board[i][j + 1]);
			}

			//열 바꾸기
			if (i + 1 < n) {
				Swap(&board[i][j], &board[i + 1][j]);
				eat = max(eat, checkChangeCandy(i, i + 1, j, j + 1, n));
				Swap(&board[i][j], &board[i + 1][j]);
			}
		}
	}
	printf("%d\n", eat);

	return 0;
}
