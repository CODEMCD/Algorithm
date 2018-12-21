#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
//반대편 방향 인덱스 반환
#define oppositDir(a) (((a) + 2) % 4)
//남동북서
int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };
//wall[y][x][dir]: (y, x)좌표에서 벽이 존재하는 방향(남동북서)에 true값을 저장한다.
bool wall[51][51][4];
//room: 해당 좌표의 방 번호를 저장한다.
//roomSize[i]: i번 방의 크기를 저장한다.
int room[51][51], roomSize[51];
bool visited[51][51];
//해당 벽이 사용됐다면 true
bool visitedWall[51][51][4];

//입력값을 이용해서 벽 정보 저장(남동북서 순서)
void calWall(int y, int x, int num) {
	int idx = 3;
	while (true) {
		if (num == 1) {
			wall[y][x][idx] = true;
			break;
		}
		if (num % 2 == 1)
			wall[y][x][idx] = true;
		num /= 2;
		idx--;
	}
}

int main(void)
{
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j) {
			int wn; scanf("%d", &wn);
			/*
			시간초과 원인 해결
			벽이 없는 칸(0)이 calWall 함수에 매개변수로 사용되면
			무한반복문(while)을 빠져나오지 못한다.
			*/
			if (wn > 0)
				calWall(i, j, wn);
		}

	//방 번호
	int roomCnt = 0;
	//가장 큰 방의 크기
	int maxRoomSize = 0;
	queue<pair<int, int>> q;

	/* 방 번호(방 개수)와 가장 큰 방의 크기를 찾는 BFS */
	for (int y = 0; y < m; ++y) {
		for (int x = 0; x < n; ++x) {
			//이미 방문한 좌표인 경우 다음으로 넘어간다.
			if (visited[y][x]) continue;

			//BFS
			roomCnt++;
			q.push({ y, x });
			visited[y][x] = true;
			room[y][x] = roomCnt;
			int curRoomSize = 1;
			while (!q.empty()) {
				int nowy = q.front().first;
				int nowx = q.front().second;
				q.pop();

				for (int i = 0; i < 4; ++i) {
					int nexty = nowy + dy[i];
					int nextx = nowx + dx[i];

					/* 기저 사례 */
					//배열 크기 밖으로 넘어간 경우
					if (nexty < 0 || nexty >= m || nextx < 0 || nextx >= n)
						continue;
					//이미 방문한 경우
					if (visited[nexty][nextx]) continue;
					//벽이 뚫려있지 않은 경우
					if (wall[nowy][nowx][i] || wall[nexty][nextx][oppositDir(i)])
						continue;

					room[nexty][nextx] = roomCnt;
					visited[nexty][nextx] = true;
					curRoomSize++;
					q.push({ nexty, nextx });
				}
			}
			//해당 방 크기 저장
			roomSize[roomCnt] = curRoomSize;
			//해당 방이 현재까지 저장된 방보다 큰 경우 값을 갱신한다.
			maxRoomSize = maxRoomSize > curRoomSize ? maxRoomSize : curRoomSize;
		}
	}

	/* 하나의 벽을 제거한 경우에 가장 큰 방 찾기 */
	int maxMerge = 0;
	for (int y = 0; y < m; ++y) {
		for (int x = 0; x < n; ++x) {
			for (int k = 0; k < 4; ++k) {
				/* 기저 사례 */
				//이미 제거해봤던 벽인 경우 or 벽이 없는 경우
				if (visitedWall[y][x][k] || !wall[y][x][k]) continue;
				int ny = y + dy[k];
				int nx = x + dx[k];
				//벽 다음 칸이 배열 범위 밖인 경우
				if (ny < 0 || ny >= m || nx < 0 || nx >= n)
					continue;
				//벽 다음 칸이 현재 칸과 같은 방인 경우
				if (room[y][x] == room[ny][nx])
					continue;

				//방문 표시
				visitedWall[y][x][k] = true;
				visitedWall[ny][nx][oppositDir(k)] = true;
				//벽을 제거하기 전 상황에서 현재 방과 벽 넘어 방의 크기를 더한다.
				int curRoomSize = roomSize[room[y][x]] + roomSize[room[ny][nx]];
				//크기가 큰 방으로 값으르 갱신한다.
				maxMerge = maxMerge > curRoomSize ? maxMerge : curRoomSize;
			}
		}
	}

	printf("%d\n%d\n%d\n", roomCnt, maxRoomSize, maxMerge);

	return 0;
}