#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define N 101
int t[N][N][N];
int mx[6] = { 1,-1,0,0,0,0 };
int my[6] = { 0,0,1,-1,0,0 };
int mz[6] = { 0,0,0,0,1,-1 };
queue<vector<int>> q;
vector<int> p;

int main(void)
{
	int m, n, h;
	scanf("%d %d %d", &m, &n, &h);
	int cnt = 0;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++) {
				scanf("%d", &t[i][j][k]);
				if (t[i][j][k] == 1) {
					p.clear();
					p.push_back(k);
					p.push_back(j);
					p.push_back(i);
					q.push(p);
				}
				else if (t[i][j][k] == 0)
					cnt++;
			}
	int qsize = (int)q.size();
	int time = 0;
	while (!q.empty()) {
		time++;
		for (int l = 0; l < qsize; l++) {
			vector<int> now = q.front();
			q.pop();
			int nowx = now[0];
			int nowy = now[1];
			int nowz = now[2];
			for (int i = 0; i < 6; i++) {
				int nextx = nowx + mx[i];
				int nexty = nowy + my[i];
				int nextz = nowz + mz[i];
				if (nextx >= 0 && nextx < m && nexty >= 0 && nexty < n && nextz >= 0 && nextz < h) {
					if (t[nextz][nexty][nextx] == 0) {
						t[nextz][nexty][nextx] = 1;
						cnt--;
						p.clear();
						p.push_back(nextx);
						p.push_back(nexty);
						p.push_back(nextz);
						q.push(p);
					}
				}
			}
		}
		qsize = (int)q.size();
	}
	if (!cnt)
		printf("%d\n", time - 1);
	else
		printf("-1\n");
	
	return 0;
}