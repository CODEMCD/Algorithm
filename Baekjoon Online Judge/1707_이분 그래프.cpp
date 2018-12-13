#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define N 20001
vector<int> g[N];
queue<int> q;
bool check1[N];
bool check2[N];

int main(void)
{
	int k;
	scanf("%d", &k);
	while (k--) {
		for (int i = 0; i < N; i++) {
			g[i].clear();
			check1[i] = false;
			check2[i] = false;
		}
		while (!q.empty())
			q.pop();
		int v, e;
		scanf("%d %d", &v, &e);
		for (int i = 0; i < e; i++) {
			int v1, v2;
			scanf("%d %d", &v1, &v2);
			g[v1].push_back(v2);
			g[v2].push_back(v1);
		}
		int ans = true;
		for (int i = 1; i <= v; i++) {
			if (!check1[i] && !check2[i])
				check1[i] = true;
			else
				continue;
			q.push(i);
			while (!q.empty()) {
				int now = q.front();
				q.pop();
				for (int j = 0; j < g[now].size(); j++) {
					int next = g[now][j];
					if (check1[now] && !check2[next]) {
						check2[next] = true;
						q.push(next);
					}
					else if (check2[now] && !check1[next]) {
						check1[next] = true;
						q.push(next);
					}
					else if (check1[now] && check1[next])
						ans = false;
					else if (check2[now] && check2[next])
						ans = false;
				}
			}
		}
		if (ans)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}