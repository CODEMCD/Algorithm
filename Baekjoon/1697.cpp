#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
#define N 200001
bool check[N];
int dist[N];

int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);
	dist[n] = 0;
	check[n] = true;
	queue<int> q;
	q.push(n);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (now >= 1 && check[now - 1] == false) {
			q.push(now - 1);
			check[now - 1] = true;
			dist[now - 1] = dist[now] + 1;
		}
		if (now + 1 < N && check[now + 1] == false) {
			q.push(now + 1);
			check[now + 1] = true;
			dist[now + 1] = dist[now] + 1;
		}
		if (2 * now < N && check[2 * now] == false) {
			q.push(2 * now);
			check[2 * now] = true;
			dist[2 * now] = dist[now] + 1;
		}
	}
	printf("%d\n", dist[k]);
	return 0;
}