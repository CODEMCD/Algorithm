#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define N 5000001
int num[N];

int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);
	sort(num, num + n);
	printf("%d\n", num[k - 1]);

	return 0;
}
