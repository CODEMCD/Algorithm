#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define N 1001
vector<int> v[N];
bool check[N];

void DFS(int node)
{
	check[node] = true;
	//printf("%d ", node);
	for (int i = 0; i < v[node].size(); i++) {
		int next = v[node][i];
		if (check[next] == false)
			DFS(next);
	}
}

int main(void)
{
	int t, n, circle;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		circle = 0;
		memset(check, false, sizeof(check));
		scanf("%d", &n);
		for (int j = 1; j <= n; j++) {
			int u;
			scanf("%d", &u);
			v[j].push_back(u);
		}
		for (int k = 1; k <= n; k++)
			sort(v[k].begin(), v[k].end());
		for (int h = 1; h <= n; h++) {
			if (check[h] == false) {
				DFS(h);
				circle++;
			}
		}
		printf("%d\n", circle);
		for (int p = 1; p <= n; p++)
			v[p].clear();
	}
	return 0;
}
