#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define N 100001
vector<int> tree[N];
queue<int> q;
bool check[N];
int dis[N];

void bfs(int x)
{
	q.push(x);
	while (!q.empty()) {
		int next = q.front();
		q.pop();
		for (int i = 0; i < tree[next].size(); i++) {
			if (i == 0 || i % 2 == 0) {
				if (check[tree[next][i]] == false) {
					dis[tree[next][i]] = dis[next] + tree[next][i + 1];
					//printf("%d + %d = %d\n", dis[next], tree[next][i + 1], dis[tree[next][i]]);
					check[next] = true;
					q.push(tree[next][i]);
				}
			}
		}
	}
}
int main(void)
{
	int v;
	scanf("%d", &v);
	for (int i = 0; i < v; i++) {
		int nv;
		scanf("%d", &nv);
		while (1) {
			int n;
			scanf("%d", &n);
			if (n == -1)
				break;
			tree[nv].push_back(n);
		}
	}
	bfs(1);
	//for (int i = 1; i <= v; i++)
	//	printf("%d ", dis[i]);
	//cout << endl;
	int max = 0, far;
	for (int i = 1; i <= v; i++)
		if (max < dis[i]) {
			max = dis[i];
			far = i;
		}

	memset(check, false, sizeof(check));
	memset(dis, 0, sizeof(dis));
	bfs(far);
	//for (int i = 1; i <= v; i++)
	//	printf("%d ", dis[i]);
	//cout << endl;
	for (int i = 1; i <= v; i++)
		if (max < dis[i])
			max = dis[i];
	printf("%d\n", max);
	return 0;
}