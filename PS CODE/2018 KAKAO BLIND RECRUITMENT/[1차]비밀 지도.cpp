#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define N 20

//십진수를 이진수로 변환한다.
vector<int> changeBi(int arr, int n) {
	vector<int> binary(N);
	for (int i = n - 1; i >= 0; --i) {
		binary[i] = arr % 2;
		arr /= 2;
	}
	return binary;
}

//맵1과 맵2를 합쳐 전체 지도를 반환한다.
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;

	for (int i = 0; i < n; ++i) {
		//맵1 한 행을 저장할 벡터
		vector<int> bi1(N);
		//맵2 한 행을 저장할 벡터
		vector<int> bi2(N);
		char sum[20];
		//십진수를 이진수로 바꾼다.
		//0: 공백, 1: 벽
		bi1 = changeBi(arr1[i], n);
		bi2 = changeBi(arr2[i], n);
		//맵1,2 중 하나라도 벽이면, 전체 지도 벽
		//맵1,2 중 모두 공백이면, 전체지도 공백
		for (int j = 0; j < n; ++j) {
			if (!bi1[j] && !bi2[j])
				sum[j] = ' ';
			else
				sum[j] = '#';
		}
		sum[n] = '\0';
		string res;
		res = sum;
		//정답 배열에 삽입
		answer.push_back(res);
	}

	return answer;
}

int main(void)
{
	return 0;
}