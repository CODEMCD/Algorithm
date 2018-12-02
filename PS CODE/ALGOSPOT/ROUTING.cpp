#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define MAX_V 20001
//double 에서 사용할 수 있는 수 중 가장 큰 값으로 설정해주어야 한다.
const double DNF = 1.7E+308;

int n, m;
//그래프의 인접 리스트 (연결된 정점 번호, 간선 가중치) 쌍을 담는다.
vector<pair<int, double>> adj[MAX_V];
//다익스트라, 최단 거리 배열을 반환한다.
vector<double> dijkstra(int src) {
	vector<double> dist(n, DNF);
	//노이즈는 더하는 것이 아니라 곱해야 하기 때문에 가장 작을 값을 1로 둔다.
	dist[src] = 1.;
	//(해당 정점까지 최단 거리, 해당 정점)쌍
	priority_queue<pair<double, int>> pq;
	pq.push(make_pair(-1, src));
	while (!pq.empty()) {
		double cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		//만약 지금 꺼낸 것보다 더 짧은 경로를 알고 있다면 지금 꺼낸 것을 무시한다.
		if (dist[here] < cost) continue;
		//인접한 정점들을 모두 검사한다.
		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i].first;
			//노이즈를 계산해야 되기 때문에 곱하기 연산을 한다.
			double nextDist = cost * adj[here][i].second;
			//더 짧은 경로를 발견하면, dist[]를 갱신하고 우선순위 큐에 넣는다.
			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}
	return dist;
}

int main()
{
	int tc; scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; ++i) {
			int a, b; double c;
			scanf("%d %d %lf", &a, &b, &c);
			adj[a].push_back(make_pair(b, c));
			adj[b].push_back(make_pair(a, c));
		}
		vector<double> ret;
		ret = dijkstra(0);
		printf("%.10lf\n", ret[n - 1]);

		for (int i = 0; i < n; ++i)
			adj[i].clear();
	}

	return 0;
}
