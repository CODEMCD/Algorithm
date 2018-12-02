#define _CRT_SECURE_NO_WARNINGS
/*
그리디 문제
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define max(a,b) ((a) > (b) ? (a) : (b))
#define N 10001

class Lunch {
public:
	int heatTime, eatTime;
	Lunch(int heat, int eat) {
		this->heatTime = heat;
		this->eatTime = eat;
	}
};

int timeHist[N];  //도시락을 데우는 시간을 누적한 값 저장
int totalEat[N];  //기다린 시간 + 도시락 데우는 시간 + 먹는 시간 값 저장
vector<Lunch> heatEat;  //(데우는 시간, 먹는 시간)
int heat[N];  //데우는 시간

void init()
{
	heatEat.clear();
	for (int i = 0; i < N; i++) {
		timeHist[i] = 0;
		totalEat[i] = 0;
		heat[i] = 0;
	}
}

bool compare(const Lunch &a, const Lunch &b)
{
	return a.eatTime > b.eatTime;
}

int main() 
{
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		init();
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &heat[i]);
		for (int i = 0; i < n; i++) {
			int eat;
			scanf("%d", &eat);
			heatEat.push_back(Lunch(heat[i], eat));
		}
		sort(heatEat.begin(), heatEat.end(), compare);
		/*for (int i = 0; i < n; i++)
			printf("%d %d\n", heatEat[i].heatTime, heatEat[i].eatTime);*/

		timeHist[0] = heatEat[0].heatTime;
		totalEat[0] = timeHist[0] + heatEat[0].eatTime;
		for (int i = 1; i < n; i++) {
			timeHist[i] = timeHist[i - 1] + heatEat[i].heatTime;
			totalEat[i] = timeHist[i] + heatEat[i].eatTime;
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
			ans = max(ans, totalEat[i]);
		printf("%d\n", ans);
	}

	return 0;
}

/*
먹는 시간을 내림차순으로 정렬
*/