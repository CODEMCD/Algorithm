#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

//북동남서
int my[4] = { -1, 0, 1, 0 };
int mx[4] = { 0, 1, 0, -1 };

//0: 빈칸(미청소)
//1: 벽
//2: 청소 완료
int map[51][51];

int main()
{
	int n, m; scanf("%d %d", &n, &m);
	int iy, ix, d; scanf("%d %d %d", &iy, &ix, &d);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d", &map[i][j]);

	bool flag = false;
	int ans = 0;
	while (true) {
		//기저 사례: 더이상 이동할 수 없는 경우
		if (flag) break;
		flag = true;

		//과정1) 최초로 빈칸을 만났을 때 청소한다.
		if (!map[iy][ix]) {
			map[iy][ix] = 2;
			ans++;
		}

		//과정 2)
		int nextDir = d;
		//과정 2-1), 2-2)를 반복하여 빈칸을 찾고, 네 방향에 더이상 빈칸이 없는지도 검사한다.
		for (int i = 0; i < 4; ++i) {
			//왼쪽 방향 설정
			nextDir = (nextDir + 3) % 4;
			int nexty = iy + my[nextDir];
			int nextx = ix + mx[nextDir];
			if (nexty < 0 || nexty >= n || nextx < 0 || nextx >= m)
				continue;
			//최초로 찾은 빈칸인 경우
			if (!map[nexty][nextx]) {
				iy = nexty;
				ix = nextx;
				d = nextDir;
				flag = false;
				//최초인 것을 유지하기 위해 반복문을 나간다.
				break;
			}
		}
		//과정 2-3) 2-4)
		if (flag) {
			//후진방향 설정
			int back = (d + 2) % 4;
			int backy = iy + my[back];
			int backx = ix + mx[back];
			//후진할 곳이 이미 청손한 곳이라면 후진할 수 있다.
			if (map[backy][backx] == 2) {
				iy = backy;
				ix = backx;
				flag = false;
			}
			//후진할 곳이 벽이라면 반복문을 빠져나간다.
		}
	}
	printf("%d\n", ans);
	
	return 0;
}
