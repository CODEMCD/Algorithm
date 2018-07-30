#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
//dp: 현재 가치일때, 최소 동전 개수를 저장할 배열
//coin: 동전 종류를 입력할 배열
int dp[10001], coin[101];
const int INF = 987654321;

int main() 
{
	int n, k; scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &coin[i]);

	//dp[0] = 0이어야 함.
	for (int i = 1; i <= k; i++) {
		//현재 가치의 최소 동전 개수를 구하기 위해 큰 값으로 초기화
		int currentCost = INF;
		for (int j = 0; j < n; j++) {
			//이전 동전 가치 = 현재 가치 - 각 동전 가치
			int preCoin = i - coin[j];
			//이전 동전 가치가 0보다 크거나 같고, 
			//이전 동전 가치를 만들수 있고(-1이 아님), 
			//이전보다 동전 개수를 적게 사용한다면 갱신한다.
			if (preCoin >= 0 && dp[preCoin] != -1 &&
				currentCost > dp[preCoin] + 1)
				currentCost = dp[preCoin] + 1;
		}
		if (currentCost == INF)
			dp[i] = -1;
		else
			dp[i] = currentCost;
	}
	/*for (int i = 0; i < k; i++)
		printf("%d ", dp[i]);*/
	printf("%d\n", dp[k]);

	return 0;
}
