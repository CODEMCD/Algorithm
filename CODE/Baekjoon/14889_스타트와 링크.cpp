/* 
DFS
소요시간: 56ms
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 987654321;
int map[21][21];
bool visited[21];
int n, cnt = 0, ans = INF;

//두 팀의 능령치를 모두 계산하여 차이를 구한 후 최소값을 저장한다.
void calAbility() {
	vector<int> start, link;
	int startA = 0, linkA = 0;

	for (int i = 0; i < n; ++i)
		if (visited[i])
			start.push_back(i);
		else
			link.push_back(i);
	int size = n / 2;
	for (int i = 0; i < size; ++i)
		for (int j = i + 1; j < size; ++j)
			startA += (map[start[i]][start[j]] + map[start[j]][start[i]]);
	for (int i = 0; i < size; ++i)
		for (int j = i + 1; j < size; ++j)
			linkA += (map[link[i]][link[j]] + map[link[j]][link[i]]);

	int diff = startA - linkA;
	diff = diff < 0 ? -diff : diff;
	ans = ans < diff ? ans : diff;
}

//두 팀을 만드는 모든 경우의 수를 DFS를 통해 구한다.
void dfs(int here) {
	visited[here] = true;
	cnt++;

	if (cnt == n / 2)
		calAbility();
	else {
		for (int i = here; i < n; ++i)
			if (!visited[i])
				dfs(i);
	}

	cnt--;
	visited[here] = false;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &map[i][j]);

	/*for (int i = 0; i < n; ++i)
		dfs(i);*/
	//경우의 수를 반반으로만 나누면 되므로 한번의 DFS으로
	//2팀으로 만드는 모든 경우를 구할 수 있다.
	dfs(0);

	printf("%d\n", ans);

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

/* 
조합
소요시간: 44ms
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 987654321;
int map[21][21];

int main()
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &map[i][j]);

	//flag: 조합을 계산할 배열(0과 1로 이루어져 있음), nC2계산
	vector<int> flag, start, link;
	for (int i = 0; i < n / 2; ++i)
		flag.push_back(0);
	for (int i = 0; i < n / 2; ++i)
		flag.push_back(1);

	int ans = INF;
	//모든 경우의 조합 집합을 계산한다.
	do {
		start.clear();
		link.clear();
		int startAbility = 0, linkAbility = 0;

		//두 팀을 각각 벡터에 저장한다.
		for (int i = 0; i < n; ++i) {
			if (flag[i])
				start.push_back(i);
			else if (!flag[i])
				link.push_back(i);
		}
		
		int ssize = start.size();
		int lsize = link.size();
		//두 팀의 능력치를 구한다.
		for (int i = 0; i < ssize; ++i)
			for (int j = i + 1; j < ssize; ++j)
				startAbility += (map[start[i]][start[j]] + map[start[j]][start[i]]);
		for (int i = 0; i < lsize; ++i)
			for (int j = i + 1; j < lsize; ++j)
				linkAbility += (map[link[i]][link[j]] + map[link[j]][link[i]]);

		int diff = startAbility - linkAbility;
		diff = diff < 0 ? -diff : diff;
		ans = ans < diff ? ans : diff;
	} while (next_permutation(flag.begin(), flag.end()));

	printf("%d\n", ans);

	return 0;
}
