#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
#define N 101
int map[N][N];
bool check[N][N];
int mx[2] = { 1,0 };
int my[2] = { 0,1 };

int main(void)
{
	int c;
	scanf("%d", &c);
	while (c--) {
		for(int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				map[i][j] = 0;
				check[i][j] = false;
			}
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &map[i][j]);
		queue<pair<int, int>> q;
		pair<int, int> p;
		p = make_pair(0, 0);
		check[0][0] = true;
		q.push(p);
		bool early = false;
		while (!q.empty()) {
			int nowx = q.front().first;
			int nowy = q.front().second;
			q.pop();
			for (int i = 0; i < 2; i++) {
				int nextx = nowx + map[nowy][nowx] * mx[i];
				int nexty = nowy + map[nowy][nowx] * my[i];
				if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < n) {
					if (nextx == n - 1 && nexty == n - 1) {
						check[nexty][nextx] = true;
						early = true;
						break;
					}
					if (!check[nexty][nextx]) {
						check[nexty][nextx] = true;
						p = make_pair(nextx, nexty);
						q.push(p);
					}
				}
			}
			if (early)
				break;
		}
		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				printf("%d ", check[i][j]);
			printf("\n");
		}*/
		if (check[n - 1][n - 1])
			printf("YES\n");
		else
			printf("NO\n");
		while (!q.empty())
			q.pop();
	}
	
	return 0;
}