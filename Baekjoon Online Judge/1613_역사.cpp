#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
vector<int> order[401], rev[401];
vector<int> orderPath[401], revPath[401];
bool visited[401];

void orderDfs(int s, int v) {
	visited[v] = true;

	for (int i = 0; i < (int)order[v].size(); ++i) {
		int next = order[v][i];
		if (!visited[next]) {
			orderPath[s].push_back(next);
			orderDfs(s, next);
		}
	}
}

void revDfs(int s, int v) {
	visited[v] = true;

	for (int i = 0; i < (int)rev[v].size(); ++i) {
		int next = rev[v][i];
		if (!visited[next]) {
			revPath[s].push_back(next);
			revDfs(s, next);
		}
	}
}

int main(void)
{
	int n, k; scanf("%d %d", &n, &k);
	for (int i = 0; i < k; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		order[a].push_back(b);
		rev[b].push_back(a);
	}

	for (int i = 1; i <= n; ++i) {
		orderDfs(i, i);
		for (int j = 0; j <= n; ++j)
			visited[j] = false;

		revDfs(i, i);
		for (int j = 0; j <= n; ++j)
			visited[j] = false;
	}

	int s; scanf("%d", &s);
	for (int i = 0; i < s; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		bool flag = false;
		for (int j = 0; j < (int)orderPath[a].size(); ++j)
			if (orderPath[a][j] == b) {
				flag = true;
				break;
			}
		if (flag) {
			printf("-1\n");
			continue;
		}

		for (int j = 0; j < (int)revPath[a].size(); ++j)
			if (revPath[a][j] == b) {
				flag = true;
				break;
			}
		if (flag) {
			printf("1\n");
			continue;
		}
		printf("0\n");
	}

	return 0;
}