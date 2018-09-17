#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
const int INF = 987654321;
const int RINF = -987654321;

int main(void)
{	
	int tc; scanf("%d", &tc);
	for (int t = 1; t <= tc; ++t) {
		int n; scanf("%d", &n);
		// 0: +, 1: -, 2: *, 3: /
		int oper[4] = { 0, };
		vector<int> opv;
		for (int i = 0; i < 4; ++i) {
			scanf("%d", &oper[i]);
			//연산자별로 저장하기(조합 탐색을 위해)
			for (int j = 0; j < oper[i]; ++j)
				opv.push_back(i);
		}
		int num[13] = { 0, };
		for (int i = 0; i < n; ++i)
			scanf("%d", &num[i]);

		//최대값은 음수를 포함한 범위안에서 가장 작은수
		//최소값은 가장 큰수로 초기화한다.
		int ans_max = RINF, ans_min = INF;
		//연산자는 총 4개이므로 숫자가 6개 이상이면 무조건 중복이 생긴다.
		//전체 조합 개수(O(N!))에서 중복된 연산자 조합 개수가 M일때
		//계산되는 시간 복잡도는 (O(N! / M!))이다.
		do {
			int cal_res = num[0];
			int cnt = 0;
			for (int i = 1; i < n; ++i) {
				switch (opv[cnt++]) {
				case 0: cal_res += num[i]; break;
				case 1: cal_res -= num[i]; break;
				case 2: cal_res *= num[i]; break;
				case 3: cal_res /= num[i]; break;
				default: break;
				}
			}
			ans_max = ans_max > cal_res ? ans_max : cal_res;
			ans_min = ans_min < cal_res ? ans_min : cal_res;

			/* //연산자의 모든 경우의 수 출력해보기
			for (int i = 1; i < n; ++i) {
				switch (opv[cnt++]) {
				case 0: printf("+ "); break;
				case 1: printf("- "); break;
				case 2: printf("* "); break;
				case 3: printf("/ "); break;
				default: break;
				}
			}
			printf("\n");*/
		} while (next_permutation(opv.begin(), opv.end()));
		printf("#%d %d\n", t, ans_max - ans_min);
	}

	return 0;
}
