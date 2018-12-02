#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 100001
int age[N], resAge[N], chAge[201];
char name[N][101], resName[N][101];

int main(void)
{
	int n, cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %s", &age[i], name[i]);
	for (int i = 0; i < n; i++)
		chAge[age[i]]++;
	for (int i = 1; i < 201; i++) {
		if (chAge[i] != 0) {
			for (int j = 0; j < n; j++) {
				if (age[j] == i) {
					resAge[cnt] = age[j];
					strcpy(resName[cnt], name[j]);
					cnt++;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d %s\n", resAge[i], resName[i]);
	return 0;
}