#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 987654321;
//home: 집 좌표 저장
//chicken: 치킨집 좌표 저장
vector<pair<int, int>> home, chicken;

int main()
{
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			int in; scanf("%d", &in);
			if (in == 1) home.push_back(make_pair(i, j));
			else if (in == 2) chicken.push_back({ i, j });
		}
	int hsize = home.size();
	int csize = chicken.size();

	//모든 치킨집 중 m개를 뽑는 모든 경우의 수 계산(조합)
	vector<int> flag;
	for (int i = 0; i < csize - m; ++i)
		flag.push_back(0);
	for (int i = 0; i < m; ++i)
		flag.push_back(1);
	int ans = INF;
	do {
		int chickenStreet = 0;
		//각 집에서 선택된 m개의 치킨집까지 거리 중 가작 작은 값들의 합 계산
		for (int i = 0; i < hsize; ++i) {
			int findMin = INF;
			for (int j = 0; j < csize; ++j) {
				if (flag[j]) {
					int d1 = home[i].first - chicken[j].first;
					int d2 = home[i].second - chicken[j].second;
					d1 = d1 > 0 ? d1 : -d1;
					d2 = d2 > 0 ? d2 : -d2;
					findMin = findMin < (d1 + d2) ? findMin : (d1 + d2);
				}
			}
			chickenStreet += findMin;
		}
		ans = ans < chickenStreet ? ans : chickenStreet;
	} while (next_permutation(flag.begin(), flag.end()));

	printf("%d\n", ans);

	return 0;
}
