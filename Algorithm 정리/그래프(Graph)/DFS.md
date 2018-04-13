# DFS(Depth First Search)

## 개념
- 한 길을 깊게 파고드는 방식으로 방문하지 않은 정점을 하나씩 방문하면서 그래프를 탐색한다.
- 스택(Stack)과 재귀를 이용하여 구현한다.
- 시간 복잡도 : 인접 행렬 - O(V^2), 인접 리스트 - O(V+E) (V : 정점, E : 간선)

## 구현 (인접 리스트)
~~~
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> num[1001];
bool check[1001];

void DFS(int node)  //using STACK
{
	check[node] = true;
	printf("%d ", node);
	for (int i = 0; i < num[node].size(); i++) {
	           int next = num[node][i];
	           if (check[next] == false)
 	                   DFS(next);
	}
}

int main(void)
{
	int n, m, start;
	scanf("%d %d %d", &n, &m, &start);
	for (int i = 0; i < m; i++) {
	        int u, v;
	        scanf("%d %d", &u, &v);
	        num[u].push_back(v);
	        num[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
	        sort(num[i].begin(), num[i].end());
	DFS(start);
	printf("\n");

	return 0;
}
~~~
