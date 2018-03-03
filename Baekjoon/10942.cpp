#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
using namespace std;
#define N 2001
int num[N];

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &num[i]);
	int m;
	scanf("%d", &m);
	while (m--) {
		int s, e;
		scanf("%d %d", &s, &e);
		bool check = true;
		while (s < e) {
			if (num[s] != num[e]) {
				check = false;
				break;
			}
			s++;
			e--;
		}
		if (check)
			printf("1\n");
		else
			printf("0\n");
	}

	return 0;
}
