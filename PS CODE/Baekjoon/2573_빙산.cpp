#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define N 301
//입력배열
int sea[N][N];
//연도별 해당좌표에서 빙하가 녹는 양
int nmelt[N][N];
//dfs에서 빙하에 방문했는지 여부를 저장하는 배열
bool visited[N][N];
//위에서부터 시계방향
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
//visitedIce: 방문한 빙하의 개수
int n, m, visitedIce;

//한 덩어리 빙하를 모두 방문하기 위한 dfs
void dfs(int y, int x) {
	visited[y][x] = true;
	visitedIce++;
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 0 && ny < n && nx >= 0 && nx < m)
			if (sea[ny][nx] > 0 && !visited[ny][nx])
				dfs(ny, nx);
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d", &sea[i][j]);

	int year = 1;
	//두 덩어리 이상으로 분리됐는지의 여부
	bool spFlag = false;
	while (true) {
		memset(nmelt, 0, sizeof(nmelt));
		memset(visited, false, sizeof(visited));
		visitedIce = 0;

		//각 빙하가 녹을 양 계산
		for (int y = 0; y < n; ++y)
			for (int x = 0; x < m; ++x)
				if (sea[y][x] > 0) {
					for (int k = 0; k < 4; ++k) {
						int ny = y + dy[k];
						int nx = x + dx[k];
						if (ny >= 0 && ny < n && nx >= 0 && nx < m
							&& !sea[ny][nx])
							nmelt[y][x] += 1;
					}
				}
		//녹지 않고 남아있는 빙하의 개수
		int nIce = 0;
		//녹지 않은 한 빙하의 좌표
		int chy, chx;
		//빙하 녹이기
		for (int y = 0; y < n; ++y)
			for (int x = 0; x < m; ++x) {
				sea[y][x] -= nmelt[y][x];
				if (sea[y][x] > 0) {
					nIce++;
					chy = y; chx = x;
				}
				//0 미만일 때는 0으로 해준다
				else
					sea[y][x] = 0;
			}
		//다 녹아버린 경우
		if (nIce == 0)
			break;

		//빙하의 한 덩어리를 모두 방문한다.
		dfs(chy, chx);
		
		//한 덩어리의 빙하를 모두 방문했는데
		//현재 빙하의 개수보다 적다면, 현재 빙하는 두 덩어리 이상으로
		//분리되어있다고 판단한다.
		if (nIce != visitedIce) {
			spFlag = true;
			break;
		}

		year++;
	}

	printf("%d\n", spFlag ? year : 0);

	return 0;
}
