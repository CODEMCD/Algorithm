#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define N 51
char m[N][N];
char water[N][N];
queue<pair<int, int>> wq;
queue<pair<int, int>> sq;
int mx[4] = { 1,-1,0,0 };
int my[4] = { 0,0,1,-1 };

int main(void)
{
	int r, c;
	scanf("%d %d", &r, &c);
	//getchar();
	vector<pair<int, int>> wp;
	pair<int, int> sp;
	pair<int, int> tmp;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			char c;
			c = getchar();
			if (c != '\n' && c != ' ') {
				m[i][j] = c;
				water[i][j] = c;
			}
			else
				j--;
			if (m[i][j] == '*') {
				tmp = make_pair(j, i);
				wp.push_back(tmp);
			}
			else if (m[i][j] == 'S') {
				sp = make_pair(j, i);
				//printf("S : (%d, %d)\n", j, i);
			}
		}
	/*printf("\n");
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			printf("%c ", m[i][j]);
		printf("\n");
	}*/

	for (int i = 0; i < wp.size(); i++)
		wq.push(wp[i]);
	sq.push(sp);
	int cnt = 0;
	int wcnt = wp.size();
	int scnt = 1;
	while (!wq.empty() || !sq.empty()) {
		cnt++;
		for (int i = 0; i < wcnt; i++) {
			int nowX = wq.front().first;
			int nowY = wq.front().second;
			wq.pop();
			for (int i = 0; i < 4; i++) {
				int nextX = nowX + mx[i];
				int nextY = nowY + my[i];
				if (nextX < c && nextX >= 0 && nextY < r && nextY >= 0) {
					if (m[nextY][nextX] != 'D' && m[nextY][nextX] != 'X' && water[nextY][nextX] != '*') {
						water[nextY][nextX] = '*';
						tmp = make_pair(nextX, nextY);
						wq.push(tmp);
					}
				}
			}
		}
		wcnt = (int)wq.size();
		for (int i = 0; i < scnt; i++) {
			int nowX = sq.front().first;
			int nowY = sq.front().second;
			sq.pop();
			for (int i = 0; i < 4; i++) {
				int nextX = nowX + mx[i];
				int nextY = nowY + my[i];
				if (nextX < c && nextX >= 0 && nextY < r && nextY >= 0) {
					if (m[nextY][nextX] == 'D') {
						printf("%d\n", cnt);
						return 0;
					}
					else if (m[nextY][nextX] == '.' && water[nextY][nextX] != '*') {  //***
						m[nextY][nextX] = 'S';
						sp = make_pair(nextX, nextY);
						sq.push(sp);
					}
				}
			}
		}
		scnt = (int)sq.size();
		//printf("%d %d\n", scnt, (int)sq.size());
	}
	printf("KAKTUS\n");

	return 0;
}