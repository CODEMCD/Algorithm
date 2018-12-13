#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define N 1001
vector<int> g[N];
int time[N];
int dp[N];
int idg[N];
queue<int> q;
#define MAX(a,b) ((a)>(b)?(a):(b))

int main(void)
{
	int t;
	scanf("%d", &t);
	while (t--) {
		for (int i = 0; i < N; i++) {
			g[i].clear();
			time[i] = 0;
			dp[i] = 0;
			idg[i] = 0;
		}
		int n, k;
		scanf("%d %d", &n, &k);
		for (int i = 1; i <= n; i++)
			scanf("%d", &time[i]);
		for (int i = 0; i < k; i++) {
			int from, to;
			scanf("%d %d", &from, &to);
			g[from].push_back(to);
			idg[to]++;
		}
		int d;
		scanf("%d", &d);

		for (int i = 1; i <= n; i++)
			if (idg[i] == 0) {
				q.push(i);
				dp[i] = time[i];
			}
		
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (int i = 0; i < g[now].size(); i++) {
				int next = g[now][i];
				idg[next]--;
				if (idg[next] == 0)
					q.push(next);
				dp[next] = MAX(dp[next], dp[now] + time[next]);
			}
		}

		/*for (int i = 1; i <= n; i++)
			printf("%d ", dp[i]);
		printf("\n");*/
		printf("%d\n", dp[d]);
	}
	
	return 0;
}