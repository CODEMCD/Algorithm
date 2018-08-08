#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int coin[11];

int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &coin[i]);
	int min = 0;
	while (1) {
		for (int i = n - 1; i >= 0; i--) {
			if (coin[i] <= k) {
				k -= coin[i];
				min++;
				break;
			}
		}
		if (k == 0)
			break;
	}
	printf("%d\n", min);
	return 0;
}