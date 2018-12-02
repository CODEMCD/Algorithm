#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define N 51
bool ground[N][N];
bool check[N][N];
int mx[4] = { 1,-1,0,0 };
int my[4] = { 0,0,1,-1 };

int main(void)
{
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(ground, false, sizeof(ground));
		memset(check, false, sizeof(check));
		int m, n, k;
		scanf("%d %d %d", &m, &n, &k);
		for (int i = 0; i < k; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			ground[y][x] = true;
		}
		queue<pair<int, int>> q;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!check[i][j] && ground[i][j]) {
					ans++;
					pair<int, int> p;
					p = make_pair(i, j);
					q.push(p);
					check[i][j] = true;

					while (!q.empty()) {
						int nowy = q.front().first;
						int nowx = q.front().second;
						q.pop();
						for (int k = 0; k < 4; k++) {
							int nexty = nowy + my[k];
							int nextx = nowx + mx[k];
							if (nextx >= 0 && nextx < m && nexty >= 0 && nexty < n) {
								if (ground[nexty][nextx] && !check[nexty][nextx]) {
									check[nexty][nextx] = true;
									p = make_pair(nexty, nextx);
									q.push(p);
								}
							}
						}
					}
				}
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}