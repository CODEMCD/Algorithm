#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define N 51
const int INF = 987654321;
char board[N][N];
//체스판의 패턴은 첫번째 시작이 W일때와 B일때 2가지로 나뉜다.
char pattern[2][9] = { "WBWBWBWB", "BWBWBWBW" };
int patternIdx[2][8] = { {0,1,0,1,0,1,0,1}, {1,0,1,0,1,0,1,0} };

//시작점이 (y, x)일 때 8x8체스판에서 색칠해야할 개수를 반환한다.
//여기서 주의할점은, 첫번째 색깔이 무슨색이든 상관없이 두가지 패턴
//모두 검사해야 한다.(완전탐색)
int countFillBox(int y, int x) {
	//첫번째 패턴
	int count0 = 0;
	for (int i = y, cntcp = 0; i < y + 8; ++i, ++cntcp) {
		for (int j = x, cnt = 0; j < x + 8; ++j, ++cnt) {
			if (pattern[patternIdx[0][cntcp]][cnt] != board[i][j])
				count0++;
		}
	}
	//두번째 패턴
	int count1 = 0;
	for (int i = y, cntcp = 0; i < y + 8; ++i, ++cntcp) {
		for (int j = x, cnt = 0; j < x + 8; ++j, ++cnt) {
			if (pattern[patternIdx[1][cntcp]][cnt] != board[i][j])
				count1++;
		}
	}
	//두가지 패턴 중 색칠한 개수가 적은 쪽을 반환한다.
	return (count0 < count1) ? count0 : count1;
}

int main()
{
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%s", board[i]);

	int ans = INF;
	for(int i = 0; i < n - 7; ++i)
		for (int j = 0; j < m - 7; ++j)
			ans = min(ans, countFillBox(i, j));
		
	printf("%d\n", ans);

	return 0;
}
