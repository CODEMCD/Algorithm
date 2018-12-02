#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 102

int main(void)
{
	char str[N], ans[N];
	fgets(str, N, stdin);
	int len = strlen(str);
	str[len - 1] = '\0';
	strcpy(ans, str);
	for (int i = 0; i <= len; i++) {
		for(int j='a'; j<='z'; j++)
			if (str[i] == j) {
				if ('z' < str[i] + 13)
					ans[i] = 'a' + ((str[i] + 13) % 'z') - 1;
				else
					ans[i] = str[i] + 13;
			}
		for (int j = 'A'; j <= 'Z'; j++)
			if (str[i] == j) {
				if ('Z' < str[i] + 13)
					ans[i] = 'A' + ((str[i] + 13) % 'Z') - 1;
				else
					ans[i] = str[i] + 13;
			}
	}
	printf("%s\n", ans);

	return 0;
}