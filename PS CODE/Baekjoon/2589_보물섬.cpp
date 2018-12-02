#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define N 51
char map[N][N];
int my[4] = { -1, 0, 1, 0 };
int mx[4] = { 0, 1, 0, -1 };

int main()
{
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%s", map[i]);

	//최대값 저장
	int ans = 0;
	//모든 육지 좌표에서 BFS탐색으로 최대 거리를 계산한다.
	//최대 정점 개수 250개, 시간복잡도: O(V^3)
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (map[i][j] == 'L') {
				int dist[N][N] = { 0, };
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				while (!q.empty()) {
					int herey = q.front().first;
					int herex = q.front().second;
					q.pop();
					for (int k = 0; k < 4; ++k) {
						int therey = herey + my[k];
						int therex = herex + mx[k];
						if (map[therey][therex] == 'L' && therey >= 0 &&
							therey < n && therex >= 0 && therex < m &&
							!dist[therey][therex]) {
							dist[therey][therex] = dist[herey][herex] + 1;
							q.push({ therey, therex });
							ans = max(ans, dist[therey][therex]);
						}
					}
				}
			}
	printf("%d\n", ans);

	return 0;
}
