#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
#define N 10001
int num[N];

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);
	int i, j;
	i = n - 1; j = n - 1;
	while (i > 0 && num[i - 1] > num[i])
		i--;
	if (i == 0) {
		printf("-1\n");
		return 0;
	}
	else {
		while (num[i - 1] > num[j])
			j--;
		swap(num[i - 1], num[j]);
		sort(num + i, num + n);
	}
	for (int i = 0; i < n; i++)
		printf("%d ", num[i]);

	return 0;
}