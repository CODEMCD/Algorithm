#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
//�ݴ��� ���� �ε��� ��ȯ
#define oppositDir(a) (((a) + 2) % 4)
//�����ϼ�
int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };
//wall[y][x][dir]: (y, x)��ǥ���� ���� �����ϴ� ����(�����ϼ�)�� true���� �����Ѵ�.
bool wall[51][51][4];
//room: �ش� ��ǥ�� �� ��ȣ�� �����Ѵ�.
//roomSize[i]: i�� ���� ũ�⸦ �����Ѵ�.
int room[51][51], roomSize[51];
bool visited[51][51];
//�ش� ���� ���ƴٸ� true
bool visitedWall[51][51][4];

//�Է°��� �̿��ؼ� �� ���� ����(�����ϼ� ����)
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
			�ð��ʰ� ���� �ذ�
			���� ���� ĭ(0)�� calWall �Լ��� �Ű������� ���Ǹ�
			���ѹݺ���(while)�� ���������� ���Ѵ�.
			*/
			if (wn > 0)
				calWall(i, j, wn);
		}

	//�� ��ȣ
	int roomCnt = 0;
	//���� ū ���� ũ��
	int maxRoomSize = 0;
	queue<pair<int, int>> q;

	/* �� ��ȣ(�� ����)�� ���� ū ���� ũ�⸦ ã�� BFS */
	for (int y = 0; y < m; ++y) {
		for (int x = 0; x < n; ++x) {
			//�̹� �湮�� ��ǥ�� ��� �������� �Ѿ��.
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

					/* ���� ��� */
					//�迭 ũ�� ������ �Ѿ ���
					if (nexty < 0 || nexty >= m || nextx < 0 || nextx >= n)
						continue;
					//�̹� �湮�� ���
					if (visited[nexty][nextx]) continue;
					//���� �շ����� ���� ���
					if (wall[nowy][nowx][i] || wall[nexty][nextx][oppositDir(i)])
						continue;

					room[nexty][nextx] = roomCnt;
					visited[nexty][nextx] = true;
					curRoomSize++;
					q.push({ nexty, nextx });
				}
			}
			//�ش� �� ũ�� ����
			roomSize[roomCnt] = curRoomSize;
			//�ش� ���� ������� ����� �溸�� ū ��� ���� �����Ѵ�.
			maxRoomSize = maxRoomSize > curRoomSize ? maxRoomSize : curRoomSize;
		}
	}

	/* �ϳ��� ���� ������ ��쿡 ���� ū �� ã�� */
	int maxMerge = 0;
	for (int y = 0; y < m; ++y) {
		for (int x = 0; x < n; ++x) {
			for (int k = 0; k < 4; ++k) {
				/* ���� ��� */
				//�̹� �����غô� ���� ��� or ���� ���� ���
				if (visitedWall[y][x][k] || !wall[y][x][k]) continue;
				int ny = y + dy[k];
				int nx = x + dx[k];
				//�� ���� ĭ�� �迭 ���� ���� ���
				if (ny < 0 || ny >= m || nx < 0 || nx >= n)
					continue;
				//�� ���� ĭ�� ���� ĭ�� ���� ���� ���
				if (room[y][x] == room[ny][nx])
					continue;

				//�湮 ǥ��
				visitedWall[y][x][k] = true;
				visitedWall[ny][nx][oppositDir(k)] = true;
				//���� �����ϱ� �� ��Ȳ���� ���� ��� �� �Ѿ� ���� ũ�⸦ ���Ѵ�.
				int curRoomSize = roomSize[room[y][x]] + roomSize[room[ny][nx]];
				//ũ�Ⱑ ū ������ ������ �����Ѵ�.
				maxMerge = maxMerge > curRoomSize ? maxMerge : curRoomSize;
			}
		}
	}

	printf("%d\n%d\n%d\n", roomCnt, maxRoomSize, maxMerge);

	return 0;
}