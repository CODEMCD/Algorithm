#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define N 201
const int INF = 987654321;
//입력 격자판
int board[N][N];
//말 이동을 사용한 횟수에 따른 최소 거리 저장
//-1로 초기화한다.
int dist[31][N][N];
//위 방향부터 반시계 방향 순서
//말 이동
int hmy[8] = { -2,-1,1,2,2,1,-1,-2 };
int hmx[8] = { 1,2,2,1,-1,-2,-2,-1 };
//원숭이 이동
int my[4] = { -1,0,1,0 };
int mx[4] = { 0,1,0,-1 };

//원숭이 상태
typedef struct _monkeyState
{
	int y, x;      //위치
	int horseCnt;  //말 이동 사용 횟수
} state;

int main()
{
	memset(dist, -1, sizeof(dist));
	int k, w, h;
	scanf("%d", &k);
	//가로, 세로 입력 주의
	scanf("%d %d", &w, &h);
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			scanf("%d", &board[i][j]);

	queue<state> q;
	// (0, 0) 시작
	q.push({ 0,0,0 });
	dist[0][0][0] = 0;
	while (!q.empty()) {
		state here = q.front();
		q.pop();
		//말 이동을 사용할 수 있을 때
		//말 이동은 장애물을 통과할 수 있다.(도착지점에만 장애물이 없으면 된다.
		if (here.horseCnt < k) {
			for (int i = 0; i < 8; ++i) {
				state there;
				there.y = here.y + hmy[i];
				there.x = here.x + hmx[i];
				//말 이동 횟수를 1 늘려준다.
				there.horseCnt = here.horseCnt + 1;
				if (!board[there.y][there.x] && there.y >= 0 && there.y < h
					&& there.x >= 0 && there.x < w) {
					//말 이동을 사용한 후의 dist배열에서 이동한 적이 없다면
					if (dist[there.horseCnt][there.y][there.x] == -1) {
						//말 이동 전의 dist배열에서 거리 1을 더하여 현재 말이동 횟수 dist배열에 갱신한다.
						dist[there.horseCnt][there.y][there.x] = dist[here.horseCnt][here.y][here.x] + 1;
						q.push({ there.y, there.x, there.horseCnt });
					}
				}
			}
		}
		//원숭이 이동은 장애물만 없다면 무조건 이동 가능하다.
		for (int i = 0; i < 4; ++i) {
			state there;
			there.y = here.y + my[i];
			there.x = here.x + mx[i];
			there.horseCnt = here.horseCnt;
			if (!board[there.y][there.x] && there.y >= 0 && there.y < h
				&& there.x >= 0 && there.x < w) {
				if (dist[there.horseCnt][there.y][there.x] == -1) {
					dist[there.horseCnt][there.y][there.x] = dist[here.horseCnt][here.y][here.x] + 1;
					q.push({ there.y, there.x, there.horseCnt });
				}
			}
		}
	}

	//dist[][]배열들의 맨아래쪽의 인덱스 중 가장 작은 값이 해답이다.(이동할 수 있다는 가정하에)
	int ans = INF;
	for (int i = 0; i <= k; ++i)
		if(dist[i][h - 1][w - 1] != -1)
			ans = min(ans, dist[i][h - 1][w - 1]);
	printf("%d\n", (ans == INF) ? -1 : ans);

	return 0;
}
