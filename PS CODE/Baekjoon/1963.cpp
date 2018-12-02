#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
#define N 10001
bool prime[N];
bool check[N];
int dist[N];

int change(int ori, int chpos, int chnum)
{
	int num[4];
	num[0] = ori / 1000;
	ori %= 1000;
	num[1] = ori / 100;
	ori %= 100;
	num[2] = ori / 10;
	num[3] = ori % 10;
	for (int i = 0; i < 4; i++)
		if (i == chpos)
			num[i] = chnum;
	int res = num[0] * 1000 + num[1] * 100 + num[2] * 10 + num[3];
	return res;
}

int main(void)
{
	memset(prime, true, sizeof(bool)*N);
	prime[0] = prime[1] = false;
	for (int i = 2; i < N; i++) {
		if (prime[i] == true)
			for (int j = i + i; j < N; j += i)
				prime[j] = false;
	}
	//int cnt = 0;
	//for (int i = 1000; i < N; i++)
	//	if (prime[i] == true) {
	//		cnt++;
	//		printf("%d ", i);
	//	}
	//printf("\n%d\n", cnt);

	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		memset(check, false, sizeof(bool)*N);
		memset(dist, 0, sizeof(int)*N);
		int n, m;
		scanf("%d %d", &n, &m);
		if (n == m) {
			printf("0\n");
			continue;
		}
		queue<int> q;
		q.push(n);
		check[n] = true;
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 10; j++) {
					int next = change(now, i, j);
					//printf("-%d\n", next);
					if (next > 1000 && prime[next] == true && check[next] == false) {
						check[next] = true;
						q.push(next);
						dist[next] = dist[now] + 1;
					}
				}
		}
		if (dist[m] == 0)
			printf("Impassible\n");
		else
			printf("%d\n", dist[m]);
	}

	return 0;
}