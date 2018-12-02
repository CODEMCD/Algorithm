#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
#define max(a,b) ((a) > (b) ? (a) : (b))

vector<int> getPartialMatch(const string &N) {
	int m = N.size();
	vector<int> pi(m, 0);
	//KMP로 자기 자신을 찾는다.
	//N을 N에서 찾는다. begin = 0이면 자기 자신을 찾아버리니까 안됨!
	int begin = 1, matched = 0;
	//비교할 문자가 N의 끝에 도달할 때까지 찾으면서 부분 일치를 모두 기록한다.
	while (begin + matched < m) {
		if (N[begin + matched] == N[matched]) {
			++matched;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0)
				++begin;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}

int main()
{	
	string H, N;
	cin >> H >> N;
	vector<int> ret, pi;
	pi = getPartialMatch(H + N);
	int k = H.size() + N.size();
	while (k > 0) {
		//s[...k-1]는 답이다.
		ret.push_back(k);
		//접두사와 접미가가 같은 문자열의 최대길이가 p일때,
		//s[...p-1]에서의 접두사와 접미사가 같은 최대 길이를 구하면 되므로
		//pi[p-1]가 그 다음으로 긴 길이이다.(이미 계산되어 있기 때문)
		k = pi[k - 1];
	}
	for (int i = (int)ret.size() - 1; i >= 0; --i)
		printf("%d ", ret[i]);
	printf("\n");
	

	return 0;
}
