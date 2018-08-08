#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 21
int d[N][N];
bool check[101];

bool search(int x, int y, int a, int b)
{
	memset(check, false, sizeof(check));
	check[0] = true;
	for (int i = 0; i <= a; i++) {  //������ �Ʒ�
		if (check[d[x + i][y + i]])
			return false;
		check[d[x + i][y + i]] = true;
	}
	for (int i = 1; i <= b; i++) {  //���� �Ʒ�
		if (check[d[x + i][y - i]])
			return false;
		check[d[x + i][y - i]] = true;
	}
	for (int i = 1; i <= a; i++) {
		if (check[d[x + b + i][y - b + i]])
			return false;
		check[d[x + b + i][y - b + i]] = true;
	}
	for (int i = 1; i < b; i++) {
		if (check[d[x + a + i][y + a - i]])
			return false;
		check[d[x + a + i][y + a - i]] = true;
	}
	return true;
}

int main(void)
{
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &d[i][j]);
		int ans = -1;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int a = 1; j + a < n; a++) {  //a : ������ �Ʒ��� �� �� �ִ� ��
					for (int b = 1; i + a + b < n && j - b >= 0; b++) {  //b : ���� �Ʒ��� �� �� �ִ� ��
						if (search(i, j, a, b))  //���簢���� ���� �� �ִ��� �Ǵ��ϴ� �Լ�
							ans = ans > ((a + b + 2) * 2 - 4) ? ans : ((a + b + 2) * 2 - 4);
					}
				}
			}
		}
		printf("#%d %d\n", tc, ans);
	}

	return 0;
}