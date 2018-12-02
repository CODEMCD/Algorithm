#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define MIN(a,b) ((a)<(b)?(a):(b))

int main(void)
{
	int n, m, ans;
	scanf("%d %d", &n, &m);
	if (n == 1)
		ans = 1;
	else if (n == 2)
		ans = MIN(4, (m + 1) / 2);
	else if (n >= 3) {
		if (m >= 7)
			ans = m - 2;
		else
			ans = MIN(4, m);
	}
	printf("%d\n", ans);

	return 0;
}