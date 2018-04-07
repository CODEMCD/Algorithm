#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define N 145
int p[N][N];
int check[N][N];  //BFS 횟수 세기 (최소시간 측정)
int mx[6] = { -1, -1, 0, 1, 1, 0 };
int my[6] = { -1, 0, 1, 1, 0, -1 };

int main(void)
{
	int cnt = 0, num = 1;
	for (int i = 0; i < N; i++) {
		cnt++;
		for (int j = 0; j < N; j++) {
			if (j == cnt)
				break;
			else
				p[i][j] = num++;
		}
	}
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%d ", p[i][j]);
		printf("\n");
	}*/

	int t;
	scanf("%d", &t);
	cnt = 1;
	while (t--) {
		int s, e;
		scanf("%d %d", &s, &e);
		if (s == e) {
			printf("#%d 0\n", cnt++);
			continue;
		}
		pair<int, int> sp;
		for (int i = 0; i < N; i++) 
			for (int j = 0; j < N; j++)
				if (p[i][j] == s) {
					sp = make_pair(i, j);
					check[i][j] = 1;
				}
		int ansx, ansy;
		queue<pair<int, int>> q;
		q.push(sp);
		bool find = false;
		while (!q.empty()) {
			int nowx = q.front().first;
			int nowy = q.front().second;
			q.pop();
			for (int i = 0; i < 6; i++) {
				int nextx = nowx + mx[i];
				int nexty = nowy + my[i];
				if (nextx >= 0 && nextx < N && nexty >= 0 && nexty < N) {
					if (p[nextx][nexty] == e) {
						check[nextx][nexty] = check[nowx][nowy] + 1; //BFS 횟수 세기
						ansx = nextx;
						ansy = nexty;
						find = true;
						break;
					}
					else if (p[nextx][nexty] != 0 && !check[nextx][nexty]) {
						check[nextx][nexty] = check[nowx][nowy] + 1; //BFS 횟수 세기
						sp = make_pair(nextx, nexty);
						q.push(sp);
					}
				}
			}
			if (find)
				break;
		}
		printf("#%d %d\n", cnt++, check[ansx][ansy] - 1);
		memset(check, 0, sizeof(check));
	}

	return 0;
}