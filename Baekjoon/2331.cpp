#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define N 1000001
int num[N];

int pow(int x, int p)
{
	int ans = 1;
	for (int i = 0; i < p; i++) {
		ans = ans *x;
	}
	return ans;
}

int main(void)
{
	int a, p, cnt = 1, result = -1;
	scanf("%d %d", &a, &p);
	num[0] = a;
	while (1) {
		int res = 0;
		while(a > 0) {
			res += pow(a % 10, p);
			a /= 10;
		}
		num[cnt] = res;
		a = res;
		cnt++;
		for (int j = 0; j < cnt - 1; j++) {
			if (num[j] == res) {
				result = j;
				break;
			}
		}
		if (result > -1)
			break;
	}

	printf("%d\n", result);
	return 0;
}
