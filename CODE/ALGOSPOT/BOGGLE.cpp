#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char map[5][5];
char word[11];
int dp[5][5][10];
int mx[8] = { 0,1,1,1,0,-1,-1,-1 };
int my[8] = { -1,-1,0,1,1,1,0,-1 };

int solve(int y, int x, int idx)
{
	int &ret = dp[y][x][idx];
	//�ʱ�ȭ ���� ó��
	if (ret != -1) return ret;
	for (int i = 0; i < 8; i++) {
		int nexty = y + my[i];
		int nextx = x + mx[i];

		if (nexty >= 0 && nexty < 5 && nextx >= 0 && nextx < 5) {
			//�ܾ�� ��ġ�Ǵ� ���ĺ��� ã���� ��,
			if (map[nexty][nextx] == word[idx]) {
				//�ܾ��� ���� ���ڰ� NULL�̸�, ��� ã�ұ� ������ TRUE�� ��ȯ
				if (word[idx + 1] == '\0') return ret = 1;
				//���� �ܾ ã�� ���� �����ִٸ� �ٽ� ����Լ� ȣ��
				ret = solve(nexty, nextx, idx + 1);  
				//���ڿ��� ã�Ҵٸ� ���� ����Լ����� ��� 1(TRUE)���� ��ȯ�Ͽ� ������ ����� 1�� ��ȯ�ϵ��� �Ѵ�.
				if (ret) return ret;
			}
		}
	}
	//���ڸ� ��� ��Ī�� �� �����Ƿ� FALSE�� ��ȯ
	return false;
}

int find()
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			int &ret = dp[i][j][0];
			if (ret != -1) return ret;  //�ʱ�ȭ�� �ȉ�ٸ� �ٷ� ����(���� ó��)
			if (map[i][j] == word[0]) {  //ù �ܾ map���� ã�Ҵٸ�
				ret = solve(i, j, 1);
				if (ret) return ret;
			}
		}
	}
	return false;
}

int main(void)
{
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		for (int i = 0; i < 5; i++)
			scanf("%s", map[i]);
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			memset(dp, -1, sizeof(dp));
			scanf("%s", word);
			printf("%s %s\n", word, find() ? "YES" : "NO");
		}
	}
	return 0;
}