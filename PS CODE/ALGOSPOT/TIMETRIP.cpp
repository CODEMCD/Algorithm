#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
using namespace std;
#define MAX_V 101
const int INF = 987654321;

//정점의 개수
int V, W;
//최단 경로 그래프의 인접 리스트, (연결된 정점 번호, 간선 가중치)쌍을 담는다.
vector<pair<int, int>> adjS[MAX_V];
//최장 경로 그래프의 인접 리스트, (연결된 정점 번호, -간선 가중치)쌍을 담는다.
vector<pair<int, int>> adjL[MAX_V];
//reachable[u][v] = u에서 v로 가는 경로가 있는가?
bool reachable[MAX_V][MAX_V];
//src에서 target으로 가는 최단 거리를 계산한다.
//가중치가 음의 무한대인 경로가 있으면 CYCLE를 반환한다.
//1(안드로메다은하)로 갈 수 없다면, target에는 INF값이 반환된다.
int BellmanFord(vector<pair<int,int>> *adj, int src, int target) {
	//시작점을 제외한 모든 정점까지의 거리 상한을 INF로 초기화한다.
	vector<int> upper(V, INF);
	upper[src] = 0;
	//V - 1번 순회한다.
	for (int iter = 0; iter < V - 1; ++iter)
		for (int here = 0; here < V; ++here) 
			for (int i = 0; i < adj[here].size(); ++i) {
				int there = adj[here][i].first;
				int cost = adj[here][i].second;
				//(here, there)간선을 따라 완화를 시도한다.
				upper[there] = min(upper[there], upper[here] + cost);
			}
	//음수 사이클의 존재 여부를 확인하자.
	//이는 0에서 1로 가는 경로중 음수 사이클이 없을 수도 있기 때문에
	//단순히 그래프에서 음수 사이클이 있는지 검사하는 것이 아닌 0에서 1경로 중에
	//음수 사이클이 있는지 검사해야 한다.
	for (int here = 0; here < V; ++here)
		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i].first;
			int cost = adj[here][i].second;
			//완화가 성공한다면 here와 there는 모두 음수 사이클에 들어 있다.
			if (upper[here] + cost < upper[there])
				//이 음수 사이클을 포함하는 경로가 있는가?
				if (reachable[src][here] && reachable[here][target])
					return -INF;
		}
	return upper[target];
}


//한 정점에서 다른 정점으로 가는 경로의 존재 여부 계산(플로이드 알고리즘)
void makeReach() {
	for (int k = 0; k < V; ++k)
		for (int i = 0; i < V; ++i)
			for (int j = 0; j < V; ++j)
				reachable[i][j] = reachable[i][j] || (reachable[i][k] && reachable[k][j]);
}

int main()
{
	int tc; scanf("%d", &tc);
	while (tc--) {
		memset(reachable, false, sizeof(reachable));
		for (int i = 0; i < MAX_V; ++i) {
			adjS[i].clear();
			adjL[i].clear();
		}

		scanf("%d %d", &V, &W);
		for (int i = 0; i < W; ++i) {
			int a, b, d; scanf("%d %d %d", &a, &b, &d);
			adjS[a].push_back(make_pair(b, d));
			adjL[a].push_back(make_pair(b, -d));
			reachable[a][b] = true;
		}

		//연결 상태 계산
		makeReach();
		//안드로메다 은하로 갈 수 없을 때
		if (!reachable[0][1]) {
			printf("UNREACHABLE\n");
			continue;
		}

		int lower, higher;
		lower = BellmanFord(adjS, 0, 1);
		higher = -BellmanFord(adjL, 0, 1);

		//음수사이클 및 양수사이클이 있을 때, 무한히 과거나 미래로 갈 수 있다.
		if ((lower == INF || lower == -INF) && (higher == INF || higher == -INF))
			printf("INFINITY INFINITY\n");
		else if ((lower == INF || lower == -INF) && (higher != INF && higher != -INF))
			printf("INFINITY %d\n", higher);
		else if ((lower != INF && lower != -INF) && (higher == INF || higher == -INF))
			printf("%d INFINITY\n", lower);
		else
			printf("%d %d\n", lower, higher);
	}

	return 0;
}
