#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
#define N 10
int num[N];

int solve(int *arr, int size)
{
	int sum = 0;
	for (int i = 0; i < size - 1; i++)
		sum += abs(arr[i] - arr[i + 1]);
	return sum;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);

	sort(num, num + n);
	//int i, j;
	int max = 0;
	/*while (1) {
		int sum = solve(num, n);
		if (sum > max)
			max = sum;
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
	}*/
	do {
		int sum = solve(num, n);
		if (sum > max)
			max = sum;
	} while (next_permutation(num, num + n));
	printf("%d\n", max);
	return 0;
}