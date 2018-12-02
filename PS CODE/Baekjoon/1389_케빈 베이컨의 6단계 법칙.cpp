#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
vector<int> fr[101];
bool visited[101];
int path[101], res[101];

int main(void)
{
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		fr[a].push_back(b);
		fr[b].push_back(a);
	}

	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		memset(visited, false, (n + 1) * sizeof(bool));
		memset(path, 0, (n + 1) * sizeof(int));

		q.push(i);
		visited[i] = true;
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (int j = 0; j < fr[now].size(); ++j) {
				int next = fr[now][j];
				if (!visited[next]) {
					visited[next] = true;
					path[next] = path[now] + 1;
					q.push(next);
				}
			}
		}

		for (int j = 1; j <= n; ++j)
			res[i] += path[j];
	}

	int idx = 1;
	int ans = res[idx];
	for (int i = 2; i <= n; ++i) {
		if (ans > res[i]) {
			ans = res[i];
			idx = i;
		}
	}
	printf("%d\n", idx);

	return 0;
}