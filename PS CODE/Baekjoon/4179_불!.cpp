#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
int board[1001][1001];
vector<pair<int, int>> firePos;

int main(void)
{
	int r, c; scanf("%d %d", &r, &c);
	int jy, jx;
	for (int i = 0; i < r; ++i) {
		string str;
		cin >> str;
		for (int j = 0; j < c; ++j) {
			if (str[j] == '#') board[i][j] = -1;
			else if (str[j] == 'F') {
				board[i][j] = -2;
				firePos.push_back(make_pair(i, j));
			}
			else if (str[j] == 'J') {
				board[i][j] = 1;
				jy = i;
				jx = j;
			}
			else
				board[i][j] = 0;
		}
	}

	//ť�� ����ϹǷ�, ����, �� ������ BFS �˰����� �����ϸ� ������ �����ȴ�.
	queue<pair<int, int>> q;
	q.push({ jy, jx });
	for (int i = 0; i < (int)firePos.size(); ++i)
		q.push({ firePos[i].first, firePos[i].second });

	int ans = 0;
	bool escape = false;
	while (!q.empty()) {
		int nowy = q.front().first;
		int nowx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nexty = nowy + dy[i];
			int nextx = nowx + dx[i];
			//���� Ż��
			if (board[nowy][nowx] > 0 && (nexty < 0 || nexty >= r ||
				nextx < 0 || nextx >= c)) {
				ans = board[nowy][nowx];
				escape = true;
				break;
			}
			//�� �� ��ǥ�� �̷� ���� ���
			else if (nexty < 0 || nexty >= r || nextx < 0 || nextx >= c)
				continue;
			//���� �̵�
			if (board[nowy][nowx] > 0 && board[nexty][nextx] == 0) {
				board[nexty][nextx] = board[nowy][nowx] + 1;
				q.push({ nexty, nextx });
			}
			//�� �̵�
			else if (board[nowy][nowx] == -2 && board[nexty][nextx] >= 0) {
				board[nexty][nextx] = -2;
				q.push({ nexty, nextx });
			}
		}
		if (escape) break;
	}

	if (escape) printf("%d\n", ans);
	else printf("IMPOSSIBLE\n");

	return 0;
}