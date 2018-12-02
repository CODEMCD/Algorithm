#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define N 1001
int b[N];

int main(void)
{
	int n = 10, cnt = 1;
	while (n--) {
		int t;
		scanf("%d", &t);
		for (int i = 0; i < t; i++)
			scanf("%d", &b[i]);
		int ans = 0;
		for (int i = 2; i < t - 2; i++) {
			if (b[i] > b[i - 1] && b[i] > b[i - 2] && b[i] > b[i + 1] && b[i] > b[i + 2]) {
				int max = 0;
				for (int j = i - 2; j <= i + 2; j++) {
					if (i != j && max < b[j])
						max = b[j];
				}
				ans += (b[i] - max);
				//printf("%d ", b[i]);
			}
		}
		printf("#%d %d\n", cnt++, ans);
		for (int i = 0; i < t; i++)
			b[i] = 0;
	}

	return 0;
}