#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define N 501
int board[N][N];
//테트로미노가 될 수 있는 모든 경우의 수
int tetrominoy[19][4] = { {0,1,2,3}, {0,0,0,0}, {0,0,1,1},
{0,1,2,2}, {0,0,0,1}, {0,0,1,2}, {0,0,0,1}, {0,1,2,2}, {0,1,1,1},
{0,0,1,2}, {0,1,1,1}, {0,1,1,2}, {1,1,0,0}, {0,1,1,2}, {0,0,1,1},
{0,0,0,1}, {0,1,2,1}, {1,1,1,0}, {1,0,1,2} };
int tetrominox[19][4] = { {0,0,0,0}, {0,1,2,3}, {0,1,1,0},
{0,0,0,1}, {2,1,0,0}, {0,1,1,1}, {0,1,2,2}, {0,0,0,-1}, {0,0,1,2},
{1,0,0,0}, {2,2,1,0}, {0,0,1,1}, {0,1,1,2}, {1,1,0,0}, {0,1,1,2},
{0,1,2,1}, {0,0,0,1}, {0,1,2,1}, {0,1,1,1} };

int main()
{
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d", &board[i][j]);

	int ans = 0;
	for (int y = 0; y < n; ++y)
		for (int x = 0; x < m; ++x)
			for (int i = 0; i < 19; ++i) {
				int flag = true;
				int add = 0;
				//해당 테트로미노가 보드안에 모두 들어가는지 검사
				for (int j = 0; j < 4; ++j) {
					int ny = y + tetrominoy[i][j];
					int nx = x + tetrominox[i][j];
					if (ny < 0 || ny >= n || nx < 0 || nx >= m)
						flag = false;
					else
						add += board[ny][nx];
				}
				if (flag)
					ans = max(ans, add);
			}

	printf("%d\n", ans);

	return 0;
}
