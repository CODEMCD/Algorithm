#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define N 8
int m[N][N];
int nop[N][N];  //등산로 길이 저장 배열
int mx[4] = { -1, 0, 1, 0 };
int my[4] = { 0, 1, 0, -1 };
vector<pair<int, int>> v;
pair<int, int> p;
queue<pair<int, int>> q;
int ans;

//등산로 최대 길이 탐색
void bfs(int n, int h)
{
	for (int i = 0; i < (int)v.size(); i++) {
		if (m[v[i].first][v[i].second] == h)
			q.push(v[i]);
		else
			continue;
		nop[v[i].first][v[i].second] = 1;
		while (!q.empty()) {
			int nowx = q.front().first;
			int nowy = q.front().second;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int nextx = nowx + mx[j];
				int nexty = nowy + my[j];
				if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < n) {
					if (m[nowx][nowy] > m[nextx][nexty] && nop[nowx][nowy] > nop[nextx][nexty]) {
						nop[nextx][nexty] = nop[nowx][nowy] + 1;
						if (nop[nextx][nexty] > ans)
							ans = nop[nextx][nexty];
						p = make_pair(nextx, nexty);
						q.push(p);
					}
				}
			}
		}
		memset(nop, 0, sizeof(nop));
	}
}

int main(void)
{
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		//초기화
		memset(m, 0, sizeof(m));
		ans = 0;
		v.clear();
		//시작
		int n, k;
		scanf("%d %d ", &n, &k);
		int h = 0;  //봉우리 높이
		//봉우리 높이 입력 및 최고 높이 봉우리 길이 저장
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				scanf("%d", &m[i][j]);
				if (h < m[i][j])
					h = m[i][j];
			}
		//최고 높이 봉우리 좌표 vector에 저장
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (m[i][j] == h) {
					p = make_pair(i, j);
					v.push_back(p);
				}
			}
		//초기 등산로 최대 길이
		bfs(n, h);
		//1 ~ k 깊이만큼 모든 등산로에 적용하여 탐색
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int l = 1; l <= k; l++) {
					m[i][j] -= l;
					bfs(n, h);
					m[i][j] += l;
				}
			}
		}
		printf("#%d %d\n", tc, ans);
	}

	return 0;
}