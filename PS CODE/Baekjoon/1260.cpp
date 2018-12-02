#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
vector<int> num[1001];
bool check[1001];

void DFS(int node)  //using STACK
{
	check[node] = true;
	printf("%d ", node);
	for (int i = 0; i < num[node].size(); i++) {
		int next = num[node][i];
		if (check[next] == false)
			DFS(next);
	}
}

void BFS(int start)  //using QUEUE
{
	queue<int> que;
	memset(check, false, sizeof(check));
	check[start] = true;
	que.push(start);
	while (!que.empty()) {
		int node = que.front();
		que.pop();
		printf("%d ", node);
		for (int i = 0; i < num[node].size(); i++) {
			int next = num[node][i];
			if (check[next] == false) {
				check[next] = true;
				que.push(next);
			}
		}
	}
}

//인접리스트를 이용한 DFS, BFS(feat, C++ STL)
int main(void)
{
	int n, m, start;
	scanf("%d %d %d", &n, &m, &start);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		num[u].push_back(v);
		num[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
		sort(num[i].begin(), num[i].end());
	DFS(start);
	printf("\n");
	BFS(start);
	printf("\n");

	return 0;
}