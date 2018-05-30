#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
using namespace std;
#define N 10
int n;
bool areFriends[N][N];
//taken[i] = i��° �л��� ¦�� �̹� ã������ true, �ƴϸ� false
int countPairings(bool taken[N])
{
	//���� �л��� �� ���� ��ȣ�� ���� �л��� ã�´�.
	int firstFree = -1;
	for (int i = 0; i < n; i++) {
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}
	//���� ��� : ��� �л��� ¦�� ã������ �� ���� ����� ã������ �����Ѵ�.
	if (firstFree == -1) return 1;
	int ret = 0;
	//�� �л��� ¦���� �л��� �����Ѵ�.
	for (int pairWith = firstFree + 1; pairWith < n; pairWith++) {
		if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairings(taken);
			//��� ����� ���� ���ؾ��ϱ� ������ �ʱ�ȭ�ؾ���
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