#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
#define N 2
int arr[N][N];
int cnt, r, c;

void solve(int x, int y, int n)
{
	if (n == 2) {
		arr[0][0] = cnt++;  //x-1,y-1
		arr[0][1] = cnt++;  //x-1,y
		arr[1][0] = cnt++;  //x,y-1
		arr[1][1] = cnt++;  //x,y
		if (x == r && y == c)
			printf("%d\n", arr[1][1]);
		else if (x == r && y - 1 == c)
			printf("%d\n", arr[1][0]);
		else if (x - 1 == r && y == c)
			printf("%d\n", arr[0][1]);
		else if (x - 1 == r && y - 1 == c)
			printf("%d\n", arr[0][0]);
		return;
	}
	int m = n / 2;
	solve(x - m, y - m, m);
	solve(x - m, y, m);
	solve(x, y - m, m);
	solve(x, y, m);
}


int main(void)
{
	int n;
	scanf("%d %d %d", &n, &r, &c);
	int nn = (int)pow(2, n);
	solve(nn - 1, nn - 1, nn);
	//for (int i = 0; i < nn; i++) {
	//	for (int j = 0; j < nn; j++)
	//		printf("%d ", arr[i][j]);
	//	printf("\n");
	//}
	return 0;
}