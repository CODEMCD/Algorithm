#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

//1000 이하의 유레카 수는 총 44개이므로 완전 탐색으로 해결 가능하다.
vector<int> eureka;
//유레카 수 구하기
void makeEureka() {
	int ret = 0, n = 1;
	while (true) {
		ret = n * (n + 1) / 2;
		if (ret <= 1000) {
			eureka.push_back(ret);
			n++;
		}
		else break;
	}
}

int main()
{
	makeEureka();
	int tc; scanf("%d", &tc);
	while (tc--) {
		int k; scanf("%d", &k);

		int euSize = eureka.size();
		bool flag = false;
		//유레카 수 3개로 입력받은 수가 만들어 질 수 있는지 판단		
		for (int i1 = 0; i1 < euSize; ++i1) {
			for (int i2 = 0; i2 < euSize; ++i2) {
				for (int i3 = 0; i3 < euSize; ++i3) {
					if (eureka[i1] + eureka[i2] + eureka[i3] == k) {
						flag = true;
						break;
					}
				}
				if (flag) break;
			}
			if (flag) break;
		}
	
		printf("%d\n", flag ? 1 : 0);
	}

	return 0;
}
