# WILDCARD

## 문제 개요

## 테스트 케이스
1. 기본 테스트 케이스
- 입력
```
2
he?p
3
help
heap
helpp
*p*
3
help
papa
hello
```
- 출력
```
heap
help
help
papa
```

2) '*' 주의해야할 테스트 케이스
- 입력
```
1
he*p
3
helpp
hepl
hepppp
```
- 출력
```
helpp
hepppp
```

## 코드 분석
- 완전 탐색: 4가지 경우
  - s[pos]와 w[pos]가 대응되지 않는다.: 대응 실패
  - w 끝에 도달했다.: 패턴에 *가 하나도 없는 경우, 패턴과 문자열의 길이가 정확히 같아야 대응 할 수 있다.
  - s 끝에 도달했다.: 패턴은 남아있지만 문자열은 끝난 경우, 남은 패턴이 모두 *면 대응 가능하지만 아니면 대응 실패이다.
  - __w[pos]가 *인 경우__: *가 몇 글자에 대응될지 모르기 때문에, 0 글자부터 남은 문자열의 길이까지를 순회하며 모든 가능성을 검사해야한다. 
  이때 w는 pos+1이후를 패턴 w'으로 하고, s의 pos + skip(현재 인덱스(pos) 이후 문자열 끝까지) 이후를 문자열 s'로 하여 match(w', s')로
  재귀 호출했을 때 답이 하나라도 참이면 대응 가능하다.

- DP

## 결과 코드
- 완전 탐색
```
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define N 1001
vector<string> res;

//와일드카드 패턴 w가 문자열 s에 대응되는지 여부를 반환한다.
bool match(const string &w, const string &s)
{
	//w[pos]와 s[pos]를 맞춰나간다.
	int pos = 0;
	while (pos < (int)s.size() && pos < (int)w.size() &&
		(w[pos] == '?' || w[pos] == s[pos]))
		++pos;
	//더이상 대응할 수 없으면 왜 while문이 끝났는지 확인한다.
	//2. 패턴 끝에 도달해서 끝난 경우: 문자열도 끝났어야 대응됨
	if (pos == w.size())
		return pos == s.size();
	//4. *를 만나서 끝난 경우: *에 몇 글자를 대응해야 할지 재귀 호출하면서 확인한다.
	if (w[pos] == '*')
		for (int skip = 0; pos + skip <= (int)s.size(); ++skip)
			//하나라도 대응되는 것이 있으면 TRUE 반환
			if (match(w.substr(pos + 1), s.substr(pos + skip)))
				return true;
	//이 외의 경우에는 모두 대응되지 않는다.
	return false;
}

int main(void)
{
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		string wild;
		cin >> wild;
		int n;
		scanf("%d", &n);
		while (n--) {
			string file;
			cin >> file;

			if (match(wild, file))
				res.push_back(file);
		}
		sort(res.begin(), res.end());
		for (int i = 0; i < (int)res.size(); i++)
			cout << res[i] << endl;
		res.clear();
	}

	return 0;
}
```
