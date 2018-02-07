#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
#define N 

int main(void)
{
	int e, s, m;
	scanf("%d %d %d", &e, &s, &m);
	e %= 15; s %= 28; m %= 19;
	int ans = 1;
	while (1) {
		if (ans % 15 == e && ans % 28 == s && ans % 19 == m)
			break;
		ans++;
	}
	printf("%d\n", ans);

	return 0;
}