#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 9
int dwarf[N], ans[N];
bool flag[N];
int sum;

//뽑는 순서를 고려하지 않는 조합 계산, 9C7
int combination(int n, int r)
{
	if (n == r) {
		for (int i = 0; i < n; i++)
			flag[i] = true;
		sum = 0;
		for (int i = 0; i < N; i++) {
			if (flag[i]) {
				//printf("%d ", dwarf[i]);
				sum += dwarf[i];
			}
		}
		if (sum == 100) {
			int cnt = 0;
			for (int k = 0; k < N; k++)
				if (flag[k])
					ans[cnt++] = dwarf[k];
		}
		for (int i = 0; i < n; i++)
			flag[i] = false;
		//printf("sum = %d\n", sum);
		return 0;
	}
	if (r == 1) {
		for (int i = 0; i < n; i++) {
			flag[i] = true;
			sum = 0;
			for (int j = 0; j < N; j++) {
				if (flag[j]) {
					//printf("%d ", dwarf[j]);
					sum += dwarf[j];
				}
			}
			if (sum == 100) {
				int cnt = 0;
				for (int k = 0; k < N; k++)
					if (flag[k])
						ans[cnt++] = dwarf[k];
			}
			flag[i] = false;
			//printf("sum = %d\n", sum);
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
	for (int i = 0; i < N; i++)
		scanf("%d", &dwarf[i]);
	
	//9C7
	combination(N, 7);

	sort(ans, ans + 7);
	for (int i = 0; i < 7; i++)
		printf("%d\n", ans[i]);
	return 0;
}
