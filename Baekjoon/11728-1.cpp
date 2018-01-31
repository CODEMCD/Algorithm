#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
#define N 1000001
int a[N];
int b[N];
int c[2 * N];

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < m; i++)
		scanf("%d", &b[i]);
	for (int i = 0; i < n; i++)
		c[i] = a[i];
	for (int i = n; i < n + m; i++)
		c[i] = b[i - n];
	/*for (int i = 0; i < n + m; i++)
		printf("%d ", c[i]);
	printf("\n");*/
	sort(c, c + n + m);
	for (int i = 0; i < n + m; i++)
		printf("%d ", c[i]);

	return 0;
}