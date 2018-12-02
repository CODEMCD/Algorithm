#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
#define N 21
bool s[N];

int main(void)
{
	int m;
	scanf("%d", &m);
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		char man[N];
		scanf("%s", man);
		if (strstr(man, "add") != NULL) {
			int num;
			scanf("%d", &num);
			if (s[num] == false)
				s[num] = true;
		}
		else if (strstr(man, "remove") != NULL) {
			int num;
			scanf("%d", &num);
			if (s[num] == true)
				s[num] = false;
		}
		else if (strstr(man, "check") != NULL) {
			int num;
			scanf("%d", &num);
			if (s[num] == true)
				printf("1\n");
			else
				printf("0\n");
		}
		else if (strstr(man, "toggle") != NULL) {
			int num;
			scanf("%d", &num);
			if (s[num] == true)
				s[num] = false;
			else
				s[num] = true;
		}
		else if (strstr(man, "all") != NULL) {
			for (int i = 1; i < N; i++)
				s[i] = true;
		}
		else if (strstr(man, "empty") != NULL) {
			for (int i = 1; i < N; i++)
				s[i] = false;
		}
	}
	return 0;
}