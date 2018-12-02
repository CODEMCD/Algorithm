#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int my[4] = { -1, 0, 1, 0 };
int mx[4] = { 0, 1, 0, -1 };

//도시 입력
int cmap[21][21];
//kv[i] = k의 크기가 i일때 방범 서비스를 제공할 수 있는 모든 좌표의 집합
vector<pair<int, int>> kv[25];

//가로세로 최대 크기 20인 배열을 모두 방범 서비스를 제공할 k의 최대 크기는 대략 23 ~ 25이다.
//미리 k의 크기에 따른 방범 서비스를 할 수 있는 좌표 집합을 만든다.
void makeKSet() {
	//k = 1일때
	kv[0].push_back({ 0, 0 });
	//k = 2일때 부터 계산을 한다.
	for (int i = 1; i < 25; ++i) {
		int pre_ksize = kv[i - 1].size();
		kv[i] = kv[i - 1];
		for (int j = 0; j < pre_ksize; ++j) {
			for (int k = 0; k < 4; ++k) {
				int nexty = kv[i - 1][j].first + my[k];
				int nextx = kv[i - 1][j].second + mx[k];
				bool flag = false;
				//중복되는 좌표가 있는지 검사한다.
				for(int l = 0; l < kv[i].size(); ++l)
					if (kv[i][l].first == nexty && kv[i][l].second == nextx) {
						flag = true;
						break;
					}
				//중복이 없으면 추가한다.
				if (!flag)
					kv[i].push_back({ nexty, nextx });
			}
		}
	}
}

//k에 따른 운영 비용을 반환한다.
int calOperationFin(int k) {
	return (k * k) + ((k - 1) * (k - 1));
}

int main(void)
{	
	makeKSet();
	int tc; scanf("%d", &tc);
	for (int t = 1; t <= tc; ++t) {
		memset(cmap, 0, sizeof(cmap));
		int n, m; scanf("%d %d", &n, &m);
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				scanf("%d", &cmap[i][j]);

		int ans = 0;
		//k에 따라 방범 서비스를 받을 수 있는 최대 집의 개수를 계산한다.
		for(int i = 0; i < 25; ++i) {
			//현재 k에서 운영 비용
			int curOF = calOperationFin(i + 1);
			//현재 k에서 모든 좌표를 순회한다.
			for (int y = 0; y < n; ++y) {
				for (int x = 0; x < n; ++x) {
					int serviced = 0, curProfit;
					//현재 좌표에서 방범 서비스를 받을 수 있는 집의 개수 계산
					for (int j = 0; j < kv[i].size(); ++j) {
						int nexty = y + kv[i][j].first;
						int nextx = x + kv[i][j].second;
						if (nexty >= 0 && nexty < n && nextx >= 0 && nextx < n)
							if (cmap[nexty][nextx])
								serviced++;
					}
					curProfit = (serviced * m) - curOF;
					//비용 손해를 보지 않는다면 최대 집 개수를 갱신한다.
					if (curProfit >= 0)
						ans = ans > serviced ? ans : serviced;		
				}
			}
		}

		printf("#%d %d\n", t, ans);
	}

	return 0;
}
