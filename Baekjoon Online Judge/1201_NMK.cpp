#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int num[501];
int cut[501];
bool cmp(int a, int b) { return a > b; }

int main(void)
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		num[i] = i + 1;
	if (n < (m + k - 1) || n > (m * k))
		printf("-1\n");
	else {
		//sort(num+3, num+6, cmp);
		for (int i = 0; i < n; i++)
			cut[i] = 1;
		int msum = m;
		for (int i = 0; i < n; i++) {
			while (1) {
				if (msum < n && cut[i] < k) {
					cut[i]++;
					msum++;
				}
				else
					break;
			}
			if (msum == n)
				break;
		}
		//for (int i = 0; i < m; i++)
		//	printf("%d ", cut[i]);
		int start = 1;
		for (int i = 0; i < m; i++) {
			sort(num + (start - 1), num + (start + cut[i] - 1), cmp);
			start += cut[i];
		}
	}
	//printf("\n");
	for (int i = 0; i < n; i++)
		printf("%d ", num[i]);
	//printf("\n");
	return 0;
}