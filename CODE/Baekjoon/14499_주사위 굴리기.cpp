#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

//동서북남
int my[4] = { 0, 0, -1, 1 };
int mx[4] = { 1, -1, 0, 0 };
//hdice: 주사위전면도의 수평부분
//vdice: 주사위전면도의 수직부분
int hdice[3], vdice[4], tmp[4];
//지도
int map[21][21];
//명령어
int cmd[1001];

int main() 
{
	int n, m, y, x, k; 
	scanf("%d %d %d %d %d", &n, &m, &y, &x, &k);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d", &map[i][j]);
	for (int i = 0; i < k; ++i)
		scanf("%d", &cmd[i]);

	for (int i = 0; i < k; ++i) {
		//다음으로 이동할 위치
		int nexty = y + my[cmd[i] - 1];
		int nextx = x + mx[cmd[i] - 1];
		if (nexty < 0 || nexty >= n || nextx < 0 || nextx >= m)
			continue;

		//동쪽으로 이동한 경우
		if (cmd[i] == 1) {
			for (int j = 0; j < 3; ++j)
				tmp[(j + 1) % 3] = hdice[j];
			//바닥면이 바뀌는 것에 주의한다.
			int ttmp = tmp[0];
			tmp[0] = vdice[3];
			vdice[3] = ttmp;
			for (int j = 0; j < 3; ++j)
				hdice[j] = tmp[j];
			//윗면은 전면도 수직과 수평이 공유하기 때문에 갱신해야 한다.
			vdice[1] = hdice[1];
		}
		//서쪽
		//모듈러 계산을 위해 반대로 이동하기 위해 더하는 숫자를 양수로 바꾼다.
		//-1 -> +2
		else if (cmd[i] == 2) {
			for (int j = 0; j < 3; ++j)
				tmp[(j + 2) % 3] = hdice[j];
			int ttmp = tmp[2];
			tmp[2] = vdice[3];
			vdice[3] = ttmp;
			for (int j = 0; j < 3; ++j)
				hdice[j] = tmp[j];
			vdice[1] = hdice[1];
		}
		//북쪽
		else if (cmd[i] == 3) {
			for (int j = 0; j < 4; ++j)
				tmp[(j + 3) % 4] = vdice[j];
			for (int j = 0; j < 4; ++j)
				vdice[j] = tmp[j];
			hdice[1] = vdice[1];
		}
		//남쪽
		else if (cmd[i] == 4) {
			for (int j = 0; j < 4; ++j)
				tmp[(j + 1) % 4] = vdice[j];
			for (int j = 0; j < 4; ++j)
				vdice[j] = tmp[j];
			hdice[1] = vdice[1];
		}

		//이동한 위치의 값이 0인 경우
		if (map[nexty][nextx] == 0)
			map[nexty][nextx] = vdice[3];
		//0이 아닌 경우
		else {
			vdice[3] = map[nexty][nextx];
			map[nexty][nextx] = 0;
		}
		//현재 위치 갱신
		y = nexty;
		x = nextx;

		//현재 주사위 전면도의 윗면 출력
		printf("%d\n", vdice[1]);
	}

	return 0;
}
