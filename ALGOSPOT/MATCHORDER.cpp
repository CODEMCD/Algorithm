#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> ra, ka;

//그리디
int main(void)
{
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int rrating;
			scanf("%d", &rrating);
			ra.push_back(rrating);
		}
		for (int i = 0; i < n; i++) {
			int krating;
			scanf("%d", &krating);
			ka.push_back(krating);
		}
		//둘 다 오름차순으로 하여 두 점수차가 가장 낮은 선수끼리의 배치를 순서대로 탐색하며 수행한다.
		sort(ra.begin(), ra.end());
		sort(ka.begin(), ka.end());
		int win = 0, saveJ = 0, j;
		for (int i = 0; i < n; i++) {
			for (j = saveJ; j < n; j++) {
				if (ra[i] <= ka[j]) {
					win++;
					saveJ = j + 1;  //그 다음 선수부터 탐색
					break;
				}
			}
		}
		printf("%d\n", win);
		ra.clear(); ka.clear();
	}

	return 0;
}
