#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int map[101][101];

int main()
{
	int n, l; scanf("%d %d", &n, &l);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &map[i][j]);

	int lcnt, comp;
	bool uphill, downhill;
	int ans = 0;
	//horizontal
	for (int i = 0; i < n; ++i) {
		//비교할 높이
		comp = map[i][0];
		//경사로를 놓을 수 있는지 길이 측정
		lcnt = 1;
		//오르막길
		uphill = true;
		//내리막길
		downhill = true;
		for (int j = 1; j < n; ++j) {
			//높이가 같은 경우(평지)
			if (comp == map[i][j])
				lcnt++;
			//다른 경우
			else {
				//경사로 차이
				int diff = comp - map[i][j];
				//비교 높이 갱신
				comp = map[i][j];
				//경사가 높아지는 경우(오르막길)
				if (diff == -1) {
					//현재까지 평지였던 길이가 l이하면 경사로를 놓을 수 없다.
					if (lcnt < l) {
						uphill = false;
						break;
					}
					//갱신
					lcnt = 1;
				}
				//경사가 낮아지는 경우(내리막길)
				else if (diff == 1) {
					int k;
					//경사가 낮아진 높이에서 평지 길이를 측정한다.
					lcnt = 1;
					for (k = j + 1; k < n; ++k)
						if (comp == map[i][k] && lcnt < l)
							lcnt++;
						else
							break;
					//경사가 낮아진 높이의 평지가 l보다 작으면 경사로를 높을 수 없다.
					if (lcnt < l) {
						downhill = false;
						break;
					}
					//경사로를 길 마지막에 놓은 경우 바로 다음 길로 넘어간다.
					else if (k == n) break;
					//경사로를 놓을 수 있는 경우
					else {
						j = k;
						//경사로를 놓고 바로 다음 높이가 현재 낮아진 높이와 같은 경우
						if (comp == map[i][j])
							lcnt = 1;
						//현재 낮아진 높이보다 높아진 경우 오르막 경사로를 설치해야 하는데
						//이미 내리막 경사로를 설치한 후이므로 평지가 없다.
						else if (comp < map[i][j]) {
							uphill = false;
							break;
						}
						//현재 낮아진 높이보다 낮아진 경우 내리막 경사로를 지을 수 있는지
						//검사하기 위해 현재 높이로 설정 후 다음 높이로 넘어간다.
						else if (comp > map[i][j])
							j = k - 1;
					}
				}
				//높이 차이가 1보다 큰 경우는 경사로를 놓을 수 없다.
				else {
					downhill = false;
					uphill = false;
					break;
				}
			}
		}
		if (uphill && downhill) ans++;
	}

	//vertical
	for (int j = 0; j < n; ++j) {
		comp = map[0][j];
		lcnt = 1;
		uphill = true;
		downhill = true;
		for (int i = 1; i < n; ++i) {
			if (comp == map[i][j])
				lcnt++;
			else {
				int diff = comp - map[i][j];
				comp = map[i][j];
				if (diff == -1) {
					if (lcnt < l) {
						uphill = false;
						break;
					}
					lcnt = 1;
				}
				else if (diff == 1) {
					int k;
					lcnt = 1;
					for (k = i + 1; k < n; ++k)
						if (comp == map[k][j] && lcnt < l)
							lcnt++;
						else
							break;
					if (lcnt < l) {
						downhill = false;
						break;
					}
					else if (k == n) break;
					else {
						i = k;
						if (comp == map[i][j])
							lcnt = 1;
						else if (comp < map[i][j]) {
							uphill = false;
							break;
						}
						else if (comp > map[i][j])
							i = k - 1;
					}
				}
				else {
					downhill = false;
					uphill = false;
					break;
				}
			}
		}
		if (uphill && downhill) ans++;
	}

	printf("%d\n", ans);

	return 0;
}
