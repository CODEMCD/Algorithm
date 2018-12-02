#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define N 32001
vector<int> v[N];
int ind[N];  //위상정렬 진입 차수를 저장할 배열
int ans[N];

//큐를 활용한 위상 정렬 구현
int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int small, tall;
		scanf("%d %d", &small, &tall);
		v[small].push_back(tall);
		ind[tall]++;  //진입차수 갱신
	}
	queue<int> q;

	for (int i = 1; i <= n; i++)
		if (ind[i] == 0)  //진입 차수가 0인 노드 큐에 저장
			q.push(i);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		printf("%d ", cur);
		for (int i = 0; i < (int)v[cur].size(); i++) {
			int next = v[cur][i];

			ind[next]--;
			if (ind[next] == 0)
				q.push(next);
		}
	}
	printf("\n");
	return 0;
}