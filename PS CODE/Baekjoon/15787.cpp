#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 100000
bool train[N][20];
int check[N];

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	//명령어 처리
	for (int i = 0; i < m; i++) {
		int cmd;
		scanf("%d", &cmd);
		if (cmd == 1 || cmd == 2) {
			int tn, tx;
			scanf("%d %d", &tn, &tx);
			if (cmd == 1)
				train[tn - 1][tx - 1] = true;
			else if (cmd == 2)
				train[tn - 1][tx - 1] = false;
		}
		else if (cmd == 3 || cmd == 4) {
			int tn;
			scanf("%d", &tn);
			if (cmd == 3) {
				for (int j = 18; j >= 0; j--)
					train[tn - 1][j + 1] = train[tn - 1][j];
				train[tn - 1][0] = false;
			}
			else if (cmd == 4) {
				for (int j = 1; j < 20; j++)
					train[tn - 1][j - 1] = train[tn - 1][j];
				train[tn - 1][19] = false;
			}
		}
	}
	//기차좌석을 이진수로 하여 서로 구분한다.
	for (int i = 0; i < n; i++) {
		int num = 0;
		for (int j = 0; j < 20; j++) {
			if (train[i][j])
				num += (int)pow(2.0, (double)j);
		}
		check[i] = num;
	}
	//오름차순으로 정렬
	sort(check, check + n);

	//중복 검사
	int sameCheck = check[0];
	int res = 1;
	for (int i = 1; i < n; i++) {
		if (check[i] != sameCheck) {
			sameCheck = check[i];
			res++;
		}
	}
	printf("%d\n", res);

	return 0;
}