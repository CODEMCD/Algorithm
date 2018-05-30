#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

//�־��� ĭ�� ���� �� �ִ� �� ���� ���
//����� �����ϴ� �� ĭ�� ����� ��ġ (dy, dx)�� ���(�� �׸� ����)
const int coverType[4][3][2] = {
	{ { 0, 0 },{ 1, 0 },{ 0, 1 } },
	{ { 0, 0 },{ 0, 1 },{ 1, 1 } },
	{ { 0, 0 },{ 1, 0 },{ 1, 1 } },
	{ { 0, 0 },{ 1, 0 },{ 1, -1 } }
};
//board�� (y, x)�� type�� ������� ���ų�, ������ ����� ���ش�.
//delta = 1�̸� ����, -1�̸� ������ ����� ���ش�.
//���� ����� ����� ������ ���� ���(������ ������ �����ų�, �������ų�, ���� ĭ�� ��) false�� ��ȯ�Ѵ�.
bool set(vector<vector<int>>&board, int y, int x, int type, int delta)
{
	bool ok = true;
	for (int i = 0; i < 3; i++) {
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];
		if (ny < 0 || ny >= (int)board.size() || nx < 0 || nx >= (int)board[0].size())
			ok = false;
		else if ((board[ny][nx] += delta) > 1)
			ok = false;
	}
	return ok;
}

//board�� ��� �� ĭ�� ���� �� �ִ� ����� ���� ��ȯ�Ѵ�.
//board[i][j] = 1 �̹� ���� ĭ Ȥ�� ���� ĭ
//board[i][j] = 0 ���� ������ ���� ĭ
int cover(vector<vector<int>>&board)
{
	//���� ä���� ���� ĭ �� ���� ���� ���ʿ� �ִ� ĭ�� ã�´�.
	int y = -1, x = -1;  //flag ����� �߰��ϱ� ���� -1�� �ʱ�ȭ
	for (int i = 0; i < (int)board.size(); i++) {
		for (int j = 0; j < (int)board[i].size(); j++) {
			if (board[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1) break;
	}
	//���� ���: ��� ĭ�� ä������ 1�� ��ȯ�Ѵ�.
	if (y == -1) return 1;
	int ret = 0;
	for (int type = 0; type < 4; type++) {
		//���� board[y][x]�� type ���·� ���� �� ������ ��� ȣ���Ѵ�.
		if (set(board, y, x, type, 1))
			ret += cover(board);
		//������ ����� ġ���.
		set(board, y, x, type, -1);
	}
	return ret;
}

int main(void)
{
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		vector<vector<int>> board;
		vector<int> v;
		char row[21];
		int h, w;
		scanf("%d %d", &h, &w);
		for (int i = 0; i < h; i++) {
			scanf("%s", row);
			for (int j = 0; j < w; j++) {
				if (row[j] == '#')
					v.push_back(1);
				else
					v.push_back(0);
			}
			board.push_back(v);
			v.clear();
		}
		/*for (int i = 0; i < (int)board.size(); i++) {
			for (int j = 0; j < (int)board[i].size(); j++) {
				printf("%d ", board[i][j]);
			}
			printf("\n");
		}*/

		printf("%d\n", cover(board));
	}

	return 0;
}