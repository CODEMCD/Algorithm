#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int map[101][101];
bool check[101][101], visited[101];
int s, n;

void dfs(int v) {
	for (int i = 0; i < n; ++i) {
		if (map[v][i] && !visited[i]) {
			visited[i] = true;
			check[s][i] = true;
			dfs(i);
		}
	}
}

int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &map[i][j]);

	for (int i = 0; i < n; ++i) {
		s = i;
		dfs(i);
		for (int j = 0; j < n; ++j)
			visited[j] = false;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			printf("%d ", check[i][j]);
		printf("\n");
	}

	return 0;
}