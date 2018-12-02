#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define N 9
//입력 벡터
vector<vector<int>> map;
//바이러스 좌표 벡터: 바이러스가 퍼지는 BFS알고리즘을 사용하기 위함
vector<pair<int, int>> pv;
//빈칸 좌표 벡터: 벽 3개를 세우는 모든 경우의 수를 계산하기 위함
vector<pair<int, int>> ev;
//상, 우, 하, 좌
int my[4] = { -1, 0, 1, 0 };
int mx[4] = { 0, 1, 0, -1 };
int n, m;

//BFS로 모든 바이러스가 퍼지는 결과를 계산한 후
//이 결과에서 빈칸의 최대 개수를 찾는다.
int bfsAndCalMax(vector<vector<int>> curMap) {
	queue<pair<int, int>> q;
	for (int i = 0; i < pv.size(); ++i)
		q.push({ pv[i].first, pv[i].second });
	while (!q.empty()) {
		int herey = q.front().first;
		int herex = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int therey = herey + my[i];
			int therex = herex + mx[i];
			if (therey >= 0 && therey < n && therex >= 0 && therex < m
				&& !curMap[therey][therex]) {
				curMap[therey][therex] = 2;
				q.push({ therey, therex });
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (!curMap[i][j])
				cnt++;
	return cnt;
}

int main(void)
{
	scanf("%d %d", &n, &m);
	map = vector<vector<int>>(n, vector<int>(m));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0)
				ev.push_back(make_pair(i, j));
			else if (map[i][j] == 2)
				pv.push_back(make_pair(i, j));
		}

	int eSize = ev.size();
	int ans = 0;
	//3개의 벽을 세우는 모든 경우의 수(완전 탐색 + BFS)
	//최대 시간복잡도는 O(N^5)이며, N은 빈칸의 개수이다.
	//여기서 바이러스와 벽이 있으므로 N의 최대 크기는 64보다 작은 것이 보장되므로
	//2초안에 해결이 되는듯 하다.
	for (int i = 0; i < eSize; ++i)
		for (int j = i + 1; j < eSize; ++j)
			for (int k = j + 1; k < eSize; ++k) {
				map[ev[i].first][ev[i].second] = 1;
				map[ev[j].first][ev[j].second] = 1;
				map[ev[k].first][ev[k].second] = 1;
				//벽을 3개 세운 후, 빈칸의 최대 개수를 계산한다.
				ans = max(ans, bfsAndCalMax(map));
				map[ev[i].first][ev[i].second] = 0;
				map[ev[j].first][ev[j].second] = 0;
				map[ev[k].first][ev[k].second] = 0;
			}
	printf("%d\n", ans);

	return 0;
}
