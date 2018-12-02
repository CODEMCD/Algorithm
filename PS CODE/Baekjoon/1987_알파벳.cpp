#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;
int r, c, cnt, ans;
bool visited[26];
char board[21][21];
int my[4] = { -1, 0, 1, 0 };
int mx[4] = { 0, 1, 0, -1 };

void dfs(int y, int x) {
	visited[board[y][x] - 'A'] = true;
	cnt++;
	for (int i = 0; i < 4; ++i) {
		int nexty = y + my[i];
		int nextx = x + mx[i];
		if (nexty >= 0 && nexty < r && nextx >= 0 && nextx < c) {
			if (!visited[board[nexty][nextx] - 'A']) {
				dfs(nexty, nextx);
				//다른 모든 루트를 찾기 위해 해당 알파벳을 다시 방문할 수 있도록 한다.
				visited[board[nexty][nextx] - 'A'] = false;
				//현재 루트의 길이 중 최대값을 저장한다.
				ans = max(ans, cnt);
				cnt--;
			}
		}
	}
}

int main()
{
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; ++i)
		scanf("%s", board[i]);
	//첫번째 칸은 무조건 방문하기 때문에 최소값은 1로 해주어야 한다.
	ans = 1;
	dfs(0, 0);
	printf("%d\n", ans);

	return 0;
}
