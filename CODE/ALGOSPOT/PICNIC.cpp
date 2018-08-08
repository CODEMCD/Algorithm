#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
using namespace std;
#define N 10
int n;
bool areFriends[N][N];
//taken[i] = i번째 학생이 짝을 이미 찾았으면 true, 아니면 false
int countPairings(bool taken[N])
{
	//남은 학생들 중 가장 번호가 빠른 학생을 찾는다.
	int firstFree = -1;
	for (int i = 0; i < n; i++) {
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}
	//기저 사례 : 모든 학생이 짝을 찾았으면 한 가지 방법을 찾았으니 종료한다.
	if (firstFree == -1) return 1;
	int ret = 0;
	//이 학생과 짝지을 학생을 결정한다.
	for (int pairWith = firstFree + 1; pairWith < n; pairWith++) {
		if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairings(taken);
			//모든 경우의 수를 구해야하기 때문에 초기화해야함
			taken[firstFree] = taken[pairWith] = false; 
		}
	}
	return ret;
}

int main(void)
{
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				areFriends[i][j] = false;
		int m;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++) {
			int f, s;
			scanf("%d %d", &f, &s);
			areFriends[f][s] = areFriends[s][f] = true;
		}
		bool taken[10] = { false, };
		int ans = countPairings(taken);
		printf("%d\n", ans);
	}

	return 0;
}