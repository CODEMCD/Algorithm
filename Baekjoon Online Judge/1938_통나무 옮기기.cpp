#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
//right, down, left, up
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
char yard[52][52];
/*
visited[y][x][d]: �볪���� ��ǥ�� (y, x)�̰� ������ d(����: 0, ����: 1)�� 
				���·� �湮�� ��ǥ�� true���� �Է��Ѵ�.
*/
bool visited[51][51][2];
int n;

//�볪�� ��ǥ(3��)
typedef struct _log {
	pair<int, int> lpos[3];
} Log;

//�볪�� ������ ����(0)���� ����(1)���� ��ȯ�Ѵ�.
int horiver(Log cur) {
	//������ ���
	if (cur.lpos[0].first == cur.lpos[1].first && cur.lpos[1].first  == cur.lpos[2].first)
		return 0;
	//������ ���
	else if (cur.lpos[0].second == cur.lpos[1].second && cur.lpos[1].second == cur.lpos[2].second)
		return 1;
	return -1;
}

//���� �볪���� �Էµ� �������� �� ĭ ������ �� �ִٸ�, TRUE�� ��ȯ�ϰ� ��ǥ�� �Ű��ش�.
bool moveLRDU(Log *cur, int dir) {
	//�Էµ� �������� �� ĭ �̵��� �볪�� ��ǥ
	pair<int, int> next[3];
	next[0].first = cur->lpos[0].first + dy[dir];
	next[0].second = cur->lpos[0].second + dx[dir];
	next[1].first = cur->lpos[1].first + dy[dir];
	next[1].second = cur->lpos[1].second + dx[dir];
	next[2].first = cur->lpos[2].first + dy[dir];
	next[2].second = cur->lpos[2].second + dx[dir];
	//�־��� ���� ������ ��� ��� FALSE ��ȯ
	if (next[0].first < 0 || next[0].first >= n ||
		next[0].second < 0 || next[0].second >= n ||
		next[1].first < 0 || next[1].first >= n ||
		next[1].second < 0 || next[1].second >= n ||
		next[2].first < 0 || next[2].first >= n ||
		next[2].second < 0 || next[2].second >= n)
		return false;
	//������ ��ǥ�� �ٸ� ������ �ִ� ��� FALSE ��ȯ
	if (yard[next[0].first][next[0].second] == '1' ||
		yard[next[1].first][next[1].second] == '1' ||
		yard[next[2].first][next[2].second] == '1')
		return false;
	//������ �� �ִ� ��� ���� ��ǥ�� �����δ�.
	cur->lpos[0].first += dy[dir];
	cur->lpos[0].second += dx[dir];
	cur->lpos[1].first += dy[dir];
	cur->lpos[1].second += dx[dir];
	cur->lpos[2].first += dy[dir];
	cur->lpos[2].second += dx[dir];
	return true;
}

//���� �볪���� 90�� ȸ���� �� �ִ� ��� TRUE�� ��ȯ�ϰ� ȸ���� ��ǥ�� �Է��Ѵ�.
bool moveRotate(Log *cur) {
	//�����볪��
	if (horiver(*cur) == 0) {
		//ȸ�� �ݰ��� ���� ������ ����ų� �ٸ� ������ �����ϸ� FALSE�� ��ȯ�Ѵ�.
		for (int i = cur->lpos[0].first - 1; i <= cur->lpos[0].first + 1; ++i)
			for (int j = cur->lpos[0].second; j <= cur->lpos[2].second; ++j)
				if (i < 0 || i >= n || j < 0 || j >= n || yard[i][j] == '1')
					return false;
		cur->lpos[0].first = cur->lpos[0].first - 1;
		cur->lpos[0].second = cur->lpos[0].second + 1;
		cur->lpos[2].first = cur->lpos[2].first + 1;
		cur->lpos[2].second = cur->lpos[2].second - 1;
		return true;
	}
	//�����볪��
	else if (horiver(*cur) == 1) {
		for (int i = cur->lpos[0].first; i <= cur->lpos[2].first; ++i)
			for (int j = cur->lpos[0].second - 1; j <= cur->lpos[0].second + 1; ++j)
				if (i < 0 || i >= n || j < 0 || j >= n || yard[i][j] == '1')
					return false;
		cur->lpos[0].first = cur->lpos[0].first + 1;
		cur->lpos[0].second = cur->lpos[0].second - 1;
		cur->lpos[2].first = cur->lpos[2].first - 1;
		cur->lpos[2].second = cur->lpos[2].second + 1;
		return true;
	}
	return false;
}

int main(void)
{
	scanf("%d", &n);
	Log b, e;
	int bcnt = 0, ecnt = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%s", yard[i]);
		for (int j = 0; j < n; ++j) {
			if (yard[i][j] == 'B')
				b.lpos[bcnt++] = { i, j };
			else if (yard[i][j] == 'E')
				e.lpos[ecnt++] = { i, j };
		}
	}

	//(�볪�� ��ǥ(3��), ������ Ƚ��)
	queue<pair<Log, int>> q;
	q.push({ b, 0 });
	//���� �볪�� ��ǥ�� �볪�� ���� �湮 ǥ��
	visited[b.lpos[0].first][b.lpos[0].second][horiver(b)] = true;
	visited[b.lpos[1].first][b.lpos[1].second][horiver(b)] = true;
	visited[b.lpos[2].first][b.lpos[2].second][horiver(b)] = true;
	int ans = 0;
	while (!q.empty()) {
		Log now = q.front().first;
		int nowCnt = q.front().second;
		q.pop();

		//���� �볪���� ������ġ�� ��ġ�� ���
		if (now.lpos[0].first == e.lpos[0].first && now.lpos[0].second == e.lpos[0].second &&
			now.lpos[1].first == e.lpos[1].first && now.lpos[1].second == e.lpos[1].second &&
			now.lpos[2].first == e.lpos[2].first && now.lpos[2].second == e.lpos[2].second) {
			ans = nowCnt;
			break;
		}

		Log next;
		//���� �볪���� �����¿�� ������ �� �ִ��� �˻��Ѵ�.
		for (int i = 0; i < 4; ++i) {
			next = now;
			//�Էµ� �������� ������ �� �ְ�, �ش� �볪�� ��ǥ�� ���� �� �� ��ǥ�� �湮�� �� �ִ� ���
			if (moveLRDU(&next, i) && (!visited[next.lpos[0].first][next.lpos[0].second][horiver(next)]
				|| !visited[next.lpos[1].first][next.lpos[1].second][horiver(next)]
				|| !visited[next.lpos[2].first][next.lpos[2].second][horiver(next)])) {
				//�湮 ǥ��
				visited[next.lpos[0].first][next.lpos[0].second][horiver(next)] = true;
				visited[next.lpos[1].first][next.lpos[1].second][horiver(next)] = true;
				visited[next.lpos[2].first][next.lpos[2].second][horiver(next)] = true;
				//ť�� ����
				q.push({ next, nowCnt + 1 });
			}
		}

		//���� �볪���� 90�� ȸ���Ѵ�.
		next = now;
		if (moveRotate(&next) && (!visited[next.lpos[0].first][next.lpos[0].second][horiver(next)]
			|| !visited[next.lpos[1].first][next.lpos[1].second][horiver(next)]
			|| !visited[next.lpos[2].first][next.lpos[2].second][horiver(next)])) {
			visited[next.lpos[0].first][next.lpos[0].second][horiver(next)] = true;
			visited[next.lpos[1].first][next.lpos[1].second][horiver(next)] = true;
			visited[next.lpos[2].first][next.lpos[2].second][horiver(next)] = true;
			q.push({ next, nowCnt + 1 });
		}
	}

	printf("%d\n", ans);

	return 0;
}