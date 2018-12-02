#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

//도형 회전 90도 공식 { {cos, -sin}, {sin, cos} }
int rot90[2][2] = { {0, -1}, {1, 0} };
//우, 상, 좌, 하
int my[4] = { 0, -1, 0, 1 };
int mx[4] = { 1, 0, -1, 0 };

vector<pair<int, int>> dragon[21];
bool map[101][101];

//현재 인덱스의 다음 드래곤 커브 모든 좌표를 계산하여 벡터에 모두 추가한다.
void makeDragonCurve(int idx) {
	//드래곤 커브 좌표들의 현재 크기
	int dsize = dragon[idx].size();
	//중심점
	int cy = dragon[idx][dsize - 1].first;
	int cx = dragon[idx][dsize - 1].second;

	//dragon벡터의 마지막 인덱스의 좌표가 중심점임을 유지하기 위해
	//끝 좌표부터 회전시킨다.
	for (int i = dsize - 2; i >= 0; --i) {
		int nowy = dragon[idx][i].first;
		int nowx = dragon[idx][i].second;

		//중심점이 원점일 때 현재 드래콘커브 좌표를 그에 맞게 변환하기
		int movy = nowy - cy;
		int movx = nowx - cx;

		//현재 좌표를 중심점을 기준으로 90도 회전
		int roty = rot90[1][0] * movx + rot90[1][1] * movy;
		int rotx = rot90[0][0] * movx + rot90[0][1] * movy;

		//원점에서 다시 원래 중심점을 기준으로 좌표로 변환하기
		int oriy = roty + cy;
		int orix = rotx + cx;

		dragon[idx].push_back(make_pair(oriy, orix));
	}
}

int main()
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x, y, d, g;
		scanf("%d %d %d %d", &x, &y, &d, &g);
		dragon[i].push_back({ y, x });

		//0세대
		dragon[i].push_back({ y + my[d], x + mx[d] });
		//1세대부터 주어진 세대까지 드래곤 커브 만들기
		for (int j = 0; j < g; ++j)
			makeDragonCurve(i);

		//현재 드래곤커브 지도에 표시하기
		int dsize = dragon[i].size();
		for (int j = 0; j < dsize; ++j)
			map[dragon[i][j].first][dragon[i][j].second] = true;
	}

	int ans = 0;
	//사각형 개수 구하기
	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j)
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1])
				ans++;

	printf("%d\n", ans);

	return 0;
}
