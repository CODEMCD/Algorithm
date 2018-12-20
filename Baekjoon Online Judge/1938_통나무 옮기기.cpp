#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
//right, down, left, up
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
char yard[52][52];
/*
visited[y][x][d]: 통나무의 좌표가 (y, x)이고 방향이 d(수평: 0, 수직: 1)인 
				상태로 방문한 좌표에 true값을 입력한다.
*/
bool visited[51][51][2];
int n;

//통나무 좌표(3개)
typedef struct _log {
	pair<int, int> lpos[3];
} Log;

//통나무 방향이 수평(0)인지 수직(1)인지 반환한다.
int horiver(Log cur) {
	//수평인 경우
	if (cur.lpos[0].first == cur.lpos[1].first && cur.lpos[1].first  == cur.lpos[2].first)
		return 0;
	//수직인 경우
	else if (cur.lpos[0].second == cur.lpos[1].second && cur.lpos[1].second == cur.lpos[2].second)
		return 1;
	return -1;
}

//현재 통나무를 입력된 방향으로 한 칸 움직일 수 있다면, TRUE를 반환하고 좌표를 옮겨준다.
bool moveLRDU(Log *cur, int dir) {
	//입력된 방향으로 한 칸 이동한 통나무 좌표
	pair<int, int> next[3];
	next[0].first = cur->lpos[0].first + dy[dir];
	next[0].second = cur->lpos[0].second + dx[dir];
	next[1].first = cur->lpos[1].first + dy[dir];
	next[1].second = cur->lpos[1].second + dx[dir];
	next[2].first = cur->lpos[2].first + dy[dir];
	next[2].second = cur->lpos[2].second + dx[dir];
	//주어진 평지 범위를 벗어난 경우 FALSE 반환
	if (next[0].first < 0 || next[0].first >= n ||
		next[0].second < 0 || next[0].second >= n ||
		next[1].first < 0 || next[1].first >= n ||
		next[1].second < 0 || next[1].second >= n ||
		next[2].first < 0 || next[2].first >= n ||
		next[2].second < 0 || next[2].second >= n)
		return false;
	//움직인 좌표에 다른 나무가 있는 경우 FALSE 반환
	if (yard[next[0].first][next[0].second] == '1' ||
		yard[next[1].first][next[1].second] == '1' ||
		yard[next[2].first][next[2].second] == '1')
		return false;
	//움직일 수 있는 경우 실제 좌표를 움직인다.
	cur->lpos[0].first += dy[dir];
	cur->lpos[0].second += dx[dir];
	cur->lpos[1].first += dy[dir];
	cur->lpos[1].second += dx[dir];
	cur->lpos[2].first += dy[dir];
	cur->lpos[2].second += dx[dir];
	return true;
}

//현재 통나무를 90도 회전할 수 있는 경우 TRUE를 반환하고 회전한 좌표를 입력한다.
bool moveRotate(Log *cur) {
	//수평통나무
	if (horiver(*cur) == 0) {
		//회전 반경이 평지 범위를 벗어나거나 다른 나무가 존재하면 FALSE를 반환한다.
		for (int i = cur->lpos[0].first - 1; i <= cur->lpos[0].first + 1; ++i)
			for (int j = cur->lpos[0].second; j <= cur->lpos[2].second; ++j)
				if (i < 0 || i >= n || j < 0 || j >= n || yard[i][j] == '1')
					return false;
		cur->lpos[0].first = cur->lpos[0].first - 1;
		cur->lpos[0].second = cur->lpos[0].second + 1;
		cur->lpos[2].first = cur->lpos[2].first + 1;
		cur->lpos[2].second = cur->lpos[2].second - 1;
		return true;
	}
	//수직통나무
	else if (horiver(*cur) == 1) {
		for (int i = cur->lpos[0].first; i <= cur->lpos[2].first; ++i)
			for (int j = cur->lpos[0].second - 1; j <= cur->lpos[0].second + 1; ++j)
				if (i < 0 || i >= n || j < 0 || j >= n || yard[i][j] == '1')
					return false;
		cur->lpos[0].first = cur->lpos[0].first + 1;
		cur->lpos[0].second = cur->lpos[0].second - 1;
		cur->lpos[2].first = cur->lpos[2].first - 1;
		cur->lpos[2].second = cur->lpos[2].second + 1;
		return true;
	}
	return false;
}

int main(void)
{
	scanf("%d", &n);
	Log b, e;
	int bcnt = 0, ecnt = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%s", yard[i]);
		for (int j = 0; j < n; ++j) {
			if (yard[i][j] == 'B')
				b.lpos[bcnt++] = { i, j };
			else if (yard[i][j] == 'E')
				e.lpos[ecnt++] = { i, j };
		}
	}

	//(통나무 좌표(3개), 움직인 횟수)
	queue<pair<Log, int>> q;
	q.push({ b, 0 });
	//시작 통나무 좌표와 통나무 방향 방문 표시
	visited[b.lpos[0].first][b.lpos[0].second][horiver(b)] = true;
	visited[b.lpos[1].first][b.lpos[1].second][horiver(b)] = true;
	visited[b.lpos[2].first][b.lpos[2].second][horiver(b)] = true;
	int ans = 0;
	while (!q.empty()) {
		Log now = q.front().first;
		int nowCnt = q.front().second;
		q.pop();

		//현재 통나무가 최종위치와 일치한 경우
		if (now.lpos[0].first == e.lpos[0].first && now.lpos[0].second == e.lpos[0].second &&
			now.lpos[1].first == e.lpos[1].first && now.lpos[1].second == e.lpos[1].second &&
			now.lpos[2].first == e.lpos[2].first && now.lpos[2].second == e.lpos[2].second) {
			ans = nowCnt;
			break;
		}

		Log next;
		//현재 통나무를 상하좌우로 움직일 수 있는지 검사한다.
		for (int i = 0; i < 4; ++i) {
			next = now;
			//입력된 방향으로 움직일 수 있고, 해당 통나무 좌표와 방향 중 한 좌표라도 방문할 수 있는 경우
			if (moveLRDU(&next, i) && (!visited[next.lpos[0].first][next.lpos[0].second][horiver(next)]
				|| !visited[next.lpos[1].first][next.lpos[1].second][horiver(next)]
				|| !visited[next.lpos[2].first][next.lpos[2].second][horiver(next)])) {
				//방문 표시
				visited[next.lpos[0].first][next.lpos[0].second][horiver(next)] = true;
				visited[next.lpos[1].first][next.lpos[1].second][horiver(next)] = true;
				visited[next.lpos[2].first][next.lpos[2].second][horiver(next)] = true;
				//큐에 삽입
				q.push({ next, nowCnt + 1 });
			}
		}

		//현재 통나무를 90도 회전한다.
		next = now;
		if (moveRotate(&next) && (!visited[next.lpos[0].first][next.lpos[0].second][horiver(next)]
			|| !visited[next.lpos[1].first][next.lpos[1].second][horiver(next)]
			|| !visited[next.lpos[2].first][next.lpos[2].second][horiver(next)])) {
			visited[next.lpos[0].first][next.lpos[0].second][horiver(next)] = true;
			visited[next.lpos[1].first][next.lpos[1].second][horiver(next)] = true;
			visited[next.lpos[2].first][next.lpos[2].second][horiver(next)] = true;
			q.push({ next, nowCnt + 1 });
		}
	}

	printf("%d\n", ans);

	return 0;
}