#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define N 32001
vector<int> v[N];
int ind[N];  //�������� ���� ������ ������ �迭
int ans[N];

//ť�� Ȱ���� ���� ���� ����
int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int small, tall;
		scanf("%d %d", &small, &tall);
		v[small].push_back(tall);
		ind[tall]++;  //�������� ����
	}
	queue<int> q;

	for (int i = 1; i <= n; i++)
		if (ind[i] == 0)  //���� ������ 0�� ��� ť�� ����
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