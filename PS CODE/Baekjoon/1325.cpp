#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define N 10001
vector<int> v[N];
bool check[N];
int ans[N];
int cnt;

void dfs(int now)
{
	check[now] = true;
	cnt++;
	for (int i = 0; i < (int)v[now].size(); i++) {
		int next = v[now][i];
		if(!check[next])
			dfs(next);
	}
}

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[b].push_back(a);
	}
	int max = 0;
	for (int i = 1; i <= n; i++) {
		memset(check, false, sizeof(check));
		cnt = 0;
		dfs(i);
		ans[i] = cnt;
		if (max < cnt)
			max = cnt;
	}
	for (int i = 1; i <= n; i++) {
		if (max == ans[i])
			printf("%d ", i); 
	}
	printf("\n");

	return 0;
}