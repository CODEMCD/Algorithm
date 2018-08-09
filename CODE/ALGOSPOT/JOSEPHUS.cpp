#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> sv;

int main()
{
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n, k; scanf("%d %d", &n, &k);
		for (int i = 1; i < n; i++)
			sv.push_back(i + 1);
		int size = sv.size();
		int pick = 0;
		while (size > 2) {
			pick = (pick + k - 1) % size;
			sv.erase(sv.begin() + pick);
			size = sv.size();
		}
		if (sv[0] < sv[1])
			printf("%d %d\n", sv[0], sv[1]);
		else
			printf("%d %d\n", sv[1], sv[0]);
		sv.clear();
	}

	return 0;
}
