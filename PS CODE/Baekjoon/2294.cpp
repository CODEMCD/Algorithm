#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
//dp: ���� ��ġ�϶�, �ּ� ���� ������ ������ �迭
//coin: ���� ������ �Է��� �迭
int dp[10001], coin[101];
const int INF = 987654321;

int main() 
{
	int n, k; scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &coin[i]);

	//dp[0] = 0�̾�� ��.
	for (int i = 1; i <= k; i++) {
		//���� ��ġ�� �ּ� ���� ������ ���ϱ� ���� ū ������ �ʱ�ȭ
		int currentCost = INF;
		for (int j = 0; j < n; j++) {
			//���� ���� ��ġ = ���� ��ġ - �� ���� ��ġ
			int preCoin = i - coin[j];
			//���� ���� ��ġ�� 0���� ũ�ų� ����, 
			//���� ���� ��ġ�� ����� �ְ�(-1�� �ƴ�), 
			//�������� ���� ������ ���� ����Ѵٸ� �����Ѵ�.
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
