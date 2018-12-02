#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define N 1001
const int INF = 987654321;
//입력 배열
int map[N][N];
//[y][x][0]: 벽을 부수지 않았을 때, (y,x)까지 거리
//[y][x][1]: 벽을 부쉈을 때, (y,x)까지 거리
//초기값일 때는 방문하지 않음
int dist[N][N][2];

typedef struct _point
{
	int y, x;        //좌표
	bool boolWall;   //벽 부순 여부
} point;

//상,우,하,좌(시계방향)
int my[4] = { -1, 0, 1, 0 };
int mx[4] = { 0, 1, 0, -1 };

int main()
{
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%1d", &map[i][j]);

	queue<point> q;
	q.push({ 0,0,false });
	//처음 시작도 포함
	dist[0][0][0] = 1;
	dist[0][0][1] = 1;
	int ans = INF;
	while (!q.empty()) {
		int herey = q.front().y;
		int herex = q.front().x;
		bool nWall = q.front().boolWall;
		q.pop();
		//마지막 지점에 도달했을 때, 거리를 계산할 수 있다면 그 중 최소값을 저장
		if (herey == n - 1 && herex == m - 1) {
			if (dist[herey][herex][0])
				ans = min(ans, dist[herey][herex][0]);
			if (dist[herey][herex][1])
				ans = min(ans, dist[herey][herex][1]);
		}
		//상하좌우로 움직였을 때, 거리를 계산할 수 있다면 큐에 삽입한다.
		for (int i = 0; i < 4; ++i) {
			int therey = herey + my[i];
			int therex = herex + mx[i];
			if (therey >= 0 && therey < n && therex >= 0 && therex < m) {
				// 1) 다음 좌표로 움직일 수 있고, 현재 좌표에서 벽을 부수지 않은 상태이며, 다음 좌표에 방문하지 않았을 때
				if (!map[therey][therex] && !nWall && !dist[therey][therex][0]) {
					dist[therey][therex][0] = dist[herey][herex][0] + 1;
					q.push({ therey, therex, false });
				}
				// 2) 다음 좌표로 움직일 수 있고, 현재 좌표에서 벽을 부순 상태이며, 다음 좌표를 방문하지 않았을 때
				else if (!map[therey][therex] && nWall && !dist[therey][therex][1]) {
					dist[therey][therex][1] = dist[herey][herex][1] + 1;
					q.push({ therey, therex, true });
				}
				// 3) 다음 좌표는 벽이고, 현재 좌표에서 벽을 부순 상태이며, 다음 좌표를 방문하지 않았을 때
				else if (map[therey][therex] && !nWall && !dist[therey][therex][1]) {
					//벽을 부수지 않은 거리 배열에서 넘어가 계산해준다.
					dist[therey][therex][1] = dist[herey][herex][0] + 1;
					q.push({ therey, therex, true });
				}
			}
		}
	}
	printf("%d\n", ans == INF ? -1 : ans);

	return 0;
}

/*
참고 테스트 케이스
입력
5 8
01000000
01010000
01010000
01010011
00010010

출력
20
*/
