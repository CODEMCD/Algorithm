#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int num[101], check[101];
bool visited[101];
vector<int> ans;

void dfs(int v) {
	check[v]++;
	check[num[v]]++;
	if (check[num[v]] < 2)
		dfs(num[v]);
}

void init(int n) {
	for (int i = 0; i <= n; ++i)
		check[i] = 0;
}

int main(void)
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &num[i + 1]);

	for (int i = 1; i <= n; ++i) {
		init(n);
		dfs(i);
		bool flag = false;
		//�� �� ������� ������ �ٸ� ������ �����Ͽ� �� ū ������ ���� �� ����.
		//��, �� ������ ����� ����� ���� �� �ϳ��̴�.
		for (int j = 1; j <= n; ++j)
			if (check[j] == 1) {
				flag = true;
				break;
			}
		if (!flag) {
			for (int j = 1; j <= n; ++j)
				if (check[j] == 2 && !visited[j]) {
					ans.push_back(j);
					visited[j] = true;
				}
		}
	}

	printf("%d\n", ans.size());
	sort(ans.begin(), ans.end());
	for (int i = 0; i < (int)ans.size(); ++i)
		printf("%d\n", ans[i]);
	return 0;
}