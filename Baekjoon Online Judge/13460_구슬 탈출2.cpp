#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

//각 구슬의 위치와 움직인 횟수를 저장할 구조체
typedef struct _ball
{
	int dist;
	int ry, rx, by, bx;
}ball;

//board
//0: '.' 빈칸
//1: '#' 벽
//2: 'O' 구멍
int board[11][11];
//상, 우, 하, 좌 (시계방향)
int my[4] = { -1,0,1,0 };
int mx[4] = { 0,1,0,-1 };
//빨간 구슬과 파란 구슬의 각각의 좌표의 방문 여부 검사
bool visited[11][11][11][11];

//상하좌우로 기우렸을때, 위치를 반환(포인터 처리)
void nextBoard(int *y, int *x, int d) {
	while (1) {
		*y += my[d];
		*x += mx[d];
		//벽을 만나면, 한칸 전 좌표로 반환
		if (board[*y][*x] == 1) {
			*y -= my[d];
			*x -= mx[d];
			break;
		}
		//구멍을 만나면 해당 좌표 반환
		else if (board[*y][*x] == 2)
			break;
	}
}

int main()
{
	int n, m; scanf("%d %d", &n, &m);
	string in;
	int iry, irx, iby, ibx, hy, hx;
	//입력처리, 홀의 좌표, 최초의 빨간 파랑 구슬 좌표 저장
	for (int i = 0; i < n; ++i) {
		cin >> in;
		for (int j = 0; j < m; ++j) {
			switch (in[j]) {
			case '.':
				board[i][j] = 0; break;
			case '#':
				board[i][j] = 1; break;
			case 'O':
				board[i][j] = 2;
				hy = i; hx = j;
				break;
			case 'R':
				iry = i; irx = j;
				break;
			case 'B':
				iby = i; ibx = j;
				break;
			}
		}
	}

	queue<ball> q;
	q.push({ 0, iry, irx, iby, ibx });
	visited[iry][irx][iby][ibx] = true;
	int ans = -1;

	while (!q.empty()) {
		ball here = q.front();
		q.pop();

		//횟수가 10번 넘어가면 실패이므로 반복문을 빠져나감
		if (here.dist > 10)
			break;
		//현재 빨간 구슬의 좌표가 구멍 좌표와 동일하면 정답
		if (here.ry == hy && here.rx == hx) {
			ans = here.dist;
			break;
		}

		for (int i = 0; i < 4; ++i) {
			int nry = here.ry, nrx = here.rx;
			int nby = here.by, nbx = here.bx;
			//빨간 구슬을 움직임
			nextBoard(&nry, &nrx, i);
			//파란 구슬을 움직임
			nextBoard(&nby, &nbx, i);

			//파란 구슬이 구멍에 빠지면 다음 동작으로 넘어감
			if (nby == hy && nbx == hx)
				continue;

			//파란 구슬과 빨간 구슬이 같은 좌표에 위치하면 상하좌우에 따라 위치를 조정함
			if (nry == nby && nrx == nbx) {
				switch (i) {
				case 0:
					here.ry < here.by ? nby++ : nry++; break;
				case 1:
					here.rx < here.bx ? nrx-- : nbx--; break;
				case 2:
					here.ry < here.by ? nry-- : nby--; break;
				case 3:
					here.rx < here.bx ? nbx++ : nrx++; break;
				}
			}

			//빨간구슬과 파란구슬 좌표가 처음 방문하는 것이라면 큐에 넣어준다.
			if (!visited[nry][nrx][nby][nbx]) {
				ball there = { here.dist + 1, nry, nrx, nby,nbx };
				q.push(there);
				visited[nry][nrx][nby][nbx];
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}
