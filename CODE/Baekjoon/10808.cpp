#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 26
int a[N];
int main(void)
{
	char str[101];
	scanf("%s", str);
	int len = strlen(str);
	for (int i = 0; i <= len; i++) {
		for (int j = 'a'; j <= 'z'; j++)
			if (str[i] == j)
				a[j - 'a']++;
	}
	for (int i = 0; i < N; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}