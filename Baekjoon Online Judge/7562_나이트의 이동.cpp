#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define N 301
int board[N][N];
int dist[N][N];
//나이트 이동
int my[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int mx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int main()
{
	int tc; scanf("%d", &tc);
	while (tc--) {
		memset(board, 0, sizeof(board));
		memset(dist, 0, sizeof(dist));

		int l; scanf("%d", &l);
		int sy, sx, ey, ex;
		scanf("%d %d", &sy, &sx);
		scanf("%d %d", &ey, &ex);

		//BFS
		queue<pair<int, int>> q;
		q.push(make_pair(sy, sx));
		while (!q.empty()) {
			int herey = q.front().first;
			int herex = q.front().second;
			q.pop();

			//도착 지점에 온 경우
			if (herey == ey && herex == ex) break;

			for (int i = 0; i < 8; ++i) {
				int therey = herey + my[i];
				int therex = herex + mx[i];
				if (therey >= 0 && therey < l && therex >= 0 && therex < l
					&& dist[therey][therex] == 0) {
					dist[therey][therex] = dist[herey][herex] + 1;
					q.push(make_pair(therey, therex));
				}
			}
		}
		printf("%d\n", dist[ey][ex]);
	}

	return 0;
}
