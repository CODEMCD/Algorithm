#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 4
int check[N];
int main(void)
{
	char str[102];
	while (fgets(str, 102, stdin) != NULL) {
		for (int i = 0; i < N; i++)
			check[i] = 0;
		int len = strlen(str);
		str[len - 1] = '\0';
		//printf("%s\n", str);
		for (int i = 0; i <= len; i++) {
			for (int j = 'a'; j <= 'z'; j++)
				if (str[i] == j)
					check[0]++;
			for (int j = 'A'; j <= 'Z'; j++)
				if (str[i] == j)
					check[1]++;
			for (int j = '0'; j <= '9'; j++)
				if (str[i] == j)
					check[2]++;
			if (str[i] == ' ')
				check[3]++;
		}
		for (int i = 0; i < N; i++)
			printf("%d ", check[i]);
		printf("\n");
	}
	return 0;
}