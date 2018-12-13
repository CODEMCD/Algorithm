#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
//��,��,��,��,��,�� ����
int dz[6] = { 0, 0, 0, 0, 1, -1 };
int dy[6] = { 0, 1, 0, -1, 0, 0 };
int dx[6] = { 1, 0, -1, 0, 0, 0 };
/*
building: ���� ����(S = 1, . = 0, # = -1, E = 2)
pathLen: �ð�(��) ���(-1�� �ʱ�ȭ)
*/
int building[31][31][31], pathLen[31][31][31];

//��ǥ
class point {
public:
	int z, y, x;
	point() {
		z = y = x = 0;
	}
};

int main(void)
{
	while (true) {
		int l, r, c; scanf("%d %d %d", &l, &r, &c);
		if (!l && !r && !c) break;

		//s: ���� ��ǥ
		//e: ���� ��ǥ
		point s, e;
		for (int i = 0; i < l; ++i) {
			for (int y = 0; y < r; ++y) {
				string str;
				cin >> str;
				for (int x = 0; x < c; ++x) {
					if (str[x] == '.') building[i][y][x] = 0;
					else if (str[x] == '#') building[i][y][x] = -1;
					else if (str[x] == 'S') {
						building[i][y][x] = 1;
						s.z = i; s.y = y; s.x = x;
					}
					else if (str[x] == 'E') {
						building[i][y][x] = 2;
						e.z = i; e.y = y; e.x = x;
					}
				}
			}
		}

		memset(pathLen, -1, sizeof(pathLen));
		//3���� BFS
		queue<point> q;
		q.push(s);
		pathLen[s.z][s.y][s.x] = 0;
		bool escap = false;
		while (!q.empty()) {
			point now = q.front();
			q.pop();

			for (int i = 0; i < 6; ++i) {
				point next;
				next.z = now.z + dz[i];
				next.y = now.y + dy[i];
				next.x = now.x + dx[i];
				if (next.z < 0 || next.z >= l || 
					next.y < 0 || next.y >= r ||
					next.x < 0 || next.x >= c)
					continue;

				//���� �ƴϰ� ó�� �ش� ��ǥ�� �� ���
				if (building[next.z][next.y][next.x] != -1 &&
					pathLen[next.z][next.y][next.x] == -1) {
					//�ð� ���
					pathLen[next.z][next.y][next.x] =
						pathLen[now.z][now.y][now.x] + 1;
					//���� ���� ��ǥ�̸� �ݺ����� ��������
					if (next.z == e.z && next.y == e.y && next.x == e.x) {
						escap = true;
						break;
					}
					else
						q.push(next);
				}
			}
			if (escap) break;
		}

		if (escap)
			printf("Escaped in %d minute(s).\n", pathLen[e.z][e.y][e.x]);
		else
			printf("Trapped!\n");
	}

	return 0;
}