#define _CRT_SECURE_NO_WARNINGS

/*
4613. 러시아 국기 같은 깃발
러시아 국기는 흰색과 빨간색이 양 끝에 고정이며, 중간 중간에 나타날 수 없으므로
중간에 있는 파란색의 개수에 따라 될 수 있는 모든 경우의 수를 탐색한다.
완전 탐색은 O(N^3)이며, N의 최대 크기가 50이기 때문에 1초안에 충분히 해결가능하다.
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define min(a,b) ((a) < (b) ? (a) : (b))
#define N 51
const int INF = 987654321;
int n, m;
char flag[N][N];
int ans = INF;

//횐색, 파란색, 빨간색의 시작점을 가지고 색칠해야 하는 개수를 반환한다.
int fillFlag(int w, int b, int r) {
	int fillCnt = 0;
	for (int i = w; i < b; ++i)
		for (int j = 0; j < m; ++j)
			if (flag[i][j] != 'W')
				++fillCnt;
	for (int i = b; i < r; ++i)
		for (int j = 0; j < m; ++j)
			if (flag[i][j] != 'B')
				++fillCnt;
	for (int i = r; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (flag[i][j] != 'R')
				++fillCnt;
	return fillCnt;
}

//파란색의 개수를 늘려가며 모든 경우의 수를 탐색하며, 색칠하는 개수의 최소값을 찾는다.
void solve(int b) {
	//기저 사례: 파란색은 양 끝의 횐색, 빨간색 2개를 제외하고 모두 칠할 수 있다.
	if (b == n - 1) return;
	//파란색 개수에 따라 모든 경우의 수 탐색
	for (int i = 1; i < n - b; ++i)
		ans = min(ans, fillFlag(0, i, i + b));
	solve(b + 1);
}

int main()
{
	int tc; scanf("%d", &tc);
	for (int t = 0; t < tc; ++t) {
		ans = INF;
		memset(flag, 0, sizeof(flag));

		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i)
			scanf("%s", flag[i]);
		solve(1);
		printf("#%d %d\n", t + 1, ans);
	}

	return 0;
}
