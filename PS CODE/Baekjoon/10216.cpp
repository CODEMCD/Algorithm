#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define N 5000
vector<int> v[N];
vector<int> g[N];
int check[N];

void dfs(int now)
{
	check[now] = true;
	for (int i = 0; i < g[now].size(); i++) {
		int next = g[now][i];
		if (!check[next])
			dfs(next);
	}
}

int main(void)
{
	int t;
	scanf("%d", &t);
	while (t--) {
		for (int i = 0; i < N; i++) {
			check[i] = false;
			v[i].clear();
			g[i].clear();
		}
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			int x, y, r;
			scanf("%d %d %d", &x, &y, &r);
			v[i].push_back(x);
			v[i].push_back(y);
			v[i].push_back(r);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				int ix = v[i][0]; int iy = v[i][1]; int ir = v[i][2];
				int jx = v[j][0]; int jy = v[j][1]; int jr = v[j][2];
				double d = (ix - jx) * (ix - jx) + (iy - jy) * (iy - jy);
				double sum = (ir + jr) * (ir + jr);
				bool check = false;
				if (d <= sum)
					check = true;
				if (check) {
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		}
		int group = 0;
		for (int i = 1; i <= n; i++) {
			if (!check[i]) {
				group++;
				dfs(i);
			}
		}
		printf("%d\n", group);
	}

	return 0;
}