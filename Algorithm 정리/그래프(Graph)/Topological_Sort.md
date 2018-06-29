# 위상 정렬 (Topological Sort)

## 정의
- '수'를 정렬하는 것이 아니라 '그래프'를 정렬하는 알고리즘이다.
- 진입 차수(해당 노드로 들어오는 간선의 개수)의 비 내림차순 순서이다.
- 예를 들어, A -> B, C -> B 와 같은 형태의 그래프에서 A, C는 진입차수가 0, B는 진입차수가 2이다.

## 조건
- 위상정렬이 가능하려면, DAG 그래프이어야 한다.
- DAG(Directed Acyclic Graph)는 방향성이 있고, 사이클이 없는 그래프이다.
![dag](https://user-images.githubusercontent.com/34755287/38078117-3744f3ca-3376-11e8-966f-8bc2e618b105.jpg)

## 구현

- DFS를 이용한 구현
DFS의 탐색 결과를 역으로 나타낸 결과가 위상정렬이다.

- 진입차수(Indegree)를 이용한 구현
1) 큐 2개를 생성한다. (탐색 큐 : 탐색할 노드 저장, 결과 큐 : 정렬 결과를 저장)
2) 진입 차수가 0인 노드들을 탐색 후 탐색 큐에 저장한다.

![ts1](https://user-images.githubusercontent.com/34755287/38078341-eba862b6-3376-11e8-8705-b569b8e40b57.jpg)

3) 탐색 큐에서 꺼낸 노드들과 연결된 노드들의 진입차수를 -1로 업데이트 한다. (그래프 재구성)

![ts2](https://user-images.githubusercontent.com/34755287/38078343-ebd7817c-3376-11e8-95d2-4677d6413b8e.jpg)

4) 다시 진입차수가 0이 된 노드들을 탐색 큐에 삽입한다.

![ts3](https://user-images.githubusercontent.com/34755287/38078344-ec06ba28-3376-11e8-9de2-1d257c8e4acd.jpg)

5) 탐색 큐가 비어질 때까지 2) ~ 4) 과정을 반복한다.

![ts4](https://user-images.githubusercontent.com/34755287/38078345-ec32e756-3376-11e8-9f17-2d4f580c87d7.jpg)

- 그래프에서 진입차수가 0인 여러 개의 노드의 순서들을 사용자의 필요에 맞게 정렬해서 탐색 큐에 저장할 수 있다. (위의 그림은 알파벳순으로 정렬하였다.)
