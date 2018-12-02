#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	int tc; scanf("%d", &tc);
	while (tc--) {
		int k, n; scanf("%d %d", &k, &n);
		int cnt = 0;
		long long a = 1983;
		long long n2_32 = (long long)pow(2.0, 32.0);

		for (int i = 1; i <= n; ++i) {
			long long sum = 0;
			long long na = a;
			for (int j = i; j <= n; ++j) {
				sum += na % 10000 + 1;
				if (sum == k) cnt++;
				else if (sum > k) break;
				na = (na * 214013 + 2531011) % n2_32;
			}
			a = (a * 214013 + 2531011) % n2_32;
		}
		printf("%d\n", cnt);
	}

	return 0;
}
