#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int>> nextNum;
int numSet[9] = { 1,2,3,4,5,6,7,8,9 };

//뽑는 순서를 고려한 조합 nCm = n! / (n-m)!
//모든 조합의 수 만들기
void makeNumSet() {
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
			for (int k = 0; k < 9; ++k)
				if (i != j && i != k && j != k) {
					vector<int> ns;
					ns.push_back(numSet[i]);
					ns.push_back(numSet[j]);
					ns.push_back(numSet[k]);
					nextNum.push_back(ns);
				}
}

//입력된 수의 조합과 매칭할 수 있는 수의 조합 추려내기
void checkPossible(int *in, int s, int b) {
	int size = nextNum.size();
	vector<vector<int>> check;

	for (int i = 0; i < size; ++i) {
		int cs = 0, cb = 0;
		//스트라이크 개수 세기
		for (int j = 0; j < 3; ++j)
			if (in[j] == nextNum[i][j])
				cs++;
		//볼 개수 세기
		for (int j = 0; j < 3; ++j)
			for (int k = 0; k < 3; ++k)
				if (j != k && in[j] == nextNum[i][k])
					cb++;
		//스크라이크 개수와 볼 개수가 같다면 생각할 수 있는 수의 조합이므로 추가한다.
		if (cs == s && cb == b)
			check.push_back(nextNum[i]);
	}
	//가능한 수의 조합 갱신하기
	nextNum = check;
}

int main()
{
	makeNumSet();
	/*printf("size: %d\n", nextNum.size());
	for (int i = 0; i < nextNum.size(); ++i)
		printf("%d%d%d ", nextNum[i][0], nextNum[i][1], nextNum[i][2]);*/
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int in[3], s, b;
		scanf("%1d", &in[0]);
		scanf("%1d", &in[1]);
		scanf("%1d", &in[2]);
		scanf("%d", &s);
		scanf("%d", &b);
		checkPossible(in, s, b);
	}
	printf("%d\n", (int)nextNum.size());

	return 0;
}
