#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

//16진수 한자리 문자를 10진수 정수형으로 변환하여 반환한다.
int hexToDec(char h) {
	switch (h) {
	case 'A': return 10;
	case 'B': return 11;
	case 'C': return 12;
	case 'D': return 13;
	case 'E': return 14;
	case 'F': return 15;
	default: return h - '0';
	}
}

//16진수 숫자 문자열을 10진수 정수형으로 변환하여 반환한다.
int changeDec(string hex) {
	int hsize = hex.size();
	int res = 0;
	int mult = hsize - 1;
	for (int i = 0; i < hsize; ++i) {
		int num = hexToDec(hex[i]);
		for (int j = 0; j < mult; ++j)
			num *= 16;
		mult--;
		res += num;
	}
	return res;
}

//내림차순
bool comp(const int a, const int b) {
	return a > b;
}

//회전하여 나타날 수 있는 모든 변의 숫자를 내림차순하여 k번째 숫자를 반환한다.
int solution(string number, int k) {
	int ans = 0;
	int size = number.size();
	//변은 총 4개이므로 현재 숫자 길이에서
	//회전할 수 있는 횟수를 계산한다.
	int numOfRot = size / 4;

	//각 변의 숫자 문자열을 저장하는 벡터
	vector<string> n;
	//현재 숫자 문자열
	string cur;
	cur = number;
	char tmp[30];
	for (int i = 0; i < numOfRot; ++i) {
		//각 변의 숫자만을 파싱하기 위해 사용할 인덱스(다음 파싱할 문자열의 시작 인덱스)
		int nIdx = 0;
		//총 4개의 변에서 나타날 수 있는 숫자 문자열을 만든다.
		for (int j = 0; j < 4; ++j) {
			int cnt = 0;
			for (int k = 0; k < numOfRot; ++k)
				tmp[cnt++] = cur[nIdx + k];
			nIdx += numOfRot;

			tmp[cnt] = '\0';
			//중복을 피하기 위해 사용될 스트링
			string check = tmp;
			bool flag = false;
			//중복이 있는지 검사
			for (int k = 0; k < n.size(); ++k)
				if (check == n[k]) {
					flag = true;
					break;
				}
			//중복이 없다면 벡터에 추가한다.
			if (!flag)
				n.push_back(check);
		}

		//회전
		//현재 문자열의 마지막 문자를 임시로 저장한다.
		char first = cur.at(size - 1);
		//회전이 끝난 문자열을 저장할 스트링
		string next;
		//현재 문자열의 마지막 문자를 회전 후의 문자열 첫번째 인덱스에 위치한다.
		next.push_back(first);
		//현재 문자열의 마지막 문자를 제외한 문자열을 순서대로 회전 후의 문자열에 삽입한다.
		for (int j = 0; j < size - 1; ++j)
			next.push_back(cur[j]);
		//현재 문자열을 갱신한다.
		cur = next;

		/*cout << cur << endl;
		for (int j = 0; j < n.size(); ++j)
			cout << n[j] << " ";
		printf("\n");*/
	}

	//문자열을 십진수 숫자로 변환 후 저장할 벡터
	vector<int> num;
	//문자열을 십진수 숫자로 변환
	for (int i = 0; i < n.size(); ++i)
		num.push_back(changeDec(n[i]));
	//내림차순 정렬
	sort(num.begin(), num.end(), comp);
	//k번째 숫자 저장
	ans = num[k - 1];

	return ans;
}

int main(void)
{
	int tc; scanf("%d", &tc);
	for (int t = 1; t <= tc; ++t) {
		int n, k; scanf("%d %d", &n, &k);
		string number;
		cin >> number;

		printf("#%d %d\n", t, solution(number, k));
	}

	return 0;
}
