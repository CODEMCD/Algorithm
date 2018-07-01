# QUADTREE

## 문제 개요

![quadtree1](https://user-images.githubusercontent.com/34755287/42132460-4ecadcea-7d53-11e8-9236-4899fe29ef94.JPG)
![quadtree2](https://user-images.githubusercontent.com/34755287/42132461-4f18281a-7d53-11e8-92b3-a62565d783c5.JPG)

## 테스트 케이스

1) 기본 테스트 케이스
- 입력
```
4
w
xbwwb
xbwxwbbwb
xxwwwbxwxwbbbwwxxxwwbbbwwwwbb
```
- 출력
```
w
xwbbw
xxbwwbbbw
xxwbxwwxbbwwbwbxwbwwxwwwxbbwb
```

## 코드 분석
- 출처: 알고리즘 문제해결전략, 분할정복
- 재귀 호출을 이용해 네 부분을 각각 상하로 뒤집은 결과를 얻은 뒤, 이들을 병합한다.
- STL의 string 함수 사용
- STL의 문자열에서 지원하는 반복자(iterator) 활용
- 시간복잡도 분석: O(n)
  - 주어진 문자열 길이: n
  - 재귀 함수를 호출할 때 마다 주어진 문자열의 한 글자씩을 사용한다.

## 결과 코드
```
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string reserve(string::iterator &it)
{
	char head = *it;
	++it;
	if (head == 'b' || head == 'w')
		return string(1, head);
	string upperLeft = reserve(it);
	string upperRight = reserve(it);
	string lowerLeft = reserve(it);
	string lowerRight = reserve(it);

	//각각 위와 아래 조각들의 위치를 바꾼다.
	return string("x") + lowerLeft + lowerRight + 
		upperLeft + upperRight;
}

int main(void)
{
	int tc;
	scanf("%d", &tc);

	while (tc--) {
		string map;
		cin >> map;

		string::iterator it = map.begin();
		cout << reserve(it) << endl;
	}

	return 0;
}
```

## 결과 분석
- 수행시간: 4ms
