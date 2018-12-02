#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
#define N 10001
int dist[N];
char cmd[N][N];
bool check[N];
int cnt = 0;

int calD(int num)
{
	return 2 * num % 10000;
}
int calS(int num)
{
	if (num == 0)
		return 9999;
	else
		return num - 1;
}
int calL(int num)
{
	int n[5] = { 0 };
	n[0] = num / 1000;
	num %= 1000;
	n[1] = num / 100;
	num %= 100;
	n[2] = num / 10; n[3] = num % 10;
	n[4] = n[0];
	int res = n[1] * 1000 + n[2] * 100 + n[3] * 10 + n[4];
	return res;
}
int calR(int num)
{
	int n[5] = { 0 };
	n[1] = num / 1000;
	num %= 1000;
	n[2] = num / 100;
	num %= 100;
	n[3] = num / 10; n[4] = num % 10;
	n[0] = n[4];
	int res = n[0] * 1000 + n[1] * 100 + n[2] * 10 + n[3];
	return res;
}

int main(void)
{
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(dist, 0, sizeof(dist));
		memset(check, false, sizeof(check));
		int n, m;
		scanf("%d %d", &n, &m);
		queue<int> q;
		q.push(n);
		check[n] = true;
		cmd[n][0] = ' ';
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			int next = calD(now);
			if (check[next] == false) {
				q.push(next);
				check[next] = true;
				dist[next] = dist[now] + 1;
				strcpy(cmd[next], cmd[now]);
				cmd[next][dist[now] + 1] = 'D';
			}
			next = calS(now);
			if (check[next] == false) {
				q.push(next);
				check[next] = true;
				dist[next] = dist[now] + 1;
				strcpy(cmd[next], cmd[now]);
				cmd[next][dist[now] + 1] = 'S';
			}
			next = calL(now);
			if (check[next] == false) {
				q.push(next);
				check[next] = true;
				dist[next] = dist[now] + 1;
				strcpy(cmd[next], cmd[now]);
				cmd[next][dist[now] + 1] = 'L';
			}
			next = calR(now);
			if (check[next] == false) {
				q.push(next);
				check[next] = true;
				dist[next] = dist[now] + 1;
				strcpy(cmd[next], cmd[now]);
				cmd[next][dist[now] + 1] = 'R';
			}
		}
		//printf("%d\n", dist[m]);
		for (int i = 1; i <= dist[m]; i++)
			printf("%c", cmd[m][i]);
		printf("\n");
	}

	return 0;
}