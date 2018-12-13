#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define N 1001
//각 좌표에서 상근이가 몇 초후에 도착했는지 저장하는 배열
int dist[N][N];
int my[4] = { -1, 0, 1, 0 };
int mx[4] = { 0, 1, 0, -1 };

int main()
{
	int tc; scanf("%d", &tc);
	while (tc--) {
		memset(dist, 0, sizeof(dist));

		//가로, 세로 입력 주의
		int w, h; scanf("%d %d", &w, &h);
		//입력배열
		char building[N][N];
		for (int i = 0; i < h; ++i)
			scanf("%s", building[i]);

		//상근이의 위치
		int py, px;
		//불의 위치
		vector<pair<int, int>> fv;
		for(int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j) {
				if (building[i][j] == '@') {
					py = i;
					px = j;
				}
				else if (building[i][j] == '*')
					fv.push_back(make_pair(i, j));
			}

		//BFS 한 번으로 모든 경우의 수를 탐색할 수 있다.
		//상근이를 먼저 옮길 수 있는 위치를 BFS를 통해 모두 배열에 추가하고,
		//그 후 불을 옮긴다. 이때, 불은 벽이나 같은 불이 아니면 무조건 옮길 수 있다.(상근이의 위치 포함)
		//BFS는 큐를 사용하기 때문에, 초기값으로 상근이의 위치를 먼저 삽입해주면 어떠한 경우에도
		//상근이의 위치부터 옮기는 것을 보장받을 수 있다.
		//(BFS 동작중 상근이의 위치로 들어온 좌표가 불로 결정되는 경우가 없다.)
		queue<pair<int, int>> q;
		//상근이의 위치를 큐에 먼저 삽입한다.
		q.push({ py, px });
		//그 다음 불의 위치를 삽입한다.
		for (int i = 0; i < fv.size(); ++i)
			q.push({ fv[i].first, fv[i].second });
		int ans = 0;
		while (!q.empty()) {
			int herey = q.front().first;
			int herex = q.front().second;
			q.pop();
			//현재 위치가 상근이인 경우
			if (building[herey][herex] == '@') {
				for (int i = 0; i < 4; ++i) {
					int therey = herey + my[i];
					int therex = herex + mx[i];
					//빈 공간이고, 아직 상근이가 가지 않는 위치면 갈 수 있다.
					if (building[therey][therex] == '.' && !dist[therey][therex]) {
						dist[therey][therex] = dist[herey][herex] + 1;
						building[therey][therex] = '@';
						q.push({ therey, therex });
					}
					//빌딩 좌표 밖으로 나가면 탈출에 성공한다.
					else if (therey < 0 || therey >= h || therex < 0 || therex >= w) {
						ans = dist[herey][herex] + 1;
						break;
					}
				}
			}
			//현재 위치가 불인 경우
			else if (building[herey][herex] == '*') {
				for (int i = 0; i < 4; ++i) {
					int therey = herey + my[i];
					int therex = herex + mx[i];
					//현재 좌표가 빌딩 내부이고, 벽과 불이 아니면 이동할 수 있다.
					if (therey >= 0 && therey < h && therex >= 0 && therex < w)
						if (building[therey][therex] != '#' && building[therey][therex] != '*') {
							building[therey][therex] = '*';
							q.push({ therey, therex });
						}
				}
			}
			if (ans > 0) break;
		}
		if (!ans)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n", ans);
	}

	return 0;
}
