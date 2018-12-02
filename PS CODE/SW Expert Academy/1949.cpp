#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define N 8
int m[N][N];
int nop[N][N];  //���� ���� ���� �迭
int mx[4] = { -1, 0, 1, 0 };
int my[4] = { 0, 1, 0, -1 };
vector<pair<int, int>> v;
pair<int, int> p;
queue<pair<int, int>> q;
int ans;

//���� �ִ� ���� Ž��
void bfs(int n, int h)
{
	for (int i = 0; i < (int)v.size(); i++) {
		if (m[v[i].first][v[i].second] == h)
			q.push(v[i]);
		else
			continue;
		nop[v[i].first][v[i].second] = 1;
		while (!q.empty()) {
			int nowx = q.front().first;
			int nowy = q.front().second;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int nextx = nowx + mx[j];
				int nexty = nowy + my[j];
				if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < n) {
					if (m[nowx][nowy] > m[nextx][nexty] && nop[nowx][nowy] > nop[nextx][nexty]) {
						nop[nextx][nexty] = nop[nowx][nowy] + 1;
						if (nop[nextx][nexty] > ans)
							ans = nop[nextx][nexty];
						p = make_pair(nextx, nexty);
						q.push(p);
					}
				}
			}
		}
		memset(nop, 0, sizeof(nop));
	}
}

int main(void)
{
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		//�ʱ�ȭ
		memset(m, 0, sizeof(m));
		ans = 0;
		v.clear();
		//����
		int n, k;
		scanf("%d %d ", &n, &k);
		int h = 0;  //���츮 ����
		//���츮 ���� �Է� �� �ְ� ���� ���츮 ���� ����
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				scanf("%d", &m[i][j]);
				if (h < m[i][j])
					h = m[i][j];
			}
		//�ְ� ���� ���츮 ��ǥ vector�� ����
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (m[i][j] == h) {
					p = make_pair(i, j);
					v.push_back(p);
				}
			}
		//�ʱ� ���� �ִ� ����
		bfs(n, h);
		//1 ~ k ���̸�ŭ ��� ���ο� �����Ͽ� Ž��
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int l = 1; l <= k; l++) {
					m[i][j] -= l;
					bfs(n, h);
					m[i][j] += l;
				}
			}
		}
		printf("#%d %d\n", tc, ans);
	}

	return 0;
}