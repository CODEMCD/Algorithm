#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;
const int INF = 987654321;

//계단에 도착한 사람의 상태 클래스
class state {
public:
	int arriveTime;  //도착 시간
	int stairNum;    //계단 번호
	int personNum;   //사람 번호
};

//거리 계산
int calDist(int py, int px, int sy, int sx) {
	return abs(py - sy) + abs(px - sx);
}

//sort함수를 위한 연산자 오버로딩
bool operator <(const state &a, const state &b) {
	return a.arriveTime < b.arriveTime;
}

int main(void)
{	
	int tc; scanf("%d", &tc);
	for (int t = 1; t <= tc; ++t) {
		int n; scanf("%d", &n);
		//사람의 위치를 저장하는 벡터
		vector<pair<int, int>> person;
		//계단의 위치를 저장하는 벡터
		vector<pair<int, int>> stair;
		//계단의 길이를 저장할 배열
		int sLen[2], cnt = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				int loc; scanf("%d", &loc);
				if (loc == 1)
					person.push_back(make_pair(i, j));
				else if (loc > 1) {
					stair.push_back(make_pair(i, j));
					sLen[cnt++] = loc;
				}
			}
		int ans = INF;
		int psize = person.size();
		//계단 2개를 이용하는 모든 경우의 수를 탐색 (조합 사용)
		for (int i = 0; i <= psize; ++i) {
			vector<int> flag;
			for (int j = 0; j < psize - i; ++j)
				flag.push_back(0);
			for (int j = 0; j < i; ++j)
				flag.push_back(1);
			//조합 계산
			do {
				//각 사람에게 주어진 계단에 도착할 때의 정보를 저장하는 벡터
				vector<state> arriveState;
				//계단의 상황을 통제하는 벡터 {계단 번호, 계단을 내려가는데 걸리는 시간 }
				//계단을 내려가는데 걸리는 시간이
				//-1: 계단을 모두 내려온 후로 계산에서 제외함
				//0: 현재 시간에 계단을 모두 내려옴
				//0보다 큰수: 계단을 내려거야할 시간
				vector<pair<int, int>> s1, s2;
				//{ 계단까지 거리, 계단 번호, 사람 번호 }
				for (int j = 0; j < psize; ++j) {
					if (!flag[j]) {
						arriveState.push_back({ calDist(person[j].first, person[j].second,
							stair[0].first, stair[0].second), 0, j });
					}
					else {
						arriveState.push_back({ calDist(person[j].first, person[j].second,
							stair[1].first, stair[1].second), 1, j });
					}
				}

				//계단에 도착하는 시간을 오름차순으로 정렬
				//GCC 컴파일러에서는 sort함수의 세번째 인자가 없거나 기존의 방법과 다른듯하다.
				//연산자 오버로딩으로 대체하였다.
				/*sort(arriveState.begin(), arriveState.end(), [](state &a, state &b) {
					return a.arriveTime < b.arriveTime;
				});*/
				sort(arriveState.begin(), arriveState.end());

				//time: 시간, serviced: 계단을 모두 내려간 사람 수
				int time = 0, serviced = 0;
				//시뮬레이션
				while (true) {
					//기저 사례: 계단을 모두 내려간 사람 수와 전체 사람수가 같으면 종료
					if (serviced == psize) break;

					int vcnt = 0;
					//계단 1
					for (int j = 0; j < s1.size(); ++j) {
						//계단을 사용할 수 있는 최대 사람 수인 3명을 넘으면 빠져나간다.
						if (vcnt == 3) break;
						if (s1[j].second > 0) {
							s1[j].second--;
							vcnt++;
						}
						//계단을 모두 내려갔다면 서비스완료 사람수를 늘리고 시간에 -1값을 넣는다.
						else if (s1[j].second == 0) {
							serviced++;
							s1[j].second = -1;
						}
					}
					vcnt = 0;
					//계단 2
					for (int j = 0; j < s2.size(); ++j) {
						if (vcnt == 3) break;
						if (s2[j].second > 0) {
							s2[j].second--;
							vcnt++;
						}
						else if (s2[j].second == 0) {
							serviced++;
							s2[j].second = -1;
						}
					}

					//현재 시간에 계단에 도착하는 사람이 있는지 탐색한다.
					for (int j = 0; j < psize; ++j) {
						if (arriveState[j].arriveTime == time) {
							if (arriveState[j].stairNum == 0)
								s1.push_back({ arriveState[j].personNum, sLen[0] });
							else if(arriveState[j].stairNum == 1)
								s2.push_back({ arriveState[j].personNum, sLen[1] });
						}
					}

					//시간 증가
					time++;
				}

				//시간을 1증가하고 시뮬레이션이 종료되므로 시간을 1빼준다.
				ans = ans < (time - 1) ? ans : (time - 1);
			} while (next_permutation(flag.begin(), flag.end()));
		}

		printf("#%d %d\n", t, ans);
	}

	return 0;
}
