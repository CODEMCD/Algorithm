#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;

int calDistSqr(int x1, int y1, int x2, int y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main(void)
{
	int tc; scanf("%d", &tc);
	while (tc--) {
		int sx, sy, ex, ey;
		scanf("%d %d %d %d", &sx, &sy, &ex, &ey);

		int ans = 0;
		int n; scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			int cx, cy, r;
			scanf("%d %d %d", &cx, &cy, &r);

			/*
			행성계사이는 서로 경계지점과 맞닿거나 교차하시 않고,
			행성계와 점사이는 경계지점과 맞닿지 않는다.
			위 조건을 바탕으로 행성계 진입/이탈 횟수는 4가지 경우로 나뉜다.
			(거리는 실수 계산을 피하기 위해 제곱으로 계산한다.)
			*/
			//시작점과 해당 행성계 중심사이 거리^2
			int distsc = calDistSqr(sx, sy, cx, cy);
			//도착점과 해당 행성계 중심사이 거리^2
			int distec = calDistSqr(ex, ey, cx, cy);
			//행성계 반지름^2
			int rs = r * r;

			// 1) 시작점과 도착점 모두 해당 행성계 밖에 있는 경우
			if (rs < distsc && rs < distec)
				//해당 행성계를 지날 필요가 없다.
				ans += 0;
			// 2) 시작점과 도착점 모두 행성계 안에 있는 경우
			else if (rs > distsc && rs > distec)
				ans += 0;
			// 3) 시작점은 행성계 밖, 도착점은 행성계 안에 있는 경우
			else if (rs > distsc && rs < distec)
				//시작점에서 도착점으로 갈려면 해당 행성계 경계를 지나야한다.
				ans += 1;
			// 4) 시작점은 행성계 안, 도착점은 행성계 밖에 있는 경우
			else if (rs < distsc && rs > distec)
				ans += 1;
		}

		printf("%d\n", ans);
	}

	return 0;
}