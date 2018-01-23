#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
#define N 1001
int tomato[N][N];
bool check[N][N];
int dist[N][N];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int n, m, day, cnt;
queue<pair<int, int>> que, que2;

void bfs(int x, int y)
{
	check[x][y] = true;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (0 <= nx && nx < n && 0 <= ny && ny < m) {
			if (check[nx][ny] == false && tomato[nx][ny] == 0) {
				tomato[nx][ny] = 1;
				que2.push(make_pair(nx, ny));
			}
		}
	}
}

int main(void)
{
	for (int i = 0; i < N; i++)
		memset(check[i], false, sizeof(int) * N);
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &tomato[i][j]);
			if(tomato[i][j] == 1)
				que.push(make_pair(i, j));
		}

	while (1) {
		cnt = 0;
		while (!que.empty()) {
			bfs(que.front().first, que.front().second);
			que.pop();
		}
		while (!que2.empty()) {
			que.push(make_pair(que2.front().first, que2.front().second));
			que2.pop();
			cnt++;
		}
		if (cnt == 0)
			break;
		day++;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (tomato[i][j] == 0)
				day = -1;
	printf("%d\n", day);
	return 0;
}