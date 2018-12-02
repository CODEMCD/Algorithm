#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define N 101
int board[N][N];
int dist[N][N];
int my[4] = { -1,0,1,0 };
int mx[4] = { 0,1,0,-1 };

int main(void)
{
	//-1: 아직 한번도 해당 좌표로 오지 못함.
	memset(dist, -1, sizeof(dist));

	int m, n; scanf("%d %d", &m, &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%1d", &board[i][j]);

	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	dist[0][0] = 0;
	while (!q.empty()) {
		int herey = q.front().first;
		int herex = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int therey = herey + my[i];
			int therex = herex + mx[i];
			if (therey >= 0 && therey < n && therex >= 0 && therex < m) {
				//처음 해당 좌표에 도달한 경우
				if (dist[therey][therex] == -1) {
					//벽을 부술때
					if (board[therey][therex])
						dist[therey][therex] = dist[herey][herex] + 1;
					//벽을 부수지 않아도 될때
					else
						dist[therey][therex] = dist[herey][herex];
					q.push({ therey, therex });
				}
				//한번 이상 해당 좌표에 도달한 경우
				else if (dist[therey][therex] >= 0) {
					//벽을 부수고, 벽을 부순 개수가 현재까지 벽을 부순 개수보다 작을때
					if (board[therey][therex] && dist[therey][therex] > dist[herey][herex] + 1) {
						dist[therey][therex] = dist[herey][herex] + 1;
						q.push({ therey, therex });
					}
					//벽을 부수지 않고, 벽을 부순 개수가 현재까지 벽을 부순 개수보다 작을때
					else if (!board[therey][therex] && dist[therey][therex] > dist[herey][herex]) {
						dist[therey][therex] = dist[herey][herex];
						q.push({ therey, therex });
					}
				}
			}
		}
	}
	printf("%d\n", dist[n - 1][m - 1]);

	//다익스트라로 더 빠른 시간안에 해결 가능

	return 0;
}
