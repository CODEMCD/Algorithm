#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define N 500001
int ncard[N];
int mcard[N];
int check[N];

bool Bsearch(int *ar, int len, int target)
{
	int first = 0;
	int last = len - 1;
	int mid;
	while (first <= last) {
		mid = (first + last) / 2;

		if (target == ar[mid])
			return true;
		else {
			if (target < ar[mid])
				last = mid - 1;
			else
				first = mid + 1;
		}
	}
	return false;
}

int main(void)
{
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &ncard[i]);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &mcard[i]);
	sort(ncard, ncard + n);
	bool ch;
	for (int i = 0; i < m; i++) {
		ch = Bsearch(ncard, n, mcard[i]);
		if (ch == true)
			check[i] = 1;
	}
	for (int i = 0; i < m; i++)
		printf("%d ", check[i]);
	return 0;
}