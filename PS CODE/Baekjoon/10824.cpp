#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 10

int main(void)
{
	char n[4][N];
	for (int i = 0; i < 4; i++)
		scanf("%s", n[i]);
	strcat(n[0], n[1]);
	strcat(n[2], n[3]);
	long long sum = atoll(n[0]) + atoll(n[2]);
	printf("%lld\n", sum);

	return 0;
}