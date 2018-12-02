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
		num[i] = i + 1;
	int i, j;
	while (1) {
		for (int i = 0; i < n; i++)
			printf("%d ", num[i]);
		printf("\n");
		i = n - 1; j = n - 1;
		while (i > 0 && num[i - 1] > num[i])
			i--;
		if (i == 0)
			break;
		else {
			while (num[i - 1] > num[j])
				j--;
			swap(num[i - 1], num[j]);
			sort(num + i, num + n);
		}
	}

	return 0;
}