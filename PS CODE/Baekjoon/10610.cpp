#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define N 100001
char sep[N];
bool cmp(int a, int b) { return a > b; }

int main(void)
{
	scanf("%s", sep);
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (sep[i] == '\0') {
			cnt = i;
			break;
		}
	}
	int sum = 0;
	sort(sep, sep + cnt);
	for (int i = 0; i < cnt; i++) {
		sum += (sep[i] - '0');
		//printf("%c ", sep[i]);
	}
	int check = 0;
	if (sep[0] == '0' && sum % 3 == 0) {
		sort(sep, sep + cnt, cmp);
	}
	else
		check = -1;
	if (check == -1)
		printf("%d\n", check);
	else
		printf("%s\n", sep);
	return 0;
}