#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
#define N 1001
//절대값 계산
#define abs(a) ((a) >= (0) ? (a) : (-a))
//학생 몸무게를 저장할 배열
int student[4][N];
//class1,2/class3,4를 더한 모든 경우의 수를 저장할 배열
vector<int> wsum12;
vector<int> wsum34;
//minDiff: (특정값 - 현재 4명 학생의 몸무게 합)의 최소값
//findWeight: 특정값에 가장 가까운 몸무게 합
int minDiff, findWeight;

//이진 탐색
int biSearch(int s, int e, int k, int idx)
{
	if (s > e) return -1;
	int mid = (s + e) / 2;

	//특정값에 가까운 몸무게 합 찾기
	int diff = k - (wsum12[idx] + wsum34[mid]);
	if (minDiff > abs(diff)) {
		minDiff = abs(diff);
		findWeight = wsum12[idx] + wsum34[mid];
	}
	//조건 1)
	else if (minDiff == abs(diff) && diff > 0)
		findWeight = wsum12[idx] + wsum34[mid];

	if (k == (wsum12[idx] + wsum34[mid]))
		return mid;
	else if (k > (wsum12[idx] + wsum34[mid]))
		return biSearch(mid + 1, e, k, idx);
	else
		return biSearch(s, mid - 1, k, idx);
}

int main(void)
{
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		minDiff = INT_MAX; findWeight = 0;
		wsum12.clear(); wsum34.clear();
		memset(student, 0, sizeof(student));

		int k, n;
		scanf("%d %d", &k, &n);
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &student[i][j]);
		//2개의 class의 학생들 몸무게를 더한 모든 경우의 수 저장
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				wsum12.push_back(student[0][i] + student[1][j]);
				wsum34.push_back(student[2][i] + student[3][j]);
			}
		}

		//이진 탐색을 위한 오름차순 정렬
		sort(wsum34.begin(), wsum34.end());
		//순차 탐색 + 이진 탐색
		for (int i = 0; i < (int)wsum12.size(); i++)
			biSearch(0, (int)wsum34.size() - 1, k, i);
		printf("%d\n", findWeight);
	}

	return 0;
}