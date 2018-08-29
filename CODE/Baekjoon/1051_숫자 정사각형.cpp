#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 51
int square[N][N];

int main()
{
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%1d", &square[i][j]);

	//정사각형 넓이 최소값 1
	int area = 1;
	//주어진 직사각형에서 네 꼭지점의 수가 같은 정사각형 탐색(완전 탐색)
	for (int y = 0; y < n - 1; ++y) {
		for (int x = 0; x < m - 1; ++x) {
			//주어진 최대 길이 n,m보다 작을때까지 정사각형을 만든다.
			for (int w = 1; (y + w < n && x + w < m); ++w) {
				//네 꼭지점 숫자가 모두 같다면 현재 값중 큰 값을 선택한다.
				if (square[y][x] == square[y][x + w] &&
					square[y][x] == square[y + w][x] &&
					square[y][x] == square[y + w][x + w])
					area = max(area, (w + 1) * (w + 1));
			}
		}
	}
	printf("%d\n", area);

	return 0;
}
