#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
#define N 1001
//���밪 ���
#define abs(a) ((a) >= (0) ? (a) : (-a))
//�л� �����Ը� ������ �迭
int student[4][N];
//class1,2/class3,4�� ���� ��� ����� ���� ������ �迭
vector<int> wsum12;
vector<int> wsum34;
//minDiff: (Ư���� - ���� 4�� �л��� ������ ��)�� �ּҰ�
//findWeight: Ư������ ���� ����� ������ ��
int minDiff, findWeight;

//���� Ž��
int biSearch(int s, int e, int k, int idx)
{
	if (s > e) return -1;
	int mid = (s + e) / 2;

	//Ư������ ����� ������ �� ã��
	int diff = k - (wsum12[idx] + wsum34[mid]);
	if (minDiff > abs(diff)) {
		minDiff = abs(diff);
		findWeight = wsum12[idx] + wsum34[mid];
	}
	//���� 1)
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
		//2���� class�� �л��� �����Ը� ���� ��� ����� �� ����
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				wsum12.push_back(student[0][i] + student[1][j]);
				wsum34.push_back(student[2][i] + student[3][j]);
			}
		}

		//���� Ž���� ���� �������� ����
		sort(wsum34.begin(), wsum34.end());
		//���� Ž�� + ���� Ž��
		for (int i = 0; i < (int)wsum12.size(); i++)
			biSearch(0, (int)wsum34.size() - 1, k, i);
		printf("%d\n", findWeight);
	}

	return 0;
}