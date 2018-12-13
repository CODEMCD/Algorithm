#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

//3번의 다트 정보가 주어졌을 때, 점수를 계산하여 반환한다.
int solution(string dartResult) {
	int answer = 0;
	//score[]: 각 다트 점수 계산
	int score[3], idx = 0;
	for (int i = 0; i < dartResult.size(); ++i) {
		//다트 점수가 10점인 경우
		if (dartResult.at(i) == '1' && dartResult.at(i + 1) == '0') {
			score[idx] = 10;
			i++;
		}
		//그 외 경우(한자리수)
		else
			score[idx] = dartResult.at(i) - 48;

		//Single, Double, Triple 점수 계산
		i++;
		if (dartResult.at(i) == 'D')
			score[idx] *= score[idx];
		else if (dartResult.at(i) == 'T')
			score[idx] *= (score[idx] * score[idx]);

		//스타상(*), 아차상(#) 점수 계산
		i++;
		if (i < dartResult.size() && dartResult.at(i) == '#')
			score[idx] *= -1;
		else if (i < dartResult.size() && dartResult.at(i) == '*') {
			if (idx == 0) score[idx] *= 2;
			else {
				score[idx - 1] *= 2;
				score[idx] *= 2;
			}
		}
		else
			i--;
		idx++;
	}

	//3개의 다트 점수를 모두 더한다.
	return answer = score[0] + score[1] + score[2];
}

int main(void)
{
	string info; cin >> info;
	int ans = solution(info);
	printf("%d\n", ans);

	return 0;
}