#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
vector<int> num[1001];
bool check[1001];
int concom;

void DFS(int node)  //using STACK
{
	check[node] = true;
	for (int i = 0; i < num[node].size(); i++) {
		int next = num[node][i];
		if (check[next] == false)
			DFS(next);
	}
}

int main(void)
{
	int n, m, start = 1;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		num[u].push_back(v);
		num[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
		sort(num[i].begin(), num[i].end());
	DFS(start);
	concom++;
	for (int i = 1; i <= n; i++) {
		if (check[i] == false) {
			DFS(i);
			concom++;
		}
	}
	printf("%d\n", concom);
	return 0;
}