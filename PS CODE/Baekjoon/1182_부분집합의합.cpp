#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 21
int num[N];
bool flag[N];
int cnt, sum, s, nn;

int combination(int n, int r)
{
	if (n == r) {
		for (int i = 0; i < n; i++)
			flag[i] = true;
		sum = 0;
		for (int i = 0; i < nn; i++)
			if (flag[i])
				sum += num[i];
		if (sum == s)
			cnt++;
		for (int i = 0; i < n; i++)
			flag[i] = false;
		return 0;
	}
	if (r == 1) {
		for (int i = 0; i < n; i++) {
			flag[i] = true;
			sum = 0;
			for (int j = 0; j < nn; j++)
				if (flag[j])
					sum += num[j];
			if (sum == s)
				cnt++;
			flag[i] = false;
		}
		return 0;
	}
	flag[n - 1] = true;
	combination(n - 1, r - 1);
	flag[n - 1] = false;
	combination(n - 1, r);
	return 0;
}

int main() 
{
	scanf("%d %d", &nn, &s);
	for (int i = 0; i < nn; i++)
		scanf("%d", &num[i]);

	for (int i = 1; i <= nn; i++) {
		memset(flag, false, sizeof(flag));
		combination(nn, i);
	}
	printf("%d\n", cnt);

	return 0;
}
