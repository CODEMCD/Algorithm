#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define N 501
int time[N];  //건물 짓는 시간을 저장하는 배열
int ind[N];  //진입차수 저장 배열
vector<int> v[N];  //그래프
int ans[N];

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int ct;
		scanf("%d", &ct);
		time[i] = ct;
		int preB;
		scanf("%d", &preB);
		while (preB != -1) { 
			v[preB].push_back(i);
			ind[i]++;
			scanf("%d", &preB);
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0)
			q.push(i);
		ans[i] = time[i];
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < (int)v[now].size(); i++) {
			int next = v[now][i];
			if (ans[next] < ans[now] + time[next])
				ans[next] = ans[now] + time[next];
			else
				ans[next] = ans[next];
			ind[next]--;
			if (ind[next] == 0)
				q.push(next);
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%d\n", ans[i]);

		
	return 0;
}

/* test case
4
1 -1
1 1 -1
2 1 -1
1 2 3 -1

1 2 3 4

4
1 -1
1 1 -1
1 1 -1
1 2 3 -1

1 2 2 3

4
1 4 3 2 -1
2 4 -1
1 4 -1
1 -1

4 3 2 1

5
10 -1
10 1 -1
4 1 -1
4 1 3 -1
3 3 -1
*/