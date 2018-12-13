#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define N 101
int board[N][N];

//뱀의 상태
typedef struct _snakeState
{
	int y, x;   //뱀의 위치
	int dir;    //회전 방향
} state;
//사과 좌표 배열
vector<pair<int, int>> apple;
//회전
vector<pair<int, char>> dir;
vector<state> snake;
//상, 우, 하, 좌
int my[4] = { -1, 0, 1, 0 };
int mx[4] = { 0, 1, 0, -1 };

int main()
{
	int n; scanf("%d", &n);
	int k; scanf("%d", &k);
	for (int i = 0; i < k; ++i) {
		int y, x; scanf("%d %d", &y, &x);
		apple.push_back(make_pair(y - 1, x - 1));
	}
	int l; scanf("%d", &l);
	for (int i = 0; i < l; ++i) {
		int x; char c;
		scanf("%d %c", &x, &c);
		dir.push_back(make_pair(x, c));
	}

	int time = 1;
	//뱀 머리 초기값
	snake.push_back({ 0,0,1 });
	int dirIdx = 0;
	int snakeSize = snake.size();
	while (true) {
		//뱀 머리 움직이기
		int nowy = snake[snakeSize - 1].y;
		int nowx = snake[snakeSize - 1].x;
		int headDir = snake[snakeSize - 1].dir;
		int heady = nowy + my[headDir];
		int headx = nowx + mx[headDir];
		snake.push_back({ heady, headx, headDir });
		snakeSize = snake.size();

		bool checkOver = false;
		//뱀 머리가 보드 밖으로 나간다면
		if (heady < 0 || heady >= n || headx < 0 || headx >= n)
			break;

		//뱀 머리가 자신의 몸통에 부딫힌다면
		for (int i = 0; i < snakeSize - 1; ++i)
			if (heady == snake[i].y && headx == snake[i].x) {
				checkOver = true;
				break;
			}
		if (checkOver)
			break;

		//사과
		bool appFlag = false;
		for (int i = 0; i < apple.size(); ++i) {
			if (apple[i].first == heady && apple[i].second == headx) {
				appFlag = true;
				//사과는 한번 먹으면 없애주어야 한다.
				apple[i].first = -1;
				apple[i].second = -1;
				break;
			}
		}
		//사과를 못먹었다면 꼬리를 자른다.
		if (!appFlag) {
			vector<state> tmp(snakeSize - 1);
			for (int i = 1; i < snakeSize; ++i)
				tmp[i - 1] = snake[i];
			snake = tmp;
			snakeSize = snake.size();
		}

		//회전
		if (dir[dirIdx].first == time) {
			if (dir[dirIdx].second == 'D')
				snake[snakeSize - 1].dir = (snake[snakeSize - 1].dir + 1) % 4;
			else if (dir[dirIdx].second == 'L')
				snake[snakeSize - 1].dir = (snake[snakeSize - 1].dir + 3) % 4;
			dirIdx++;
			//인덱스 처리
			if (dirIdx >= dir.size()) dirIdx = 0;
		}
		time++;
	}
	printf("%d\n", time);

	return 0;
}
