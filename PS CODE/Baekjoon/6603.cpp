#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
#define N 14
int s[N];
int pm[N];

int main(void)
{
	int k;
	do {
		scanf("%d", &k);
		for (int i = 0; i < k; i++) {
			scanf("%d", &s[i]);
			if (i > 5)
				pm[i] = 0;
			else
				pm[i] = 1;
		}
		do {
			/*for (int i = 0; i < k; i++)
				printf("%d ", pm[i]);
			printf("\n");*/
			for (int i = 0; i < k; i++) {
				if (pm[i] == 1)
					printf("%d ", s[i]);
			}
			printf("\n");
		} while (prev_permutation(pm, pm + k));
		printf("\n");
	} while (k != 0);

	return 0;
}